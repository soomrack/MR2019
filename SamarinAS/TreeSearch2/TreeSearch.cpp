#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    void* data;
    Node* left_Child;
    Node* right_Child;

public:
    Node(int key, void* data);
};

Node::Node(int key, void* data)
{
    this->key = key;
    this->data = data;
    left_Child = nullptr;
    right_Child = nullptr;
}

    
class Tree
{
public:
    Node* root;
public:
    Tree()
    {
        root = nullptr;
    }
public:
    Node* search_parent_for_new_node(int key, Node* root);
public:
    int add_data(int key, void* data);
public:
    void Print(Node* root);
public:
    Node* Search(Node* root,int key);
public:
    Node* Search_Parent(Node* root, int key);
public:
    Node* Delete(Node* root, int key);
public:
    Node* Min_Node(Node* root);
public:
    Node* Max_Node(Node* root);
public:
    Node* Search_Min_Left_Child_For_Right_Root(Node* root);
};

Node* Tree::Min_Node(Node* root)
{
    Node* Min = root;
    while (Min->left_Child != nullptr)
    {
        Min = Min->left_Child;
    }
    return Min;
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


Node *Tree::Max_Node(Node* root)
{
    Node* Max = root;
    while (Max->right_Child != nullptr)
    {
        Max = Max->right_Child;
    }
    return Max;
}

Node* Tree::Delete(Node* root, int key)
{
    Node* Dead_Node = Search(root, key);
    Node* Dead_Node_Parant = Search_Parent(root,key); //Родитель удаляемого узла
    //У удаляемого узла нет детей
    if((Dead_Node->left_Child == nullptr) && (Dead_Node->right_Child == nullptr))
    {
        if ((Dead_Node_Parant->left_Child) == Dead_Node)
        {
            Dead_Node_Parant->left_Child = nullptr;
        }
        else
        {
            Dead_Node_Parant->right_Child = nullptr;
        }
    }
    // У удаляемого элеиента есть левый ребенок
    if ((Dead_Node->left_Child != nullptr) && (Dead_Node->right_Child == nullptr))
    {
        if ((Dead_Node_Parant->left_Child)->key == Dead_Node->key)
        {
            Dead_Node_Parant->left_Child = Dead_Node->left_Child;
        }
        else
        {
            Dead_Node_Parant->right_Child = Dead_Node->left_Child;
        }
    }
    // У удаляемого элемента есть правый ребенок
    if ((Dead_Node->left_Child == nullptr) && (Dead_Node->right_Child != nullptr))
    {
        if ((Dead_Node_Parant->left_Child)->key == Dead_Node->key)
        {
            Dead_Node_Parant->left_Child = Dead_Node->right_Child;
        }
        else
        {
            Dead_Node_Parant->right_Child = Dead_Node->right_Child;
        }
    }
    
    Node* Temp = nullptr;
    Node* Temp1 = nullptr;

    if ((Dead_Node->left_Child != nullptr) && (Dead_Node->right_Child != nullptr)&& ((Dead_Node->left_Child)->left_Child == nullptr) && ((Dead_Node->left_Child)->right_Child == nullptr) && ((Dead_Node->right_Child)->left_Child == nullptr) && ((Dead_Node->right_Child)->right_Child == nullptr))
    {
        Temp = Min_Node(Dead_Node);
        cout << Temp->key << '\n';
        Temp1 = Search_Parent(root, Temp->key);
        cout << Temp1->key << '\n';
        (Dead_Node->key) = (Temp->key);
        cout << Dead_Node->key << '\n';
        if (Temp->right_Child == nullptr)
        {
            Temp1->left_Child = nullptr;
        }
        else
        {
            (Temp1->left_Child) = (Temp->right_Child);
        }
    }

    if ((Dead_Node->left_Child != nullptr) && (Dead_Node->right_Child != nullptr) && ((Dead_Node->left_Child)->left_Child != nullptr) && ((Dead_Node->left_Child)->right_Child != nullptr) && ((Dead_Node->right_Child)->left_Child != nullptr) && ((Dead_Node->right_Child)->right_Child != nullptr))
    {
        Temp = Search_Min_Left_Child_For_Right_Root(Dead_Node);
        //cout << Temp->key << '\n';
        Temp1 = Search_Parent(root, Temp->key);
        //cout << Temp1->key << '\n';
        (Dead_Node->key) = (Temp->key);
        //cout << Dead_Node->key << '\n';
        if (Temp->right_Child == nullptr)
        {
            Temp1->left_Child = nullptr;
        }
        else
        {
            (Temp1->left_Child) = (Temp->right_Child);
        }
    }
    return root;
}

Node* Tree::Search_Parent(Node* root, int key)
{
    if ((root == nullptr) || ((root->left_Child)->key == key) || ((root->right_Child)->key == key))
    {
        return root;
    }
    if (root->key > key)
    {
        return Search_Parent(root->left_Child, key);
    }
    if(root->key < key)
    {
        return Search_Parent(root->right_Child, key);
    }
}

Node* Tree::Search(Node* root, int key)
{
    if ((root == nullptr) || (root->key == key))
    {
        return root;
    }
    if (root->key > key)
    {
        return Search(root->left_Child, key);
    }
    else
    {
        return Search(root->right_Child, key);
    }
}

void Tree::Print(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->key)
    {
        cout << root->key<<'\n';
    }
    Print(root->left_Child);
    Print(root->right_Child);
}

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

    Node* parent = search_parent_for_new_node(key, root);

    if (key <= parent->key) 
    {
        parent->left_Child = child;
    }
    else 
    {
        parent->right_Child = child;
    }
    return 1;
}

int main()
{
    int a = 0, b=0;
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
    mytree.Print(mytree.root);
    cout << '\n';
    //a = mytree.Search(mytree.root, 1)->key;
    //cout << a<<'\n';
    //b = mytree.Search_Parent(mytree.root, 1)->key;
    //cout << b << '\n';
    //mytree.Delete(mytree.root,3);
    //cout << '\n';
    //mytree.Print(mytree.root);
    return 0;
}

