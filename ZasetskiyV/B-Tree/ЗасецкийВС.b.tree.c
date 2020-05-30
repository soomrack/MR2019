#include <iostream>
const int t = 3;
class Node
{
public:
    int key[2*t-1]; //массив ключей
    Node * child_node_pointer[2*t]; //массив указателей на узлы-потомки
    int number_of_keys; //кол-во ключей
    bool is_leaf; //является ли листом
public:
    Node(bool is_leaf)
    {
        this->is_leaf = is_leaf;
        this->number_of_keys = 0;
    }
    ~Node(){}

    void print_node(); //вспомогательный метод для вывода дерева
    void remove_key(int); //удалить ключ из узла
    void remove_node_pointer(int); //удалить потомка по индексу
    void push_key(int); //добавить ключ в узел
    int find_key_index(int);
    void print(); //посмотреть содержимое узла
};

class Tree
{
public:
    Node * root;
public:
    Tree()
    {
        this->root = nullptr;
    }
    ~Tree(){}

    Node * search(Node *, int); //найти узел с искомым ключом
    int insert(int); //метод вставки
    void print_tree(); //метод вывода ключей дерева в отсортированном виде
    int delete_data(int); //метод удаления ключа

private:
    Node * find_parent(Node *, Node *, int); //функция поиска узла-родителя ключа
    int split_child(Node *, int, Node *); //разбить заполненного ребёнка на двух
    int insert_to_nonfull_node(Node *, int); //вставить ключ в неполный узел
    int begin_deletion(Node *, Node *, int); //вспомогательная функция удаления
    ////методы для удаления ключа из листа:
    void borrow_left_neighbour(Node *, int, int);
    void borrow_right_neighbour(Node *, int, int);
    void merge_delete(Node *, int, int, int);
    //методы для удаления ключа из внутреннего узла:
    int borrow_left_child(Node *, int);
    int borrow_right_child(Node *, int);
    void merge_delete_child(Node *, int, int, int);
};



int Tree::split_child(Node * parent, int index_of_old_node, Node * old_node)
{
    //СОЗДАЁМ НОВЫЙ УЗЕЛ, КУДА ПЕРЕНЕСЁМ ПОЛОВИНУ СТАРОГО
    Node * new_node = new Node(old_node->is_leaf);
    new_node->number_of_keys = t - 1;
    //копируем правую половину (t-1) ключей в новый узел
    for (int j = 0; j != (t-1); j++)
    {
        new_node->key[j] = old_node->key[j + t];
    }
    //копируем правую половину (t) потомков в новый узел
    if (old_node->is_leaf == false)
    {
        for (int j = 0; j != t; j++)
        {
            new_node->child_node_pointer[j] = old_node->child_node_pointer[j + t];
        }
    }
    old_node->number_of_keys = t - 1;
    //ВЫДЕЛИМ МЕСТО В МАССИВЕ ПОТОМКОВ РОДИТЕЛЯ ДЛЯ НОВОГО ПОТОМКА (ИНДЕКС ПОСЛЕДНЕГО ПОТОМКА СОВПАДАЕТ С КОЛИЧЕСТВОМ КЛЮЧЕЙ)
    for (int j = parent->number_of_keys; j != index_of_old_node; j--)
    {
        parent->child_node_pointer[j + 1] = parent->child_node_pointer[j];
    } //таким образом, (index_of_old_node + 1)-й элемент остался свободным
    //помещаем новый узел на это место
    parent->child_node_pointer[index_of_old_node + 1] = new_node;
    //ОСВОБОДИМ index_of_old_node-ТОЕ МЕСТО В МАССИВЕ КЛЮЧЕЙ РОДИТЕЛЯ ДЛЯ СЕРЕДИННОГО КЛЮЧА РАЗБИВАЕМОГО УЗЛА И ПОМЕСТИМ ЕГО ТУДА
    for (int j = parent->number_of_keys - 1; j >= index_of_old_node; j--)
    {
        parent->key[j + 1] = parent->key[j];
    }
    //помещаем серединный (t - тый) ключ в массив ключей родителя
    parent->key[index_of_old_node] = old_node->key[t - 1];
    parent->number_of_keys ++;
    return 0;
}

