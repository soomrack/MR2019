#include <iostream>
using namespace std;

const int t = 2;

static void swap (int *a, int *b) { int c = *a; *a = *b; *b = c; }

class BNode {
public:
    int keys[2*t-1]{};
    BNode *children[2*t+1]{};
    BNode *parent{};
    int keys_count;       //количество ключей
    int child_count{};    //количество сыновей
    bool leaf;
    explicit BNode(int key);
};

BNode::BNode(int key) {
    this->keys[0] = key;
    for (int i = 1; i < (2 * t - 1); i++)
        this->keys[i] = 0;
    for (auto & i : this->children)
        i = nullptr;
    this->keys_count = 1;
    this->leaf = true;
}

class BTree {
private:
    BNode *root;
    static void insert_in_node(int key, BNode *node);
    static void sort(BNode *node);
    static void split_node(BNode *node);
    static void delete_node(BNode *node);
    static bool search_key(int key, BNode *node);
           void remove_any(int key, BNode *node);
    static void remove_node(int key, BNode *node);
           void remove_leaf(int key, BNode *node);
    static void left_connect(BNode *node, BNode *neighbor);
    static void right_connect(BNode *node, BNode *neighbor);
           void repair(BNode *node);
public:
    BTree();
    ~BTree();
    void insert(int key);
    bool search(int key);
    void remove(int key);
};

BTree::BTree()  { root = nullptr; }

BTree::~BTree() { if (root != nullptr) delete_node(root); }

//Функция для деконструктора
void BTree::delete_node(BNode *node) {
    if (node != nullptr) {
        for (int i = 0; i <= (2*t-1); i++) {
            if (node->children[i] != nullptr)
                delete_node(node->children[i]);
            else {
                delete(node);
                break;
            }
        }
    }
}

//Простое добавление элемента в узел
void BTree::insert_in_node(int key, BNode *node) {
    node->keys[node->keys_count] = key;
    node->keys_count = node->keys_count + 1;
    sort(node);
}

//Сортировка в узле, чтобы элементы шли по порядку
void BTree::sort(BNode *node) {
    for (int i = 0; i < (2*t-1); i++){
        for (int j = i+1; j <= (2*t-1); j++){
            if ((node->keys[i] != 0) && (node->keys[j] != 0)) {
                if ((node->keys[i]) > (node->keys[j])){
                    swap(node->keys[i],node->keys[j]);
                }
            } else break;
        }
    }
}

//Добавление значения в узел с предварительным поиском позиции
void BTree::insert(int key) {
    if (root == nullptr) {
        auto *newRoot = new BNode(key);
        newRoot->keys[0] = key;
        for (int j = 1; j <= (2*t-1); j++) newRoot->keys[j] = 0;
        for (int i=0; i<=(2*t); i++)       newRoot->children[i] = nullptr;
        newRoot->keys_count = 1;
        newRoot->child_count = 0;
        newRoot->leaf = true;
        newRoot->parent = nullptr;
        root = newRoot;
    } else {
        BNode *ptr = root;
        while (!ptr->leaf) {                     //выбор ребенка до тех пор, пока узел не будет являться листом
            for (int i = 0; i <= (2*t-1); i++) { //перебираем все ключи
                if (ptr->keys[i] != 0) {
                    if (key < ptr->keys[i]) {
                        ptr = ptr->children[i];
                        break;
                    }
                    if ((ptr->keys[i+1] == 0)&&(key > ptr->keys[i])) {
                        ptr = ptr->children[i+1];
                        break;
                    }
                } else break;
            }
        }
        insert_in_node(key, ptr);
        while (ptr->keys_count == 2 * t) {
            if (ptr == root) {
                split_node(ptr);
                break;
            } else {
                split_node(ptr);
                ptr = ptr->parent;
            }
        }
    }
}

