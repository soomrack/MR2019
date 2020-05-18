#include <iostream>
#include <algorithm>

using namespace std;

class Tree;

class Node
{
    public:
        Node(int t, bool is_leaf);
        ~Node() {};
        void insertNode(const int key, void *data);
        void splitChild(const int border, Node *node);
        void traverse();
        Node *search(const int key);
        friend class Tree;
    private:
        int *key;
        int t;
        void **data;
        Node **child;
        int keys_counter;
        bool is_leaf;
};

class Tree
{
    public:
        Tree(int t);
        ~Tree() {};
        void printTree();
        void addData(const int key, void *data);
        void deleteNode(Node *node);
    private:
        Node *root;
        int t;
};

void Tree::printTree()
{
    if (root != nullptr)
    {
        root->traverse();
    }
}

Node::Node(int t, bool is_leaf)
{
    this->t = t;
    this->is_leaf = is_leaf;
    this->key = new int[this->t - 1];
    this->data = new void *[this->t - 1];
    this->child = new Node *[this->t];
    this->keys_counter = 0;
}

Tree::Tree(int t)
{
    this->root = nullptr;
    this->t = t;
}

void Node::traverse()
{
    int index = 0;
    for (index = 0; index < keys_counter; index++)
    {
        if (is_leaf == false)
        {
            child[index]->traverse();
        }
        cout << " (" << key[index] << ", " << *(char *)(data[index]) << ")";
    }
    if (is_leaf == false)
    {
        child[index]->traverse();
    }
}

Node *Node::search(const int key)
{
    int index = 0;
    while (index < this->keys_counter && key > this->key[index])
    {
        index++;
    }
    if (this->key[index] == key)
    {
        return this;
    }
    if (this->is_leaf == true)
    {
        return nullptr;
    }
    return child[index]->search(key);
}

void Tree::addData(const int key, void *data)
{
    if (root == nullptr)
    {
        root = new Node(t, true);
        root->key[0] = key;
        root->data[0] = data;
        root->keys_counter = 1;
    }
    else
    {
        if (root->keys_counter == t - 1)
        {
            Node *node = new Node(t, false);
            node->child[0] = root;
            node->splitChild(0, root);
            int index = 0;
            if (node->key[0] < key)
            {
                index++;
            }
            node->child[index]->insertNode(key, data);
            root = node;
        }
        else
        {
            root->insertNode(key, data);
        }
    }
}

void Node::insertNode(const int key, void *data)
{
    int index = keys_counter - 1;
    if (is_leaf == true)
    {
        while (index >= 0 && this->key[index] > key)
        {
            this->key[index + 1] = this->key[index];
            this->data[index + 1] = this->data[index];
            index--;
        }
        this->key[index + 1] = key;
        this->data[index + 1] = data;
        this->keys_counter++;
    }
    else
    {
        while (index >= 0 && this->key[index] > key)
        {
            index--;
        }
        if (child[index + 1]->keys_counter == t - 1)
        {
            splitChild(index + 1, child[index + 1]);
            if (this->key[index + 1] < key)
            {
                index++;
            }
        }
        child[index + 1]->insertNode(key, data);
    }
}

void Node::splitChild(const int border, Node *node)
{
    cout << "Success!" << endl;
    Node *new_node = new Node(node->t, node->is_leaf);
    new_node->keys_counter = t / 2 - 1;
    for (int index = 0; index < t / 2 - 1; index++)
    {
        new_node->key[index] = node->key[index + t / 2];
        new_node->data[index] = node->data[index + t / 2];
    }
    if (node->is_leaf == false)
    {
        for (int index = 0; index < t / 2; index++)
        {
            new_node->child[index] = node->child[index + t / 2];
        }
    }
    node->keys_counter = t / 2 - 1;
    for (int index = keys_counter; index >= border + 1; index--)
    {
        child[index + 1] = child[index];
    }
    child[border + 1] = new_node;
    for (int index = keys_counter - 1; index >= border; index--)
    {
        key[index + 1] = node->key[index];
        data[index + 1] = node->data[index];
    }
    key[border] = node->key[t / 2 - 1];
    keys_counter++;
}

void Tree::deleteNode(Node *node)
{
    if (node != nullptr)
    {
        for (int index = 0; index < t / 2; index++)
        {
            if (node->child[index] != nullptr)
            {
                deleteNode(node->child[index]);
            }
            else
            {
                delete(node);
            }
        }
    }
}

typedef struct Symbol{
    int key;
    char symbol[10];
} Symbol;

int main()
{
    Tree tree = Tree(6);
    Symbol a = {1, "a"};
    Symbol b = {2, "b"};
    Symbol c = {3, "c"};
    Symbol d = {4, "d"};
    Symbol e = {5, "e"};
    Symbol f = {6, "f"};
    Symbol g = {7, "g"};
    Symbol h = {8, "h"};
    tree.addData(d.key, d.symbol);
    tree.addData(g.key, g.symbol);
    tree.addData(a.key, a.symbol);
    tree.addData(b.key, b.symbol);
    tree.addData(e.key, e.symbol);
    tree.addData(h.key, h.symbol);
    tree.addData(c.key, c.symbol);
    tree.addData(f.key, f.symbol);
    tree.printTree();
    return 0;
}