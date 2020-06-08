#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    void* data;
public:
    // Левый ребенок
    Node* leftChild;
    // Правый ребенок
    Node* rightChild;
    // Родитель
    Node* parent;
public:
    // Конструктор
    Node(int key, void* data);
    // Деструктор
    ~Node();
};

Node::Node(int key, void* data)
{
    this->key = key;
    this->data = data;
    parent = nullptr;
    leftChild = nullptr;
    rightChild = nullptr;
};

class Tree
{
public:
    Node* root;
public:
    Tree();
public:
    // Добавление узла
    void Add(int key, void* data);
    // Удаление узла
    void Delete(Node* root, int key);
    // в зависимости от наличия тех или иных детей
    void withoutChildren_delete(Node* root, Node* node, int key);
    void withLeftChildren_delete(Node* root, Node* node, int key);
    void withRightChildren_delete(Node* root, Node* node, int key);
    void withTwoChildren_delete(Node* root,Node* node, int key);
public:
    // Поиск родителя узла
    Node* parentSearch(int key, Node* root);
    // Поиск узла по ключу
    Node* SearchNode(Node* root, int key);
    // Поиск наименьшего левого ребенка в правой части
    Node* MinLeftChildrenFromRight(Node* root);
    // Обход графа в ширину
    void bypass_depth(Node* root);
};

Tree::Tree()
{
    root = nullptr;
}


Node* Tree::parentSearch(int key, Node* root)
{
    if (root->key <= key)
    {
        if (root->rightChild != nullptr)
        {
            return parentSearch(key, root->rightChild);;
        }
        return root;
    }
    else 
    {
        if (root->leftChild != nullptr)
        {
            return parentSearch(key, root->leftChild);;
        }
        return root;
    }
}

void Tree::Add(int key, void* data)
{
    Node* child = new Node(key, data);

    if (root == nullptr)
    {
        root = child;
        return;
    }

    child->parent = parentSearch(key, root);

    if (key <= child->parent->key)
    {
        child->parent->leftChild = child;
    }
    else
    {
        child->parent->rightChild = child;
    }
    return;
}

void bypass_depth(Node* root)
{
    if (root != nullptr)
    {
        if (root->key)
        {
            cout << root->key;
        }
        cout << '\n';
        bypass_depth(root->leftChild);
        bypass_depth(root->rightChild);
    }
    else return;
}

Node* Tree::SearchNode(Node* root, int key)
{
    if ((root == nullptr) || (root->key == key))
    {
        return root;
    }
    else if (root->key > key)
    {
        return SearchNode(root->leftChild, key);
    }
    else
    {
        return SearchNode(root->rightChild, key);
    }
}

Node* Tree::MinLeftChildrenFromRight(Node* root)
{
    Node* leftMinimum = root;
    if (leftMinimum->rightChild != nullptr)
    {
        while (leftMinimum->leftChild != nullptr)
        {
            leftMinimum = leftMinimum->leftChild;
        }
    }
    return leftMinimum;
}
void Tree::withoutChildren_delete(Node* root, Node* node, int key)
{
    node = SearchNode(root, key);

    if (node->leftChild == nullptr && node->rightChild == nullptr && node != nullptr)
    {
        if ((node->parent->leftChild) == node)
        {
            node->parent->leftChild = nullptr;
        }
        else
        {
            node->parent->rightChild = nullptr;
        }
    }
}

void Tree::withLeftChildren_delete(Node* root, Node* node, int key)
{
    node = SearchNode(root, key);
    if ((node->leftChild != nullptr) && (node->rightChild == nullptr))
    {
        if ((node->parent->leftChild) == node)
        {
            node->parent->leftChild = node->leftChild;
        }
        else
        {
            node->parent->rightChild = node->leftChild;
        }
    }
}

void Tree::withRightChildren_delete(Node* root, Node* node, int key)
{
    Node* swap = nullptr;
    if ((node->leftChild != nullptr) && (node->rightChild != nullptr))
    {
        swap = MinLeftChildrenFromRight(node);
        (node->key) = (swap->key);
        if (swap == (swap->parent->rightChild))
        {
            swap->parent->rightChild = swap->rightChild;
        }
        if (swap == (swap->parent->leftChild))
        {
            swap->parent->leftChild = swap->leftChild;
        }
    }
}

void Tree::withTwoChildren_delete(Node* root, Node* node, int key)
{
    node = SearchNode(root, key);
    Node* swap = nullptr;
    if ((node->leftChild != nullptr) && (node->rightChild != nullptr))
    {
        swap = MinLeftChildrenFromRight(node);
        (node->key) = (swap->key);
        if (swap == (swap->parent->rightChild))
        {
            swap->parent->rightChild = swap->rightChild;
        }
        if (swap == (swap->parent->leftChild))
        {
            swap->parent->leftChild = swap->leftChild;
        }
    }
}

void Tree::Delete(Node* root, int key)
{
    Node* nodeToDelete = SearchNode(root, key);
    // Адаптивное удаление
    // В зависимости от ситуации

    // Узел, у которого нет детей
    withoutChildren_delete(root, nodeToDelete,key);

    // Узел, у которого есть левый ребенок
    withLeftChildren_delete(root, nodeToDelete, key);

    // Узел, у которого правый ребенок
    withRightChildren_delete(root, nodeToDelete, key);

    // Узел, у которого есть 2 ребенка
    withTwoChildren_delete(root, nodeToDelete, key);
    return;
}

int main()
{
    Tree TreeTest = Tree();

    TreeTest.Add(1, nullptr);
    TreeTest.Add(4, nullptr);
    TreeTest.Add(6, nullptr);
    TreeTest.Add(9, nullptr);
    TreeTest.Add(12, nullptr);
    TreeTest.Add(14, nullptr);

    TreeTest.Delete(TreeTest.root,4);
    TreeTest.Delete(TreeTest.root, 9);

    bypass_depth(TreeTest.root);

    return 0;
}