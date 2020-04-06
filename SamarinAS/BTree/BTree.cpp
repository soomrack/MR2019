
#include <iostream>
const int t = 2;

class BNode
{
public:
    int keys[t];
    BNode* children[2 * t - 1];
    BNode* parent;
    int count;
public:
    BNode(int key);
};

BNode::BNode(int key)
{
    this->keys[0] = key;
    for (int i = 1; i <= t; i++)
    {
        this->keys[i] = 0;
    }
    for (int j = 0; j < (2*t - 1); j++)
    {
        this->children[j] = nullptr;
    }
    this->count = 1;
    this->parent = nullptr;
}

class Tree
{
public:
    BNode* root;
    Tree()
    {
        root = nullptr;
    }
    int Add_data(int key);

public:
    BNode* search_free_space(int key,BNode* root);
};

BNode* Tree::search_free_space(int key,BNode* root)
{
    if (root->count < t - 1)
    {
        return root;
    }
    for (int i = 0; i < t; i++) //перебираем ключи узла для нахождения промежутка, в котрый входит ключ
    {
        if (key <= root->keys[i]) 
        {
            search_free_space(key,root->children[i]);
        }
        if (key > root->keys[t])
        {
            search_free_space(key, root->children[i+1]);
        }
    }

}

int Tree::Add_data(int key)
{
    BNode* child = new BNode(key);
    
    if (root == nullptr)
    {
        root = child;
        return 1;
    }

    BNode* parant = search_free_space(key, root);

    for (int i = 0; i < t; i++) //перебираем ключи узла для нахождения промежутка, в котрый входит ключ
    {
        if (key <= parant->keys[i])
        {
            if(parant->children[i] == nullptr) // если ребенка не было
            {
                parant->children[i] = child;
            }
            (parant->children[i])->keys[(parant->children[i])->count] = child->keys[0]; // если был, то пустой ключ его приравниваем к ключу
            (parant->children[i])->count++;
               
        }   
    }
}

int main()
{

}