//(вспомогательный) Метод для вставки ключа в незаполненный узел
int Tree::insert_to_nonfull_node(Node * node_to_insert, int key)
{
    int index_of_insertion = node_to_insert->number_of_keys - 1;
    //ЕСЛИ УЗЕЛ ЯВЛЯЕТСЯ ЛИСТОМ
    if (node_to_insert->is_leaf)
    //ищем индекс для вставки ключа key
    {
        while ((node_to_insert->key[index_of_insertion] > key) && (index_of_insertion != -1))
        {
            //сдвигаем элемент на 1 вправо
            node_to_insert->key[index_of_insertion + 1] = node_to_insert->key[index_of_insertion];
            index_of_insertion--;
        }//таким образом, мы освободили (index_of_insertion + 1)-тое место для key
        //помещаем key на это место
        node_to_insert->key[index_of_insertion + 1] = key;
        node_to_insert->number_of_keys ++;
    }
    //ЕСЛИ УЗЕЛ НЕ ЯВЛЯЕТСЯ ЛИСТОМ
    else
    {
        //ИЩЕМ ИНДЕКС ПОТОМКА ДЛЯ ВСТАВКИ КЛЮЧА
        while ((node_to_insert->key[index_of_insertion] > key) && (index_of_insertion != -1))
        {
            index_of_insertion--;
        }
          //для индексации потомка используется index_of_insertion + 1
          index_of_insertion++;
        //ПРОВЕРИМ ЗАПОЛНЕННОСТЬ ПОТОМКА
        //если потомок заполнен
        if (node_to_insert->child_node_pointer[index_of_insertion]->number_of_keys == 2 * t - 1)
        {
            //разделяем потомка
            this->split_child(node_to_insert, index_of_insertion, node_to_insert->child_node_pointer[index_of_insertion]);
            //выбираем, в какого потомка добавлять ключ
            if (key > node_to_insert->key[index_of_insertion])
                index_of_insertion++;
            //добавляем ключ в потомка
            this->insert_to_nonfull_node(node_to_insert->child_node_pointer[index_of_insertion], key);
        }
        //если потомок не заполнен, вставляем в него ключ
        else
        {
            this->insert_to_nonfull_node(node_to_insert->child_node_pointer[index_of_insertion], key);
        }
    }
    return  0;
}

void Node::print_node()
{
    int j;
    for (j = 0; j != this->number_of_keys; j++)
    {
        if (this->is_leaf == false)
            this->child_node_pointer[j]->print_node();
        std::cout << this->key[j] << "  ";
    }
    //печатаем последнего потомка (ключи больше ключей родителя)
    if (this->is_leaf == false)
        this->child_node_pointer[this->number_of_keys]->print_node();
}

//Метод ищет ключ и возвращает указатель на узел с ключом в случае успешного поиска, нулевой указатель в остальных случаях
Node * Tree::search(Node * node, int key)
{
    //найдём индекс первого ключа, большего или равного key
    int first_greater_or_equal_key_index = 0;
    while ((first_greater_or_equal_key_index < node->number_of_keys) && (key > node->key[first_greater_or_equal_key_index]))
        first_greater_or_equal_key_index++;

    //если ключ найден, возвращаем указатель на его узел
    if (node->key[first_greater_or_equal_key_index] == key)
        return node;

    //если узел является листом
    if (node->is_leaf)
        return nullptr;

    //в остальных случаях производим поиск в левом потомке от первого большего key ключа
    //(или в правом от последнего меньшего, что то же самое)
    return search(node->child_node_pointer[first_greater_or_equal_key_index], key);
}