//Разбиение узла на родителя и двух сыновей
void BTree::split_node(BNode *node) {
    if (node->keys_count < (2 * t - 1)) return;
    //первый сын
    auto *child1 = new BNode(0);
    for (int j = 0; j <= t-2; j++)       child1->keys[j] = node->keys[j];
    for (int j = t-1; j <= (2*t-1); j++) child1->keys[j] = 0;
    child1->keys_count = t - 1;     //количество ключей в узле
    if(node->child_count != 0) {
        for (int i=0; i <= (t-1); i++){
            child1->children[i] = node->children[i];
            child1->children[i]->parent = child1;
        }
        for (int i=t; i<=(2*t); i++)
            child1->children[i] = nullptr;
        child1->leaf = false;
        child1->child_count = t - 1; //количество сыновей
    } else {
        child1->leaf = true;
        child1->child_count = 0;
        for (int i = 0; i <= (2*t); i++)
            child1->children[i] = nullptr;
    }
    //второй сын
    auto *child2 = new BNode(0);
    for (int j = 0; j <= (t-1); j++) child2->keys[j] = node->keys[j+t];
    for (int j = t; j <= (2*t-1); j++) child2->keys[j] = 0;
    child2->keys_count = t;
    if(node->child_count != 0) {
        for (int i = 0; i <= (t); i++){
            child2->children[i] = node->children[i+t];
            child2->children[i]->parent = child2;
        }
        for (int i = t+1; i <= (2*t); i++) child2->children[i] = nullptr;
        child2->leaf = false;
        child2->child_count = t;
    } else {
        child2->leaf = true;
        child2->child_count = 0;
        for (int i = 0; i <= (2*t); i++) child2->children[i] = nullptr;
    }
    //родитель
    if (node->parent == nullptr) { //если родителя нет, то это корень
        node->keys[0] = node->keys[t-1];
        for (int j = 1; j <= (2*t-1); j++)
            node->keys[j] = 0;
        node->children[0] = child1;
        node->children[1] = child2;
        for (int i=2; i<=(2*t); i++)
            node->children[i] = nullptr;
        node->parent = nullptr;
        node->leaf = false;
        node->keys_count = 1;
        node->child_count = 2;
        child1->parent = node;
        child2->parent = node;
    } else {
        insert_in_node(node->keys[t - 1], node->parent);
        for (int i = 0; i <= (2*t); i++){
            if (node->parent->children[i] == node)
                node->parent->children[i] = nullptr;
        }
        for (int i = 0; i <= (2*t); i++){
            if (node->parent->children[i] == nullptr) {
                for (int k = (2*t); k > (i+1); k--)
                    node->parent->children[k] = node->parent->children[k-1];
                node->parent->children[i+1] = child2;
                node->parent->children[i] = child1;
                break;
            }
        }
        child1->parent = node->parent;
        child2->parent = node->parent;
        node->parent->leaf = false;
        delete node;
    }
}

//Поиск по ключу
bool BTree::search(int key) {
    return search_key(key, this->root);
}

bool BTree::search_key(int key, BNode *node) {
    int i;
    if (node != nullptr){
        if (!node->leaf){
            for (i = 0; i <= (2*t-1); i++) {
                if (node->keys[i]!=0) {
                    if(key == node->keys[i])
                        return true;
                    if (key < node->keys[i])
                        return search_key(key, node->children[i]);
                } else break;
            }
            return search_key(key, node->children[i]);
        } else {
            for (int j = 0; j <= (2*t-1); j++)
                if (key == node->keys[j])
                    return true;
            return false;
        }
    } else return false;
}

//Удаление ключа из узла
void BTree::remove_node(int key, BNode *node) {
    for (int i = 0; i < node->keys_count; i++) {
        if (node->keys[i] == key) {
            for (int j = i; j < node->keys_count; j++) {
                node->keys[j] = node->keys[j+1];
                node->children[j] = node->children[j+1];
            }
            node->keys[node->keys_count - 1] = 0;
            node->children[node->keys_count - 1] = node->children[node->keys_count];
            node->children[node->keys_count] = nullptr;
            break;
        }
    }
    node->keys_count--;
}

//Соединение соседних узлов после удаления
void BTree::left_connect(BNode *node, BNode *neighbor) {
    if (node == nullptr)
        return;
    for (int i = 0; i <= (neighbor->keys_count - 1); i++) {
        node->keys[node->keys_count] = neighbor->keys[i];
        node->children[node->keys_count] = neighbor->children[i];
        node->keys_count = node->keys_count + 1;
    }
    node->children[node->keys_count] = neighbor->children[neighbor->keys_count];
    for (int j = 0; j <= node->keys_count; j++){
        if (node->children[j] == nullptr) break;
        node->children[j]->parent = node;
    }
    delete neighbor;
}

void BTree::right_connect(BNode *node, BNode *neighbor) {
    if (node == nullptr)
        return;
    for (int i = 0; i <= (neighbor->keys_count - 1); i++) {
        node->keys[node->keys_count] = neighbor->keys[i];
        node->children[node->keys_count + 1] = neighbor->children[i + 1];
        node->keys_count = node->keys_count + 1;
    }
    for (int j = 0; j <= node->keys_count; j++) {
        if (node->children[j] == nullptr) break;
        node->children[j]->parent = node;
    }
    delete neighbor;
}

