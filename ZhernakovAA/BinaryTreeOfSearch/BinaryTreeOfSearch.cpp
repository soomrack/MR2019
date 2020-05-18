#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int key;
    void* data;
    Node* left_Child;
    Node* right_Child;
    Node* parent;
public:
    Node(int key, void* data);
};

Node::Node(int key, void* data)
{
    this->key = key;
    this->data = data;
    left_Child = nullptr;
    right_Child = nullptr;
    parent = nullptr;
}

class Tree
{
public:
    Node* root;
    Tree()
    {
        root = nullptr;
    }
    Node* search_parent_for_new_node(int key, Node* root);
    int add_data(int key, void* data);
    void dsf_Print(Node* root);
    void bsf_Print();
    Node* Search(Node* root, int key);
    Node* Delete(Node* root, int key);
    Node* Min_Node(Node* root);
    Node* Max_Node(Node* root);
    Node* Search_Min_Left_Child_For_Right_Root(Node* root);
    Node* Next_Node(bool restart);
};

Node* Tree::search_parent_for_new_node(int key, Node* root)
{
    if (root->key <= key)
    {
        if (root->right_Child == nullptr)
        {
            return root;
        }
        return search_parent_for_new_node(key, root->right_Child);
    }

    if (root->key > key)
    {
        if (root->left_Child == nullptr)
        {
            return root;
        }
        return search_parent_for_new_node(key, root->left_Child);
    }
}

int Tree::add_data(int key, void* data)
{
    Node* child = new Node(key, data);

    if (root == nullptr)
    {
        root = child;
        return 1;
    }

    child -> parent = search_parent_for_new_node(key, root);

    if (key <= child->parent->key)
    {
        child->parent->left_Child = child;
    }
    else
    {
        child->parent->right_Child = child;
    }
    return 1;
}

Node* Tree::Search(Node* root, int key)
{
    if (root->key > key)
    {
        return Search(root->left_Child, key);
    }
    else if (root->key < key)
    {
        return Search(root->right_Child, key);
    }
    else if ((root == nullptr) || (root->key == key))
    {
        return root;
    }
}

void Tree::dsf_Print(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->key)
    {
        cout << root->key << '\n';
    }
    dsf_Print(root->left_Child);
    dsf_Print(root->right_Child);
}

Node* Tree::Min_Node(Node* root)
{
    while (root->left_Child != nullptr)
    {
        root = root->left_Child;
    }
    return root;
}

Node* Tree::Max_Node(Node* root)
{
    while (root->right_Child != nullptr)
    {
        root = root->right_Child;
    }
    return root;
}

Node* Tree::Search_Min_Left_Child_For_Right_Root(Node* root)
{
    Node* p = root;
    if (p->right_Child != nullptr)
    {
        return Min_Node(p->right_Child);
    }
    return root;
}

Node* Tree::Delete(Node* root, int key)
{
    Node* Dead_Node = Search(root, key);
    // У удаляемого элемента нет детей
    if (Dead_Node->left_Child == nullptr && Dead_Node->right_Child == nullptr)
    {
        if ((Dead_Node->parent->left_Child) == Dead_Node)
        {
            Dead_Node->parent->left_Child = nullptr;
        }
        else
        {
            Dead_Node->parent->right_Child = nullptr;
        }
    }
    // У удаляемого элемента есть только левый ребенок
    if ((Dead_Node->left_Child != nullptr) && (Dead_Node->right_Child == nullptr))
    {
        if ((Dead_Node->parent->left_Child) == Dead_Node)
        {
            Dead_Node->parent->left_Child = Dead_Node->left_Child;
        }
        else
        {
            Dead_Node->parent->right_Child = Dead_Node->left_Child;
        }
    }
    // У удаляемого элемента есть только правый ребенок
    if ((Dead_Node->left_Child == nullptr) && (Dead_Node->right_Child != nullptr))
    {
        if ((Dead_Node->parent->left_Child) == Dead_Node)
        {
            Dead_Node->parent->left_Child = Dead_Node->right_Child;
        }
        else
        {
            Dead_Node->parent->right_Child = Dead_Node->right_Child;
        }
    }
    //У удаляемого элемента два ребенка
    Node* Replacement = nullptr;
    if ((Dead_Node->left_Child != nullptr) && (Dead_Node->right_Child != nullptr))
    {
        Replacement = Search_Min_Left_Child_For_Right_Root(Dead_Node);
        (Dead_Node->key) = (Replacement->key);
        if (Replacement == Replacement->parent->right_Child)
        {
            Replacement->parent->right_Child = Replacement->right_Child;
        }
        if (Replacement == Replacement->parent->left_Child)
        {
            Replacement->parent->left_Child = Replacement->left_Child;
        }
    }
    return root;
}

Node* Tree::Next_Node(bool restart)
{
    static queue <Node*> check_children;
    if (check_children.empty() && !restart) return nullptr;
    if (restart)
    {
        while (!check_children.empty())
            check_children.pop();
        check_children.push(this->root);
    }
    Node* current_node = check_children.front();
    check_children.pop();
    if (current_node->left_Child)
        check_children.push(current_node->left_Child);
    if (current_node->right_Child)
        check_children.push(current_node->right_Child);
    return current_node;
}

void Tree::bsf_Print()
{
    cout << Next_Node(true)->key << endl;
    while (Node* node = this->Next_Node(false))
    {
        cout << node->key << endl;
    }
}

int main()
{
    int a = 0, b = 0;
    Tree mytree = Tree();

    mytree.add_data(40, nullptr);
    mytree.add_data(20, nullptr);
    mytree.add_data(60, nullptr);
    mytree.add_data(5, nullptr);
    mytree.add_data(30, nullptr);
    mytree.add_data(50, nullptr);
    mytree.add_data(80, nullptr);
    mytree.add_data(3, nullptr);
    mytree.add_data(15, nullptr);
    mytree.add_data(24, nullptr);
    mytree.add_data(35, nullptr);
    mytree.add_data(70, nullptr);
    mytree.add_data(90, nullptr);
    mytree.add_data(1, nullptr);
    mytree.add_data(4, nullptr);
    mytree.add_data(16, nullptr);
    mytree.dsf_Print(mytree.root);
    cout << '\n';

    a = mytree.Min_Node(mytree.root)->key;
    cout << a << '\n' << '\n';

    a = mytree.Max_Node(mytree.root)->key;
    cout << a << '\n' << '\n';

    mytree.bsf_Print();
    cout << '\n';

    mytree.Delete(mytree.root, 4);
    mytree.dsf_Print(mytree.root);
    cout << '\n';

    mytree.Delete(mytree.root, 40);
    mytree.dsf_Print(mytree.root);
    cout << '\n';

    mytree.Delete(mytree.root, 30);
    mytree.dsf_Print(mytree.root);
    cout << '\n';

    mytree.bsf_Print();
    cout << '\n';
    return 0;
}