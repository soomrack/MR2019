#include <iostream>

using namespace std;

class Node{
    public:
        int key;
        void *data;
        Node *left_child;
        Node *right_child;
        Node *parent;
    public:
        Node();
        Node(const int key, void *data, Node *parent);
        ~Node() {};
};

class Tree : public Node{
    public:
        Node *root;
    public:
        Tree();
        ~Tree() {};
        void addData(const int key, void *data);
        void deleteData(const int key);
        void printTree(Node *root);
        Node *minNode(Node *root);
        Node *maxNode(Node *root);
        Node *nextNode(const int key, Node *root);
        Node *prevNode(const int key, Node *root);
        Node *search(const int key, Node *root);
    private:
        Node *findParentForNewNode(const int key, Node *root);
};

Node::Node()
{
    this->key = 0;
    this->data = nullptr;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

Node::Node(int key, void *data, Node *parent)
{
    this->key = key;
    this->data = data;
    this->parent = parent;
    this->left_child = nullptr;
    this->right_child = nullptr;
}

Tree::Tree()
{
    this->root = nullptr;
}

Node *Tree::minNode(Node *root)
{
    if(root->left_child == nullptr)
    {
        return root->left_child;
    }
    return minNode(root->left_child);
}

Node *Tree::maxNode(Node *root)
{
    if(root->right_child == nullptr)
    {
        return root->right_child;
    }
    return maxNode(root->right_child);
}

Node *Tree::nextNode(const int key, Node *root)
{
    if(root->right_child != nullptr)
    {
        return minNode(root->right_child);
    }
    else
    {
        Node *parent = root->parent;
        while(parent != nullptr && root != parent->left_child)
        {
            root = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

Node *Tree::prevNode(const int key, Node *root)
{
    if(root->left_child != nullptr)
    {
        return maxNode(root->left_child);
    }
    else
    {
        Node *parent = root->parent;
        while(parent != nullptr && root != parent->right_child)
        {
            root = parent;
            parent = parent->parent;
        }
        return parent;
    }
}

Node *Tree::search(const int key, Node *root)
{
    if(root == nullptr || root->key == key)
    {
        return root;
    }
    else if(root->key < key)
    {
        return search(key, root->right_child);
    }
    else
    {
        return search(key, root->left_child);
    }
}

Node *Tree::findParentForNewNode(const int key, Node *root)
{
    if(root->key < key)
    {
        if(root->right_child == nullptr)
        {
            return root;
        }
        else return findParentForNewNode(key, root->right_child);
    }
    else
    {
        if(root->left_child == nullptr)
        {
            return root;
        }
        else return findParentForNewNode(key, root->left_child);
    }
}

void Tree::addData(const int key, void *data)
{
    if(this->root == nullptr)
    {
        Node *child = new Node(key, data, nullptr);
        this->root = child;
    }
    else
    {
        parent = findParentForNewNode(key, this->root);
        Node *child = new Node(key, data, parent);
        if(parent->key < key)
        {
            parent->right_child = child;
        }
        else
        {
            parent->left_child = child;
        }
    }
}

void Tree::deleteData(const int key)
{
    Node *deletingNode = search(key, this->root);
    if(deletingNode->right_child == nullptr && deletingNode->left_child == nullptr)
    {
        if(deletingNode->parent->left_child == deletingNode)
        {
            deletingNode->parent->left_child = nullptr;
        }
        else
        {
            deletingNode->parent->right_child = nullptr;
        }
    }
    else if(deletingNode->right_child == nullptr && deletingNode->left_child != nullptr)
    {
        if(deletingNode->parent->left_child == deletingNode)
        {
            deletingNode->parent->left_child = deletingNode->left_child;
        }
        else
        {
            deletingNode->parent->right_child = deletingNode->left_child;
        }
    }
    else if(deletingNode->right_child != nullptr && deletingNode->left_child == nullptr)
    {
        if(deletingNode->parent->left_child == deletingNode)
        {
            deletingNode->parent->left_child = deletingNode->right_child;
        }
        else
        {
            deletingNode->parent->right_child = deletingNode->right_child;
        }
    }
    else
    {
        root->key = minNode(root->right_child)->key;
        root = minNode(root->right_child);
    }
}

void Tree::printTree(Node *root)
{
    if(root == nullptr)
    {
        return;
    }
    else if(root->data != nullptr)
    {
        cout << root->key << " : " << *((int *)root->data) << '\n';
    }
    printTree(root->left_child);
    printTree(root->right_child);
}

int main() {
    int a = 10;
    int b = 9;
    int c = 8;
    int d = 7;
    int e = 6;
    int f = 5;
    int g = 4;
    int h = 3;
    int x = 2;
    int y = 1;
    int z = 0;
    Tree tree = Tree();
    tree.addData(0, &a);
    tree.addData(1, &b);
    tree.addData(2, &c);
    tree.addData(-3, &d);
    tree.addData(-1, &e);
    tree.addData(4, &f);
    tree.addData(-2, &g);
    tree.addData(5, &h);
    tree.addData(3, &x);
    tree.addData(-5, &y);
    tree.addData(-4, &z);
    tree.deleteData(2);
    tree.printTree(tree.root);

    //cout << *((int *)(tree.search(-2, tree.root))->data) << endl;
    system("pause");
}