//Перестраеваем дерево, пока все условия B-дерева не будут выполнены
void BTree::repair(BNode *node) {
    if ((node == root) && (node->keys_count == 0)) {
        if (root->children[0] != nullptr) {
            root->children[0]->parent = nullptr;
            root = root->children[0];
        } else {
            delete root;
        }
        return;
    }
    BNode *ptr=node;
    int child_position = 0;
    BNode *parent = ptr->parent;
    for (int j = 0; j <= parent->keys_count; j++) {
        if (parent->children[j] == ptr) {
            child_position = j; //позиция узла по отношению к родителю
            break;
        }
    }
    //если ptr-первый ребенок (самый левый)
    if (child_position == 0){
        insert_in_node(parent->keys[child_position], ptr);
        left_connect(ptr, parent->children[child_position + 1]);
        parent->children[child_position + 1] = ptr;
        parent->children[child_position] = nullptr;
        remove_node(parent->keys[child_position], parent);
        if(ptr->keys_count == 2 * t){
            while (ptr->keys_count == 2 * t) {
                if (ptr == root){
                    split_node(ptr);
                    break;
                } else {
                    split_node(ptr);
                    ptr = ptr->parent;
                }
            }
        } else
        if (parent->keys_count <= (t - 2))
            repair(parent);
    } else {
        //если ptr-последний ребенок (самый правый)
        if (child_position == parent->keys_count) {
            insert_in_node(parent->keys[child_position - 1], parent->children[child_position - 1]);
            right_connect(parent->children[child_position - 1], ptr);
            parent->children[child_position] = parent->children[child_position - 1];
            parent->children[child_position - 1] = nullptr;
            remove_node(parent->keys[child_position - 1], parent);
            BNode *temp = parent->children[child_position];
            if(ptr->keys_count == 2 * t){
                while (temp->keys_count == 2 * t){
                    if (temp == root){
                        split_node(temp);
                        break;
                    } else {
                        split_node(temp);
                        temp = temp->parent;
                    }
                }
            } else
            if (parent->keys_count <= (t - 2))
                repair(parent);
        //если ptr имеет братьев справа и слева
        } else {
            insert_in_node(parent->keys[child_position], ptr);
            left_connect(ptr, parent->children[child_position + 1]);
            parent->children[child_position + 1] = ptr;
            parent->children[child_position] = nullptr;
            remove_node(parent->keys[child_position], parent);
            if(ptr->keys_count == 2 * t){
                while (ptr->keys_count == 2 * t){
                    if (ptr == root){
                        split_node(ptr);
                        break;
                    } else {
                        split_node(ptr);
                        ptr = ptr->parent;
                    }
                }
            } else
            if (parent->keys_count <= (t - 2))
                repair(parent);
        }
    }
}

//Удаление ключа из листа
void BTree::remove_leaf(int key, BNode *node) {
    if ((node == root) && (node->keys_count == 1)) {
        remove_node(key, node);
        root->children[0] = nullptr;
        delete root;
        root = nullptr;
        return;
    }
    if (node == root) {
        remove_node(key, node);
        return;
    }
    if (node->keys_count > (t - 1)) {
        remove_node(key, node);
        return;
    }
    BNode *ptr=node;
    int k1;
    int k2;
    int position;
    int child_position = 0;
    int i;
    for (i = 0; i <= node->keys_count - 1; i++) {
        if (key == node->keys[i]) {
            position = i;      //позиция ключа в узле
            break;
        }
    }
    BNode *parent = ptr->parent;
    for (int j = 0; j <= parent->keys_count; j++) {
        if (parent->children[j] == ptr) {
            child_position = j; //позиция узла по отношению к родителю
            break;
        }
    }
    //если ptr-первый ребенок (самый левый)
    if (child_position == 0) {
        if (parent->children[child_position + 1]->keys_count > (t - 1)) { //если у правого брата больше, чем t-1 ключей
            k1 = parent->children[child_position + 1]->keys[0];           //k1 - минимальный ключ правого брата
            k2 = parent->keys[child_position];                            //k2 - ключ родителя, больше, чем удаляемый, и меньше, чем k1
            insert_in_node(k2, ptr);
            remove_node(key, ptr);
            parent->keys[child_position] = k1;                           //меняем местами k1 и k2
            remove_node(k1, parent->children[child_position + 1]); //удаляем k1 из правого брата
        } else {                                                         //если у правого единственного брата не больше t-1 ключей
            remove_node(key, ptr);
            if (ptr->keys_count <= (t - 2))
                repair(ptr);
        }
    //если ptr-последний ребенок (самый правый)
    } else {
        if (child_position == parent->keys_count) {
            if (parent->children[child_position - 1]->keys_count > (t - 1)) {
                BNode *temp = parent->children[child_position - 1];
                k1 = temp->keys[temp->keys_count - 1]; //k1 - максимальный ключ левого брата
                k2 = parent->keys[child_position - 1]; //k2 - ключ родителя, меньше, чем удаляемый и больше, чем k1
                insert_in_node(k2, ptr);
                remove_node(key, ptr);
                parent->keys[child_position - 1] = k1;
                remove_node(k1, temp);
            } else {                                   //если у единственного левого брата не больше t-1 ключей
                remove_node(key, ptr);
                if (ptr->keys_count <= (t - 2))
                    repair(ptr);
            }
        //если ptr имеет братьев справа и слева
        } else {
            //если у правого брата больше, чем t-1 ключей
            if (parent->children[child_position + 1]->keys_count > (t - 1)) {
                k1 = parent->children[child_position + 1]->keys[0]; //k1 - минимальный ключ правого брата
                k2 = parent->keys[child_position];                  //k2 - ключ родителя, больше, чем удаляемый и меньше, чем k1
                insert_in_node(k2, ptr);
                remove_node(key, ptr);
                parent->keys[child_position] = k1;                           //меняем местами k1 и k2
                remove_node(k1, parent->children[child_position + 1]); //удаляем k1 из правого брата
            } else {                                                         //если у левого брата больше, чем t-1 ключей
                if (parent->children[child_position - 1]->keys_count > (t - 1)) {
                    BNode *temp = parent->children[child_position - 1];
                    k1 = temp->keys[temp->keys_count - 1]; //k1 - максимальный ключ левого брата
                    k2 = parent->keys[child_position - 1]; //k2 - ключ родителя, меньше, чем удаляемый и больше, чем k1
                    insert_in_node(k2, ptr);
                    remove_node(key, ptr);
                    parent->keys[child_position - 1] = k1;
                    remove_node(k1, temp);
                } else {                                   //если у обоих братьев не больше t-1 ключей
                    remove_node(key, ptr);
                    if (ptr->keys_count <= (t - 2))
                        repair(ptr);
                }
            }
        }
    }
}

