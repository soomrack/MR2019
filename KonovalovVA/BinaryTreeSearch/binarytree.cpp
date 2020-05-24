#include <iostream>
using namespace std;

class Node 
{
public:
    int key;
    void* data;
    Node* left_child;
    Node* right_child;

public:
    Node(int key, void* data) 
    {
        this->data = data;
        this->key = key;
        left_child = nullptr;
        right_child = nullptr;
    }

    ~Node() 
    {
        key = 0;
        data = nullptr;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class Tree 
{
public:
    Node* root;
    Tree() 
    {
        root = nullptr;
    }

public:
    Node* parent_search_for_new_node(int key, Node* root);
    void add_data(int key, void* data);
    Node* node_search(int key, Node* root);
    Node* parent_node_search(int key, Node* root);
    Node* min_left(Node* root);
    void delete_data(int key);
    void delete_root(void);
    void traverse(Node* root);
};

Node* Tree::parent_search_for_new_node(int key, Node* root) 
{
    if (key < root->key) 
    {
        if (root->left_child == nullptr) return(root);
        return(parent_search_for_new_node(key, root->left_child));
    }
    else 
    {
        if (root->right_child == nullptr) return(root);
        return(parent_search_for_new_node(key, root->right_child));
    }
}

void Tree::add_data(int key, void* data) 
{
    Node* child = new Node(key, data);
    if (root == nullptr) 
    {
        root = child;
        return;
    }

    Node* parent = parent_search_for_new_node(key, root);

    if (key < parent->key) parent->left_child = child;
    else parent->right_child = child;
}

Node* Tree::node_search(int key, Node* root) 
{
    if (root == nullptr) return nullptr;
    if (key == root->key) return root;
    if (key < root->key) node_search(key, root->left_child);
    else node_search(key, root->right_child);
}

Node* Tree::parent_node_search(int key, Node* root) 
{
    if (root->key == key) return nullptr;
    if (root->left_child != nullptr) if (key == root->left_child->key) return root;
    if (root->right_child != nullptr) if (key == root->right_child->key) return root;

    if (key < root->key) parent_node_search(key, root->left_child);
    else parent_node_search(key, root->right_child);
}

Node* Tree::min_left(Node* root) 
{
    Node* find_min = root;
    while (find_min->left_child != nullptr) 
    {
        find_min = find_min->left_child;
    }
    return find_min;
}

void Tree::delete_data(int key) 
{

    Node* delete_node = node_search(key, root);
    if (delete_node == nullptr) return;

    if ((delete_node->left_child != nullptr) && (delete_node->right_child != nullptr)) // у удаляемого узла два ребенка 
    {
        Node* temp = min_left(delete_node->right_child);
        if (temp == delete_node->right_child) 
        {
            delete_node->key = temp->key;
            delete_node->data = temp->data;
            delete_node->right_child = temp->right_child;
            delete temp;
            return;
        }
        else 
        {
            delete_node->data = temp->data;
            delete_node->key = temp->key;
            delete_data(temp->key);
            return;
        }
    }

    Node* parent_delete_node = parent_node_search(key, root);
    if (parent_delete_node == nullptr) 
    {
        delete_root();
        return;
    }
    
    if ((delete_node->left_child == nullptr) && (delete_node->right_child == nullptr)) // у удаляемого узла нет детей
    {
        if (parent_delete_node->left_child == delete_node) parent_delete_node->left_child = nullptr;
        else parent_delete_node->right_child = nullptr;
        delete delete_node;
        return;
    }

    
    if ((delete_node->left_child != nullptr) && (delete_node->right_child == nullptr)) // у удаляемого узла только левый ребенок
    {
        if (parent_delete_node->left_child == delete_node) parent_delete_node->left_child = delete_node->left_child;
        else parent_delete_node->right_child = delete_node->left_child;
        delete delete_node;
        return;
    }

    if ((delete_node->left_child == nullptr) && (delete_node->right_child != nullptr)) // у удаляемого узла только правый ребенок
    {
        if (parent_delete_node->left_child == delete_node) parent_delete_node->left_child = delete_node->right_child;
        else parent_delete_node->right_child = delete_node->right_child;
        delete delete_node;
        return;
    }
}

void Tree::delete_root(void) // функция для удаления корня
{
    if ((root->left_child == nullptr) && (root->right_child == nullptr)) // у корня нет детей
    {
        root = nullptr;
        return;
    }

    if ((root->left_child != nullptr) && (root->right_child == nullptr)) // у корня только левый ребенок
    {
        root = root->left_child;
        return;
    }

    if ((root->left_child == nullptr) && (root->right_child != nullptr)) // у корня  только правый ребенок
    {
        root = root->right_child;
        return;
    }
}

void Tree::traverse(Node* root) 
{
    if (root != nullptr) 
    {
        traverse(root->left_child);
        cout << root->key << endl;
        traverse(root->right_child);
    }
    return;

}

int main() 
{
    Tree mytree;
    mytree.add_data(12, nullptr);
    mytree.add_data(34, nullptr);
    mytree.add_data(56, nullptr);
    mytree.add_data(78, nullptr);
    mytree.add_data(910, nullptr);

    mytree.traverse(mytree.root);
    cout << endl;

    mytree.delete_data(910);
    mytree.traverse(mytree.root);
    cout << endl;

    mytree.delete_data(12);
    mytree.delete_data(34);
    mytree.delete_data(78);
    mytree.traverse(mytree.root);
}