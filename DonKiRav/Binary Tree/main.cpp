#include <iostream>
using namespace std;

class BinaryTreeNode {
public:
    int key;
    int* data;
    BinaryTreeNode* left_child;
    BinaryTreeNode* right_child;
public:
    BinaryTreeNode(int key, int* data);
};

BinaryTreeNode::BinaryTreeNode(int key, int* data)
{
    this->key = key;
    this->data = data;
    left_child = nullptr;
    right_child = nullptr;
}

class BinaryTree
{
public:
    BinaryTreeNode* root;
public:
    BinaryTree()
    {
        root = nullptr;
    }
public:
    static void     PRINT(BinaryTreeNode* root);
    int             ADD(int key, int* data);
    static BinaryTreeNode* FIND(BinaryTreeNode* root, int key);
    static BinaryTreeNode* REMOVE(BinaryTreeNode* root, int key);
private:
    static BinaryTreeNode* parent_node(BinaryTreeNode* root, int key);
    static BinaryTreeNode* min_node(BinaryTreeNode* root);
    static BinaryTreeNode* max_node(BinaryTreeNode* root);
    static BinaryTreeNode* find_parent_for_new_node(BinaryTreeNode* root, int key);
};

int BinaryTree::ADD(int key, int* data) {
    auto* child = new BinaryTreeNode(key, data);
    if (root == nullptr) {
        root = child;
        return 1;
    }
    BinaryTreeNode* parent = find_parent_for_new_node(root, key);
    if (key <= parent->key)
        parent->left_child = child;
    else
        parent->right_child = child;
    return 1;
}

BinaryTreeNode* BinaryTree::REMOVE(BinaryTreeNode* root, int key)
{
    BinaryTreeNode* delete_node = FIND(root, key);
    BinaryTreeNode* parent_delete_node = parent_node(root, key);
    /// Нет детей
    if((delete_node->left_child == nullptr) && (delete_node->right_child == nullptr)) {
        if ((parent_delete_node->left_child) == delete_node)
            parent_delete_node->left_child = nullptr;
        else
            parent_delete_node->right_child = nullptr;
    }
    /// Левый ребёнок
    if ((delete_node->left_child != nullptr) && (delete_node->right_child == nullptr)) {
        if (parent_delete_node->left_child == delete_node)
            parent_delete_node->left_child = delete_node->left_child;
        else
            parent_delete_node->right_child = delete_node->left_child;
    }
    /// Правый ребёнок
    if ((delete_node->left_child == nullptr) && (delete_node->right_child != nullptr)) {
        if (parent_delete_node->left_child == delete_node)
            parent_delete_node->left_child = delete_node->right_child;
        else
            parent_delete_node->right_child = delete_node->right_child;
    }
    BinaryTreeNode* a = nullptr;
    BinaryTreeNode* b = nullptr;
    if ((delete_node->left_child != nullptr) && (delete_node->right_child != nullptr)) {
        if (delete_node->right_child != nullptr)
            a = min_node(delete_node->right_child);
        b = parent_node(root, a->key);
        (delete_node->key) = (a->key);
        if (a == b->left_child)
            b->left_child = a->right_child;
        if (a == b->right_child)
            b->right_child = a->right_child;
    }
    return root;
}

BinaryTreeNode* BinaryTree::FIND(BinaryTreeNode* root, int key) {
    if ((root == nullptr) || (root->key == key))
        return root;
    if (root->key > key)
        return FIND(root->left_child, key);
    else
        return FIND(root->right_child, key);
}

void BinaryTree::PRINT(BinaryTreeNode* root) {
    if (root == nullptr)
        return;
    if (root->key)
        cout << root->key << endl;
    PRINT(root->left_child);
    PRINT(root->right_child);
}

BinaryTreeNode* BinaryTree::parent_node(BinaryTreeNode* root, int key) {
    if ((root == nullptr) || ((root->left_child)->key == key) || ((root->right_child)->key == key))
        return root;
    if (root->key > key)
        return parent_node(root->left_child, key);
    if(root->key < key)
        return parent_node(root->right_child, key);
    return nullptr;
}

BinaryTreeNode* BinaryTree::min_node(BinaryTreeNode* root) {
    BinaryTreeNode* MIN = root;
    while (MIN->left_child != nullptr)
        MIN = MIN->left_child;
    return MIN;
}

BinaryTreeNode *BinaryTree::max_node(BinaryTreeNode* root) {
    BinaryTreeNode* Max = root;
    while (Max->right_child != nullptr)
        Max = Max->right_child;
    return Max;
}

BinaryTreeNode* BinaryTree::find_parent_for_new_node(BinaryTreeNode* root, int key) {
    if (root->key <= key) {
        if (root->right_child == nullptr)
            return root;
        return find_parent_for_new_node(root->right_child, key);
    }
    if (root->key > key) {
        if (root->left_child == nullptr)
            return root;
        return find_parent_for_new_node(root->left_child, key);
    }
    return nullptr;
}

int main() {

    BinaryTree tree1 = BinaryTree();

    tree1.ADD(40, nullptr);
    tree1.ADD(20, nullptr);
    tree1.ADD(60, nullptr);
    tree1.ADD(5, nullptr);
    tree1.ADD(30, nullptr);
    tree1.ADD(50, nullptr);
    tree1.ADD(80, nullptr);

    tree1.PRINT(tree1.root);

    int * a;
    a = tree1.FIND(tree1.root, 1)->data;
    cout << a <<'\n';

    tree1.REMOVE(tree1.root, 30);
    cout << '\n';

    tree1.PRINT(tree1.root);

    return 0;
}