//Удаление из произвольного узла
void BTree::remove_any(int key, BNode *node) {
    BNode *ptr = node;
    int position = 0; //номер ключа
    for (int i = 0; i <= node->keys_count - 1; i++) {
        if (key == node->keys[i]) {
            position = i;
            break;
        }
    }
    int child_position; //номер сына по отношению к родителю
    if (ptr->parent != nullptr) {
        for(int i = 0; i <= ptr->parent->keys_count; i++) {
            if (ptr->children[i] == ptr) {
                child_position = i;
                break;
            }
        }
    }
    //находим наименьший ключ правого поддерева
    ptr = ptr->children[position+1];
    int newkey = ptr->keys[0];
    while (!ptr->leaf)
        ptr = ptr->children[0];
    //если ключей в найденном листе не больше 1 - ищем наибольший ключ в левом поддереве
    //иначе - просто заменяем key на новый ключ, удаляем новый ключ из листа
    if (ptr->keys_count > (t - 1)) {
        newkey = ptr->keys[0];
        remove_node(newkey, ptr);
        node->keys[position] = newkey;
    } else {
        ptr = node;
        //ищем наибольший ключ в левом поддереве
        ptr = ptr->children[position];
        newkey = ptr->keys[ptr->keys_count - 1];
        while (!ptr->leaf)
            ptr = ptr->children[ptr->keys_count];
        newkey = ptr->keys[ptr->keys_count - 1];
        node->keys[position] = newkey;
        //если ключей не больше, чем t-1 - перестраиваем
        if (ptr->keys_count > (t - 1))
            remove_node(newkey, ptr);
        else {
            remove_leaf(newkey, ptr);
        }
    }
}

//Сам метод удаления по ключу
void BTree::remove(int key) {
    BNode *ptr = this->root;
    int position;
    int positionSon;
    if (!search_key(key, ptr)) {
        return;
    } else {
        //ищем узел, в котором находится ключ для удаления
        for (int i = 0; i <= ptr->keys_count - 1; i++) {
            if (ptr->keys[i] != 0) {
                if(key == ptr->keys[i]) {
                    position = i;
                    break;
                } else {
                    if ((key < ptr->keys[i])) {
                        ptr = ptr->children[i];
                        positionSon = i;
                        i = -1;
                    } else {
                        if (i == (ptr->keys_count - 1)) {
                            ptr = ptr->children[i+1];
                            positionSon = i+1;
                            i = -1;
                        }
                    }
                }
            } else break;
        }
    }
    if (ptr->leaf) {
        if (ptr->keys_count > (t - 1))
            remove_node(key, ptr);
        else remove_leaf(key, ptr);
    } else remove_any(key, ptr);
}

int main() {
    BTree tree = BTree();

    tree.insert(5);
    tree.insert(9);
    tree.remove(12);
    tree.search(5);

    return 0;
}