//Метод добавляет новый ключ в дерево
int Tree::insert(int key)
{
    //если корня нет, создаём его
    if (this->root == nullptr)
    {
        this->root = new Node(true);
        this->root->key[0] = key;
        this->root->number_of_keys = 1;
    }
    else
    {
        //если корень заполнен, создаём новый корень, а старый делим на два потомка
        if (this->root->number_of_keys == 2 * t - 1)
        {
            Node * new_root = new Node(false);
            new_root->child_node_pointer[0] = this->root;
            this->split_child(new_root, 0, this->root);
            //вставляем ключ в одного из двух потомков нового корня
            int index_of_child_to_insert = 0;
            //сравниваем ключ со средним элементом массива ключей бывшего корня
            if (key > new_root->key[0])
                index_of_child_to_insert++;
            this->insert_to_nonfull_node(new_root->child_node_pointer[index_of_child_to_insert], key);
            this->root = new_root;
        }
        //если корень не заполнен, вызываем для него функцию вставки ключа в неполный узел
        else
        {
            this->insert_to_nonfull_node(this->root, key);
        }
    }
    return 0;
}

void Tree::print_tree()
{
    if (this->root != nullptr)
        root->print_node();
    else
        std::cout << "Tree is empty\n";
}

void Node::print()
{
    std::cout << "Node: ";
    for (int j = 0; j != this->number_of_keys; j++)
    {
        std::cout << this->key[j] << "  ";
    }
}

//вспомогательная функция поиска родителя
Node * Tree::find_parent(Node * node_parent, Node * node, int key)
{
    //найдём индекс первого ключа, большего или равного key
    int first_greater_or_equal_key_index = 0;
    while ((first_greater_or_equal_key_index < node->number_of_keys) && (key > node->key[first_greater_or_equal_key_index]))
        first_greater_or_equal_key_index++;

    //если ключ найден, возвращаем указатель на узел его родителя
    if (node->key[first_greater_or_equal_key_index] == key)
        return node_parent;

    //в остальных случаях производим поиск в левом потомке от первого большего key ключа
    return find_parent(node, node->child_node_pointer[first_greater_or_equal_key_index], key);
}

void Node::remove_node_pointer(int index_remove)
{
    //удаляем узел
    delete this->child_node_pointer[index_remove];
    //смещаем указатели влево, заполняя освободившееся место
    for (int j = index_remove; j != this->number_of_keys; j++)
    {
        this->child_node_pointer[j] = this->child_node_pointer[j + 1];
    }
}

void Node::push_key(int key)
{
    //вычисляем позицию для вставляемого ключа
    int push_index;
    for (push_index = 0; push_index != this->number_of_keys; push_index++)
    {
        if (key < this->key[push_index])
            break;
    }
    //смещаем ключи вправо от позиции вставки
    for (int j = this->number_of_keys; j != push_index; j--)
    {
        this->key[j] = this->key[j - 1];
    }
    //вставляем ключ
    this->key[push_index] = key;
    this->number_of_keys ++;
}

int Node::find_key_index(int key)
{
    int index;
    for (index = 0; index != this->number_of_keys; index++)
    {
        if (this->key[index] == key)
        {
            return index;
        }
    }
    return -1;
}

void Node::remove_key(int key_delete)
{
    int index_remove = this->find_key_index(key_delete);
    for (int j = index_remove; j != this->number_of_keys - 1; j++)
    {
        //смещаем ключи влево, заполняя освободившееся место
        this->key[j] = this->key[j + 1];
    }
    this->number_of_keys --;
}

void Tree::borrow_left_neighbour(Node * node_parent, int key_delete, int neighbour_index)
{
    //удаляем ключ
    node_parent->child_node_pointer[neighbour_index + 1]->remove_key(key_delete);
    //в узле с удаляемым ключом ставим ключ родителя на первое место
    node_parent->child_node_pointer[neighbour_index + 1]->push_key(node_parent->key[neighbour_index]);
    //переносим последний ключ левого соседа на место ключа родителя
    int last_key_index = node_parent->child_node_pointer[neighbour_index]->number_of_keys - 1;
    node_parent->key[neighbour_index] = node_parent->child_node_pointer[neighbour_index]->key[last_key_index];
    node_parent->child_node_pointer[neighbour_index]->number_of_keys --;
}

