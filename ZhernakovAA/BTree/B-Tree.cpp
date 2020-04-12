#include <iostream>
using namespace std;

const int t = 2;
struct BNode {
    int keys[2 * t];
    BNode* children[2 * t + 1];
    BNode* parent;
    int count; //количество ключей
    int countSons; //количество сыновей
    bool leaf; // true - узел является листом, false - не является
};

class Tree {
private:

    void insert_to_node(const int key, BNode* node);
    void sort(BNode* node);

public:
    Tree()
    {
        root = nullptr;
    }
    BNode* root;
    void add_key(int key);
    void print_tree(BNode* root);
};

void Tree::insert_to_node(int key, BNode* node) 
{
    node->keys[node->count] = key;
    node->count = node->count + 1;
    sort(node);
}

void Tree::sort(BNode* node) {
    int m;
    for (int i = 0; i < (2 * t - 1); i++) {
        for (int j = i + 1; j <= (2 * t - 1); j++) {
            if ((node->keys[i] != 0) && (node->keys[j] != 0)) {
                if ((node->keys[i]) > (node->keys[j])) {
                    m = node->keys[i];
                    node->keys[i] = node->keys[j];
                    node->keys[j] = m;
                }
            }
            else break;
        }
    }
}

void Tree::add_key(const int key)
{
    if (root == nullptr) 
    {
        BNode* newRoot = new BNode;
        newRoot->keys[0] = key;
        for (int j = 1; j <= (2 * t - 1); j++) 
            newRoot->keys[j] = 0;
        for (int i = 0; i <= (2 * t); i++) 
            newRoot->children[i] = nullptr;
        newRoot->count = 1;
        root = newRoot;
    }
    else {
        BNode* ptr = root;
        while (ptr->leaf == false) //выбор ребенка до тех пор, пока узел не будет являться листом
        { 
            for (int i = 0; i <= (2 * t - 1); i++)  //перебираем все ключи
            { 
                if (ptr->keys[i] != 0) 
                {
                    if (key < ptr->keys[i]) 
                    {
                        ptr = ptr->children[i];
                        break;
                    }
                    if ((ptr->keys[i + 1] == 0) && (key > ptr->keys[i])) 
                    {
                        ptr = ptr->children[i + 1]; //перенаправляем к самому последнему ребенку, если цикл не "сломался"
                        break;
                    }
                }
                else break;
            }
        }
        insert_to_node(key, ptr);
    }
}

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

int main()
{
    Tree mytree = Tree();
    mytree.add_key(8);
    mytree.add_key(6);
    //mytree.insert(2);
    //mytree.insert(1);
    //mytree.insert(10);
    mytree.print_tree(mytree.root);
    return 0;
}

