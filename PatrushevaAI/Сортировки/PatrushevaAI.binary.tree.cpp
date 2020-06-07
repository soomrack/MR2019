#include <iostream>
#include <queue> 

using namespace std;



class Node
{
public:
    int key;
    void* data;
    Node* left_child;
    Node* right_child;

public:
    Node(int key, void* data);

};

Node::Node(int key, void* data)
{
    this->key = key;
    this->data = data;
    left_child = nullptr;
    right_child = nullptr;
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
    Node* search(Node* root, int key);
    Node* search_parent(Node* root, int key);
    Node* delete_node(Node* root, int key);
    Node* min_node(Node* root);
    Node* max_node(Node* root);
    Node* search_min_left_ch_for_right_root(Node* root);
    Node* next_node(bool restart = true);
    void print_for_next_node();
};



Node* Tree::min_node(Node* root)
{
    Node* Min = root;
    while (Min->left_child != nullptr)
    {
        Min = Min->left_child;
    }
    return Min;
}


Node* Tree::search_min_left_ch_for_right_root(Node* root)
{
    Node* p = root;
    if (p->right_child != nullptr)
    {
        return min_node(p->right_child);
    }
    return root;
}


Node* Tree::max_node(Node* root)
{
    Node* Max = root;
    while (Max->right_child != nullptr)
    {
        Max = Max->right_child;
    }
    return Max;
}

Node* Tree::delete_node(Node* root, int key)
{
    Node* Dead_Node = search(root, key);
    Node* Dead_Node_Parant = search_parent(root, key); //Родитель удаляемого узла
    //У удаляемого узла нет детей
    if ((Dead_Node->left_child == nullptr) && (Dead_Node->right_child == nullptr))
    {
        if ((Dead_Node_Parant->left_child) == Dead_Node)
        {
            Dead_Node_Parant->left_child = nullptr;
        }
        else
        {
            Dead_Node_Parant->right_child = nullptr;
        }
    }
    // У удаляемого элеиента есть левый ребенок
    if ((Dead_Node->left_child != nullptr) && (Dead_Node->right_child == nullptr))
    {
        if (Dead_Node_Parant->left_child == Dead_Node)
        {
            Dead_Node_Parant->left_child = Dead_Node->left_child;
        }
        else
        {
            Dead_Node_Parant->right_child = Dead_Node->left_child;
        }
    }
    // У удаляемого элемента есть правый ребенок
    if ((Dead_Node->left_child == nullptr) && (Dead_Node->right_child != nullptr))
    {
        if (Dead_Node_Parant->left_child == Dead_Node)
        {
            Dead_Node_Parant->left_child = Dead_Node->right_child;
        }
        else
        {
            Dead_Node_Parant->right_child = Dead_Node->right_child;
        }
    }

    Node* Temp = nullptr;
    Node* Temp1 = nullptr;
    if ((Dead_Node->left_child != nullptr) && (Dead_Node->right_child != nullptr))
    {
        Temp = search_min_left_ch_for_right_root(Dead_Node);
        Temp1 = search_parent(root, Temp->key);
        (Dead_Node->key) = (Temp->key);
        if (Temp == Temp1->right_child)
        {
            Temp1->right_child = Temp->right_child;
        }
        if (Temp == Temp1->left_child)
        {
            Temp1->left_child = Temp->right_child;
        }

    }
    return root;
}

Node* Tree::search_parent(Node* root, int key)
{
    if ((root == nullptr) || ((root->left_child)->key == key) || ((root->right_child)->key == key))
    {
        return root;
    }
    if (root->key > key)
    {
        return search_parent(root->left_child, key);
    }
    if (root->key < key)
    {
        return search_parent(root->right_child, key);
    }
}

Node* Tree::search(Node* root, int key)
{
    if ((root == nullptr) || (root->key == key))
    {
        return root;
    }
    if (root->key > key)
    {
        return search(root->left_child, key);
    }
    else
    {
        return search(root->right_child, key);
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
        cout << root->key << '\n';
    }
    Print(root->left_child);
    Print(root->right_child);
}

Node* Tree::next_node(bool restart)
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
    if (current_node == nullptr)
    {
        return nullptr;
    }
    if (current_node->left_child != nullptr)
    {
        check_children.push(current_node->left_child);
    }

    if (current_node->right_child != nullptr)
    {
        check_children.push(current_node->right_child);
    }
    return current_node;
}

void Tree::print_for_next_node()
{
    next_node(true);
    while (Node* node = this->next_node(false))
    {
        cout << node->key << "\n";
    }
}

Node* Tree::search_parent_for_new_node(int key, Node* root)
{
    if (root->key <= key)
    {
        if (root->right_child == nullptr)
        {
            return root;
        }
        return search_parent_for_new_node(key, root->right_child);
    }

    if (root->key > key)
    {
        if (root->left_child == nullptr)
        {
            return root;
        }
        return search_parent_for_new_node(key, root->left_child);
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
        parent->left_child = child;
    }
    else
    {
        parent->right_child = child;
    }
    return 1;
}

int main()
{
    int a = 0, b = 0;
    Tree mytree = Tree();

    mytree.add_data(42, nullptr);
    mytree.add_data(22, nullptr);
    mytree.add_data(62, nullptr);
    mytree.add_data(7, nullptr);
    mytree.add_data(32, nullptr);
    mytree.add_data(52, nullptr);
    mytree.add_data(82, nullptr);
    mytree.add_data(5, nullptr);
    mytree.add_data(17, nullptr);
    mytree.add_data(26, nullptr);
    mytree.add_data(36, nullptr);
    mytree.add_data(72, nullptr);
    mytree.add_data(92, nullptr);
    mytree.add_data(3, nullptr);
    mytree.add_data(6, nullptr);

    mytree.print_for_next_node();


    return 0;
}
