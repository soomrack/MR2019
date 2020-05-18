#include <iostream>

class Node {
public:
    int key;
    void* data;
    Node* left_child;
    Node* right_child;

public:
    Node(int key, void* data) {
        this->data = data;
        this->key = key;
        left_child = nullptr;
        right_child = nullptr;
    }
};

class Tree {
public:
    Node* root;
    Tree() {
        root = nullptr;
    }
public:
    Node* parent_search_for_new_node(int key, Node* root);
    void add_data(int key, void* data);
    Node* node_search(int key, Node* root);
    Node* parent_node_search(int key, Node* root);
    Node* min_left(Node* root);
    void delete_data(int key);
};

Node* Tree::parent_search_for_new_node(int key, Node* root) {
    if (key < root->key) {
        if (root->left_child == nullptr) return(root);
        return(parent_search_for_new_node(key, root->left_child));
    }
    else {
        if (root->right_child == nullptr) return(root);
        return(parent_search_for_new_node(key, root->right_child));
    }
}

void Tree::add_data(int key, void* data) {
    Node* child = new Node(key, data);
    if (root == nullptr) {
        root = child;
        return;
    }

    Node* parent = parent_search_for_new_node(key, child);

    if (key < parent->key) parent->left_child = child;
    else parent->right_child = child;
}

Node* Tree::node_search(int key, Node* root) {
    if ((key == root->key) || (root==nullptr)) return root;
    if (key < root->key) node_search(key, root->left_child);
    else node_search(key, root->right_child);
}

Node* Tree::parent_node_search(int key, Node* root) {
    if ((key == root->left_child->key) || (key == root->right_child->key)) return root;
    if (key < root->key) parent_node_search(key, root->left_child);
    else parent_node_search(key, root->right_child);
}

Node* Tree::min_left(Node* root) {
    Node* find_min = root;
    while (find_min->left_child != nullptr) {
        find_min = find_min->left_child;
    }
    return find_min;
}

void Tree::delete_data(int key) {
    Node* delete_node = node_search(key, root);
    if (delete_node == nullptr) return;
    Node* parent_delete_node = parent_node_search(key, root);

    //У удаляемого узла нет детей
    if ((delete_node->left_child == nullptr) && (delete_node->right_child == nullptr)) {
        if (parent_delete_node->left_child == delete_node) parent_delete_node->left_child = nullptr;
        else parent_delete_node->right_child = nullptr;
        return;
    }

    //У удаляемого узла только левый ребенок
    if ((delete_node->left_child != nullptr) && (delete_node->right_child == nullptr)) {
        if (parent_delete_node->left_child == delete_node) parent_delete_node->left_child = delete_node->left_child;
        else parent_delete_node->right_child = delete_node->left_child;
        return;
    }

    //У удаляемого узла только правый ребенок
    if ((delete_node->left_child == nullptr) && (delete_node->right_child != nullptr)) {
        if (parent_delete_node->left_child == delete_node) parent_delete_node->left_child = delete_node->right_child;
        else parent_delete_node->right_child = delete_node->right_child;
        return;
    }

    //У удаляемого узла два ребенка 
    Node* temp = min_left(delete_node->right_child);
    if (temp == delete_node->right_child) {
        delete_node->key = temp->key;
        delete_node->data = temp->data;
        delete_node->right_child = temp->right_child;
        return;
    }
    else {
        delete_node->data = temp->data;
        delete_node->key = temp->key;
        delete_data(temp->key);
        return;
    }
    //Что делать, если удаляемый узел - корень дерева, у которого нет родителя?

}

int main() {
    Tree trii;
    trii.add_data(8, nullptr);
    trii.add_data(1, nullptr);
    trii.add_data(5, nullptr);
    trii.add_data(32, nullptr);

}