void Tree::borrow_right_neighbour(Node * node_parent, int key_delete, int neighbour_index)
{
    //удаляем ключ
    node_parent->child_node_pointer[neighbour_index - 1]->remove_key(key_delete);
    //в узле с удаляемым ключом ставим ключ родителя на последнее место
    node_parent->child_node_pointer[neighbour_index - 1]->push_key(node_parent->key[neighbour_index - 1]);
    //переносим первый ключ соседа на место ключа родителя
    int key_neighbour = node_parent->child_node_pointer[neighbour_index]->key[0];
    node_parent->key[neighbour_index - 1] = key_neighbour;
    //удаляем первый ключ соседа
    node_parent->child_node_pointer[neighbour_index]->remove_key(key_neighbour);
}

void Tree::merge_delete(Node * node_parent, int key_delete, int left_index, int right_index)
{
    //переносим ключи из правого потомка в левого
    for (int j = 0; j != t - 1; j++)
    {
        node_parent->child_node_pointer[left_index]->number_of_keys = 2 * (t - 1);
        node_parent->child_node_pointer[left_index]->key[t - 1 + j] = node_parent->child_node_pointer[right_index]->key[j];
    }
    //удаляем ключ из объединённого потомка
    node_parent->child_node_pointer[left_index]->remove_key(key_delete);
    //добавляем ключ родителя
    int key_parent = node_parent->key[left_index];
    node_parent->child_node_pointer[left_index]->push_key(key_parent);
    //удаляем указатель на правого потомка из массива указателей родительского узла
    node_parent->remove_node_pointer(right_index);
    //удаляем ключ родителя из массива ключей родительского узла
    node_parent->remove_key(key_parent);
}

int Tree::borrow_left_child(Node * node_delete_from, int del_index)
{
    //ставим последний ключ левого ребёнка на место удаляемого ключа
    int child_last_index = node_delete_from->child_node_pointer[del_index]->number_of_keys - 1;
    int key_replace = node_delete_from->child_node_pointer[del_index]->key[child_last_index];
    node_delete_from->key[del_index] = key_replace;
    return key_replace;
}

int Tree::borrow_right_child(Node * node_delete_from, int del_index)
{
    //ставим первый ключ правого ребёнка на место удаляемого ключа
    int key_replace = node_delete_from->child_node_pointer[del_index + 1]->key[0];
    node_delete_from->key[del_index] = key_replace;
    return key_replace;
}

void Tree::merge_delete_child(Node * node_delete_from, int key_delete, int left_index, int right_index)
{
    //переносим ключи из правого потомка в левого
    for (int j = 0; j != t - 1; j++)
    {
        node_delete_from->child_node_pointer[left_index]->number_of_keys = 2 * (t - 1);
        node_delete_from->child_node_pointer[left_index]->key[t - 1 + j] = node_delete_from->child_node_pointer[right_index]->key[j];
    }
    //переносим удаляемый ключ в левого ребёнка
    node_delete_from->child_node_pointer[left_index]->push_key(key_delete);
    //удаляем указатель на правого потомка из массива указателей родительского узла
    node_delete_from->remove_node_pointer(right_index);
    //удаляем ключ из родительского узла
    node_delete_from->remove_key(key_delete);
}

