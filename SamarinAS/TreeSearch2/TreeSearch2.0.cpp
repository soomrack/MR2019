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

public:
    Node(int key, void* data);
//public:
//    ~Node()
//    {
//        delete left_Child;
//        delete right_Child;
//    }
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
    int add_data(int key, void* data);
    void Print(Node* root);
    Node* Search(Node* root,int key);
    Node* Search_Parent(Node* root, int key);
    Node* Delete_Node(Node* root, int key);
    Node* Min_Node(Node* root);
    Node* Max_Node(Node* root);
    Node* Search_Min_Left_Child_For_Right_Root(Node* root);
   // void Delete_Tree(Node* root);
    Node* Next_node(bool restart = true);
    void Print_for_next_node();
};

//void Tree::Delete_Tree(Node* root)
//{
//    Node* delete_parent_node = Search_Parent(root, root->key);
//    if (delete_parent_node != nullptr)
//    {
//        if()
//    }
//    delete root;
//}

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

Node* Tree::Delete_Node(Node* root, int key)
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
        if (Dead_Node_Parant->left_Child == Dead_Node)
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
        if (Dead_Node_Parant->left_Child == Dead_Node)
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
    if ((Dead_Node->left_Child != nullptr) && (Dead_Node->right_Child != nullptr))
    {
        Temp = Search_Min_Left_Child_For_Right_Root(Dead_Node);
        Temp1 = Search_Parent(root, Temp->key);
        (Dead_Node->key) = (Temp->key);
        if (Temp == Temp1->right_Child)
        {
            Temp1->right_Child = Temp->right_Child;
        }
        if (Temp == Temp1->left_Child)
        {
            Temp1->left_Child = Temp->right_Child;
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

Node* Tree::Next_node(bool restart)
{
    static queue <Node*> check_children;
    if (restart == true)
    {
        check_children.push(this->root);
        cout << (this->root)->key << "\n";
        restart = false;
    }
    Node* current_node = check_children.front();
    check_children.pop();
    if ((current_node->left_Child == nullptr) && (current_node->right_Child == nullptr)&&(check_children.empty()))
    {
        return nullptr;
    }
    if (current_node->left_Child != nullptr)
    {
        check_children.push(current_node->left_Child);
    }

    if (current_node->right_Child != nullptr)
    {
        check_children.push(current_node->right_Child);
    }
    return current_node;
}

void Tree::Print_for_next_node()
{
    Next_node(true);
    while (Node* node = this->Next_node(false))
    {
        cout << node->key << "\n";
    }
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

    mytree.Print_for_next_node();
    //mytree.Print(mytree.root);
    //cout << '\n';
    //a = mytree.Search(mytree.root, 1)->key;
    //cout << a<<'\n';
    //b = mytree.Search_Parent(mytree.root, 1)->key;
    //cout << b << '\n';
    //mytree.Delete_Node(mytree.root,4);
    //mytree.Delete_Node(mytree.root,3);
    //mytree.Delete_Node(mytree.root,30);
    //cout << '\n';
    //mytree.Print(mytree.root);
    //b = mytree.Min_Node(mytree.root)->key;
    //cout << b << '\n';
   // mytree.Delete_Tree(mytree.root->left_Child);
   // mytree.Print(mytree.root);

    return 0;
}

