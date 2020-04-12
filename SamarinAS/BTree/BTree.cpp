
#include <iostream>
using namespace std;
const int t = 2;

class BNode
{
public:
    int keys[(2 * t)];
    BNode* children[(2 * t + 1 )];
    BNode* parent;
    int count;
    bool leaf;
public:
    BNode(int key);
};

BNode::BNode(int key)
{
    this->keys[0] = key;
    for (int i = 1; i < (2 * t); i++)
    {
        this->keys[i] = 0;
    }
    for (int j = 0; j < (2*t + 1); j++)
    {
        this->children[j] = nullptr;
    }
    this->count = 1;
    this->parent = nullptr;
    this->leaf = true;
}

class Tree
{
public:
    BNode* root;
    Tree()
    {
        root = nullptr;
    }
    void add_data(const int key);
    void print_tree(BNode* root);

private:
    void insert(int key, BNode* node);
    void sort(BNode* node);
    void restruct(BNode *node);
    void search_parent(BNode *root);
};

void Tree::print_tree(BNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    for (int i = 0; i < (2*t - 1); i++)
    {
        if (root->count >= i)
        {
            cout << root->keys[i] << ",";
        }
    }
    cout << '\n';
    for (int i = 0; i < (2*t); i++)
    {
        if (root->children[i] != nullptr)
        {
            print_tree(root->children[i]);
        }
    }
}

void Tree::search_parent(BNode* root)
{
    if (root->leaf == false) //усли у узла внизу еще что-то есть
    {
        for (int i = 0; i < 2 * t; i++)
        {
            (root->children[i])->parent = root;
        }

        for (int i = 0; i < 2 * t; i++)
        {
            search_parent(root->children[i]);
        }

    }
}


void Tree::restruct(BNode* node)
{
    if (node->count < (2*t - 1))
    {
        return;
    }

    //для разделения нужно создать дв ановых ребенка, в 1го перенести t-2 ключей, во второго от t до 2t-1

    BNode *new_child1 = new BNode(0);
    new_child1->count = 0;
    int j;
    for (j = 0; j <= t - 2; j++) //копирование половины ключей в новый узел 
    {
        new_child1->keys[j] = node->keys[j]; 
    }
    new_child1->count = t - 1;

    int count_child_node = 0; // подсчет того, есть ли дети у узла
    for (int count_ch = 0; count_ch < 2 * t; count_ch++)
    {
        if (node->children[count_ch] != nullptr)
        {
            count_child_node++;
        }
    }

    if (count_child_node != 0)//усли у узла были дети
    {
        for (int i = 0; i < (t - 1); i++)
        {
            new_child1->children[i] = node->children[i]; // сохраняем имеющихся детей и делаем у них ссылку на родителя
            new_child1->children[i]->parent = new_child1;
        }
        new_child1->leaf = false;
    }
    
    BNode* new_child2 = new BNode(0);
    new_child2->count = 0;

    for (j = 0; j <= (t - 1); j++) //копирование ВТОРОЙ половины ключей в новый узел 
    {
        new_child2->keys[j] = node->keys[j + t];
    }
    new_child2->count = t-1;

    if (count_child_node != 0)//если у узла были дети
    {
        for (int i = 0; i <= (t); i++)
        {
            new_child2->children[i] = node->children[i+t]; // сохраняем имеющихся детей и делаем у них ссылку на родителя
            (new_child2->children[i])->parent = new_child2;
        }
        new_child2->leaf = false;
    }


    //теперь нужно првести манипуляции с родителем узла, который нужно разбить
    if (node->parent == nullptr) // если у узла нет родителей, те он самый верхний
    {
        node->keys[0] = node->keys[t - 1]; //в руте на первое место встет центральный элемент, а все остальные удаляем
        for (int j = 1; j <= (2 * t - 1); j++)
        {
            node->keys[j] = 0;
        }
        node->count = 1; //теперь в этом узле лежит всего 1 ключ
        node->children[0] = new_child1;
        node->children[1] = new_child2;

        for (int i = 2; i < (2 * t); i++) // обнуление других детей
        {
            node->children[i] = nullptr;
        }

        node->leaf = false;
        new_child1->parent = node;
        new_child2->parent = node;

    }
    else
    {
        insert(node->keys[t-1], node->parent); // добавим в родителя ключ, который не попал в новых детей

        for (int i = 0; i < (2 * t); i++) //перебираем всех детей родителя, пока не дойдем до нашего узла и обнулим его ссылку на него, те удалим
        {
            if ((node->parent)->children[i] == node)
            {
                (node->parent)->children[i] = nullptr;
            }
        }
        for (int i = 0; i < (2 * t); i++)
        {
            if ((node->parent)->children[i] == nullptr)
            {
                for (int j = (2 * t); j > (i + 1); j--)
                {
                    node->parent->children[j] = node->parent->children[j];
                    node->parent->children[i + 1] = new_child2;
                    node->parent->children[i] = new_child1;
                    break;
                }
            }
        }
        new_child1->parent = node->parent;
        new_child2->parent = node->parent;
        (node->parent)->leaf = false;
        //delete node;
    }
}

void Tree::insert(const int key, BNode* node)
{
    node->keys[node->count] = key;
    node->count = node->count + 1;
    sort(node);
}

void Tree::sort(BNode* node)
{
    int temp;
    for (int i = 0; i < (2 * t); i++)
    {
        if (node->count > i)// Если i или j будет больше count, то дальше еще нет ключей
        {
            for (int j = i + 1; j < 2 * t; j++)
            {
                if(node->count > j) // Если i или j будет больше count, то дальше еще нет ключей
                {
                    if (node->keys[i] > node->keys[j])
                    {
                        temp = node->keys[i];
                        node->keys[i] = node->keys[j];
                        node->keys[j] = temp;
                    }
                }
            }
        }

    }
}


void Tree::add_data(const int key)
{
    if (root == nullptr)
    {
        root = new BNode(key);
        return;
    }
    else
    {
        //поиск места, куда можно вставить ключ. temp будет переназначаться до того момента, пока он не станет листом
        BNode *temp = root;
        while (temp->leaf == false)
        {
            for (int i = 0; i < 2 * t; i++)
            {
                if (temp->keys[i] != 0) //если ключи есть. Если i<кол-ва ключей, то значит что данный ключ существует
                {
                    if (key < temp->keys[i]) //если ключ оказался меньше рассматриваемого ключа, то нужно вставить его в лист левее
                    {
                        temp = temp->children[i];
                        break;
                    }
                    if ((temp->keys[i+1] == 0) && (key > temp->keys[i])) //Если кол-во ключей меньше или равно индексу следующего ключа, то тот ключ пустой, если я не запутался 
                    {
                        temp = temp->children[i + 1]; //если ключ оказался больше, то берем лист справа
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        insert(key, temp); // теперь добавим ключ к найденному листу

        while(temp->count <= 2*t) // если количество ключей превышает допустимое
        {
            if (temp == root)
            {
                restruct(temp);
                break;
            }
            else
            {
                restruct(temp);
                temp = temp->parent;
            }
        }
    }
}

int main()
{
    Tree mytree = Tree();
    mytree.add_data(6);
    mytree.add_data(8);
    mytree.add_data(2);
    mytree.add_data(1);
    mytree.add_data(9);
    mytree.add_data(10);
    //int a0 = mytree.root->count;
    //int a1 = mytree.root->children[0]->count;
    //int a2 = mytree.root->children[1]->count;
   // cout << a0<<a1<<a2 << '\n';
    mytree.print_tree(mytree.root);
    return 0;

}