int Tree::begin_deletion(Node * node_delete_from, Node * node_parent, int key_delete)
{
    if (node_delete_from->is_leaf)
    {
        //если в узле достаточно ключей, удаляем ключ
        if (node_delete_from->number_of_keys > t - 1)
        {
            node_delete_from->remove_key(key_delete);
            return 0;
        }

        if (node_parent == nullptr)
            node_parent = this->find_parent(nullptr, this->root, key_delete);

        //находим индекс листа с удаляемым ключом в массиве указателей на детей
        int leaf_index;
        for (leaf_index = 0; leaf_index != node_parent->number_of_keys; leaf_index++)
        {
            if (node_parent->key[leaf_index] > key_delete)
                break;
        }

        //если сосед слева больше t-1
        if (leaf_index != 0 && node_parent->child_node_pointer[leaf_index-1]->number_of_keys > t - 1)
        {
            this->borrow_left_neighbour(node_parent, key_delete, leaf_index - 1);
        }
            //если сосед справа больше t-1
        else if (leaf_index != node_parent->number_of_keys &&
                 node_parent->child_node_pointer[leaf_index+1]->number_of_keys > t - 1)
        {
            this->borrow_right_neighbour(node_parent, key_delete, leaf_index + 1);
        }
            //если оба соседа размером t-1
        else
        {
            //если лист с удаляемым ключом самый левый
            if (leaf_index == 0)
            {
                this->merge_delete(node_parent, key_delete, leaf_index, leaf_index + 1);
                return 0;
            }
            //в остальных случаях
            this->merge_delete(node_parent, key_delete, leaf_index - 1, leaf_index);
        }
        return 0;
    }

    //если узел с удаляемым ключом не является листом
    //индекс удаляемого ключа:
    int del_index = node_delete_from->find_key_index(key_delete);
    //если у ребёнка слева больше (t-1) ключей
    if (node_delete_from->child_node_pointer[del_index]->number_of_keys > t - 1)
    {
        //ставим последний ключ левого ребёнка на место удаляемого ключа
        int key_replace = this->borrow_left_child(node_delete_from, del_index);
        //запускаем удаление перенесённого ключа из узла ребёнка
        this->begin_deletion(node_delete_from->child_node_pointer[del_index], node_delete_from, key_replace);
    }
    //если у ребёнка справа больше (t-1) ключей
    else if (node_delete_from->child_node_pointer[del_index + 1]->number_of_keys > t - 1)
    {
        //ставим первый ключ правого ребёнка на место удаляемого ключа
        int key_replace = this->borrow_right_child(node_delete_from, del_index);
        //запускаем удаление перенесённого ключа из узла ребёнка
        this->begin_deletion(node_delete_from->child_node_pointer[del_index + 1], node_delete_from, key_replace);
    }
    //если оба ребёнка имеют по (t-1) ключей
    else
    {
        //объединяем детей, удаляем ключ из родителя, переносим его в ребёнка
        this->merge_delete_child(node_delete_from, key_delete, del_index, del_index + 1);
        //запускаем удаление ключа из ребёнка (левого)
        this->begin_deletion(node_delete_from->child_node_pointer[del_index], node_delete_from, key_delete);
    }
    return 0;
}

int Tree::delete_data(int key_delete)
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty\n";
        return 1;
    }
    Node * node_delete_from = this->search(this->root, key_delete);
    if (node_delete_from == nullptr)
    {
        std::cout << "The data is missing\n";
        return 2;
    }

    return this->begin_deletion(node_delete_from, nullptr, key_delete);
}



int main()
{
    Tree tree = Tree();

    for (int k = 0; k != 30; k++)
    {
        tree.insert(k);
    }

    tree.print_tree();
    std::cout << "\n";

    //вывод внешнего вида дерева:
    tree.root->print();
    std::cout << "\n";
    for (int j = 0; j <= tree.root->number_of_keys; j++)
    {
        tree.root->child_node_pointer[j]->print();
    }
    std::cout << "\n";
    for (int j = 0; j <= tree.root->number_of_keys; j++)
    {
        for (int k = 0; k <= tree.root->child_node_pointer[j]->number_of_keys; k++)
        {
            tree.root->child_node_pointer[j]->child_node_pointer[k]->print();
        }
    }
}