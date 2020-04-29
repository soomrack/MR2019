#include <iostream>
#include <queue>

using namespace std;


class Node
{
public:
    int key;
    void* data;
    Node* left_descendant;
    Node* right_descendant;
public:
    Node(int key, void* data);
};

class Tree
{
public:
    Node* root;
    Tree();
public:
    void add_node(int key, void* data);
    void delete_node(Node* root, int key);
    void print_depth_first_traversal(Node* root);
    void print_breadth_first_traversal(Node* root);
    Node* search_node(Node* root, int key);
private:
    Node* search_parent_of_node(Node* root, int key);
    Node* search_parent_for_new_child(int key, Node* root);
    Node* find_min(Node* root);
    void copy_and_delete_node(Node* from, Node* to);
};

Node::Node(int key, void* data)
{
    this->key = key;
    this->data = data;
    left_descendant = nullptr;
    right_descendant = nullptr;
}

Tree::Tree()
{
    root = nullptr;
}

Node* Tree::search_parent_for_new_child(int key, Node* root)
{
    if (root->key > key)
    {
        if (root->left_descendant == nullptr) return root;
        else return search_parent_for_new_child(key, root->left_descendant);
    }

    if (root->key <= key)
    {
        if (root->right_descendant == nullptr) return root;
        else return search_parent_for_new_child(key, root->right_descendant);
    }
}

void Tree::add_node(int key, void* data)
{
    Node* descendant = new Node(key, data);

    if (root == nullptr)
    {
        root = descendant;
        return;
    }

    Node* parent = search_parent_for_new_child(key, root);

    if (key <= parent->key)
        parent->left_descendant = descendant;
    else
        parent->right_descendant = descendant;
}

void Tree::delete_node(Node* root, int key)
{

    Node* remove_node = search_node(root, key);
    Node* parent_of_remove_node = search_parent_of_node(root, key);

    // узел не имеет потомков
    if (remove_node->left_descendant == nullptr && remove_node->right_descendant == nullptr)
    {
        if (parent_of_remove_node->left_descendant == remove_node)
        {
            parent_of_remove_node->left_descendant = nullptr;
        }
        else
        {
            parent_of_remove_node->right_descendant = nullptr;
        }
    }
    // узел имеет только правого потомка
    if (remove_node->left_descendant == nullptr && remove_node->right_descendant != nullptr)
    {
        if (parent_of_remove_node->left_descendant == remove_node)
        {
            parent_of_remove_node->left_descendant = remove_node->right_descendant;
        }
        else
        {
            parent_of_remove_node->right_descendant = remove_node->right_descendant;
        }
    }
    // узел имеет только левого потомка
    if (remove_node->left_descendant != nullptr && remove_node->right_descendant == nullptr)
    {
        if (parent_of_remove_node->left_descendant == remove_node)
        {
            parent_of_remove_node->left_descendant = remove_node->left_descendant;
        }
        else
        {
            parent_of_remove_node->right_descendant = remove_node->left_descendant;
        }
    }
    // узел имеет оба потомка
    if (remove_node->left_descendant != nullptr && remove_node->right_descendant != nullptr)
    {
        Node* replace_node = find_min(remove_node->right_descendant);

        if (replace_node->right_descendant == nullptr)
            copy_and_delete_node(replace_node, remove_node);
        else
        {
            remove_node->key = replace_node->key;
            remove_node->data = replace_node->data;
            copy_and_delete_node(replace_node->right_descendant, replace_node);
        }
    }
}

Node* Tree::find_min(Node* root)
{
    if (root->left_descendant == nullptr)
        return root;
    else
        return find_min(root->left_descendant);
}

void Tree::copy_and_delete_node(Node* from, Node* to)
{
    int key_buffer = from->key;
    void* data_buffer = from->data;
    delete_node(root, from->key);
    to->key = key_buffer;
    to->data = data_buffer;
}

Node* Tree::search_node(Node* root, int key)
{
    if (root == nullptr) return root;

    if (root->key == key) return root;
    else if (root->key > key) return search_node(root->left_descendant, key);
    else return search_node(root->right_descendant, key);

}

Node* Tree::search_parent_of_node(Node* root, int key)
{
    if (root == nullptr) return root;

    if (root->right_descendant != nullptr && root->right_descendant->key == key) return root;
    if (root->left_descendant != nullptr && root->left_descendant->key == key) return root;

    else if (root->key > key) return search_parent_of_node(root->left_descendant, key);
    else return search_parent_of_node(root->right_descendant, key);

}
//вывод дерева в глубину
void Tree::print_depth_first_traversal(Node* root)
{
    if (root != nullptr)
    {
        cout << root->key << '\n';
        print_tree_dsf(root->left_descendant);
        print_tree_dsf(root->right_descendant);
    }
}

//вывод дерева  в ширину
void Tree::print_breadth_first_traversal(Node* root)
{
    queue <Node*> elements;
    elements.push(root);

    while (!elements.empty())
    {
        Node* buffer = elements.front();
        cout << buffer->key << endl;
        elements.pop();

        if (buffer->left_descendant != nullptr)
        {
            elements.push(buffer->left_descendant);
        }
        if (buffer->right_descendant != nullptr)
        {
            elements.push(buffer->right_descendant);
        }
    }
}

int main()
{
    Tree mytree = Tree();

    mytree.add_node(40, nullptr);
    mytree.add_node(20, nullptr);
    mytree.add_node(60, nullptr);
    mytree.add_node(5, nullptr);
    mytree.add_node(30, nullptr);
    mytree.add_node(50, nullptr);
    mytree.add_node(80, nullptr);
    mytree.add_node(3, nullptr);
    mytree.add_node(15, nullptr);
    mytree.add_node(24, nullptr);
    mytree.add_node(35, nullptr);
    mytree.add_node(70, nullptr);
    mytree.add_node(90, nullptr);
    mytree.add_node(1, nullptr);
    mytree.add_node(4, nullptr);

    mytree.print_tree_dsf(mytree.root);

    mytree.delete_node(mytree.root, 5);
    cout << "\n";
    mytree.print_tree_bsf(mytree.root);
    cout << "\n";
    mytree.print_tree_dsf(mytree.root);
}
