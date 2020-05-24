#include <iostream>
using namespace std;

const int t = 2;
const int order = (2 * t - 1);

struct BNode
{
    int keys[order];
    BNode* child[order + 1];
    BNode(int key);
    int number_of_keys;
};

BNode::BNode(int key)
{
    this->keys[0] = key;
    for (int i = 1; i < (order); i++)
    {
        this->keys[i] = 0;
    }
    for (int i = 0; i < (order + 1); i++)
    {
        this->child[i] = nullptr;
    }
    this->number_of_keys = 1;
}

class Tree
{
private:
    void insert(const int key, BNode* node);
    void sort(BNode* node);
    BNode* search_leaf(int key);
    BNode* search_parent(BNode* node, BNode* root);
    void restruct(BNode* node);
    void setup_child(BNode* new_child1, BNode* new_child2, BNode* node);
public:
    Tree()
    {
        root = nullptr;
    }
    BNode* root;
    void add_key(int key);
    void delete_key(int key);
    BNode* search_node(int key, BNode* root);
    void print_tree(BNode* root);

};

void Tree::insert(int key, BNode* node)
{
    node->keys[node->number_of_keys] = key;
    node->number_of_keys = node->number_of_keys + 1;
    sort(node);
}

BNode* Tree::search_node(int key, BNode* root)
{
    {
        for (int i = 0; i < (root->number_of_keys); i++)
        {
            if (root->keys[i] == key)
            {
                return root;
            }
        }
        for (int i = 0; i < (root->number_of_keys); i++)
        {
            if (key < root->keys[i])
            {
                return search_node(key, root->child[i]);
            }
            if ((key > root->keys[i]) && (root->number_of_keys == (i + 1)))
            {
                return search_node(key, root->child[i + 1]);
            }
        }

    }
}

BNode* Tree::search_parent(BNode* node, BNode* root)
{
    for (int i = 0; i < (2 * t); i++)
    {
        if (root->child[i] == node)
        {
            return root;
        }
        if (root->child[i] != nullptr)
        {
            search_parent(node, root->child[i]);
        }
    }
}

BNode* Tree::search_leaf(int key)
{
    BNode* temp = root;
    while (temp->child[0] != nullptr)
    {
        for (int i = 0; i < (order); i++)
        {
            if (temp->keys[i] != 0)
            {
                if (key < temp->keys[i])
                {
                    temp = temp->child[i];
                    break;
                }
                if ((temp->keys[i + 1] == 0) && (key > temp->keys[i]))
                {
                    temp = temp->child[i + 1];
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return temp;
}

void Tree::sort(BNode* node) {
    int m;
    for (int i = 0; i < (order); i++)
    {
        for (int j = i + 1; j <= (order); j++)
        {
            if ((node->keys[i] != 0) && (node->keys[j] != 0))
            {
                if ((node->keys[i]) > (node->keys[j]))
                {
                    m = node->keys[i];
                    node->keys[i] = node->keys[j];
                    node->keys[j] = m;
                }
            }
            else break;
        }
    }
}

void Tree::setup_child(BNode* new_child1, BNode* new_child2, BNode* node)
{
    for (int i = 0; i < (t - 1); i++)
    {
        new_child1->keys[i] = node->keys[i];
        new_child2->keys[i] = node->keys[i + t];
    }
    new_child1->number_of_keys = t - 1;
    new_child2->number_of_keys = t - 1;

    if (node->child[0] != nullptr)
    {
        for (int i = 0; i <= (t - 1); i++)
        {
            new_child1->child[i] = node->child[i];
            new_child2->child[i] = node->child[i + t];
        }
    }
}

void Tree::add_key(const int key)
{
    if (root == nullptr)
    {
        root = new BNode(key);
        return;
    }

    BNode* temp = search_leaf(key);

    insert(key, temp);

    BNode* temp_parent = search_parent(temp, root);

    while (temp->number_of_keys >= (order))
    {
        if (temp == root)
        {
            restruct(temp);
        }
        else
        {
            restruct(temp);
            temp = temp_parent;
        }
    }
}

void Tree::restruct(BNode* node)
{
    BNode* new_child1 = new BNode(0);
    new_child1->number_of_keys = 0;

    BNode* new_child2 = new BNode(0);
    new_child2->number_of_keys = 0;

    setup_child(new_child1, new_child2, node);

    if (node == root)
    {
        node->keys[0] = node->keys[t - 1];
        for (int i = 1; i < (order); i++)
        {
            node->keys[i] = 0;
        }
        node->number_of_keys = 1;
        node->child[0] = new_child1;
        node->child[1] = new_child2;
        for (int i = 2; i < (order + 1); i++)
        {
            node->child[i] = nullptr;
        }
    }
    else
    {
        BNode* parent_node = search_parent(node, root);
        insert(node->keys[t - 1], parent_node);
        for (int i = 0; i < (order + 1); i++)
        {
            if (parent_node->child[i] == node)
            {
                parent_node->child[i] = nullptr;
            }
        }
        for (int i = 0; i < (order + 1); i++)
        {
            if (parent_node->child[i] == nullptr)
            {
                for (int j = (order); j > (i + 1); j--)
                {
                    parent_node->child[j] = parent_node->child[j - 1];
                }
                parent_node->child[i + 1] = new_child2;
                parent_node->child[i] = new_child1;
                break;
            }
        }
    }
}

void Tree::delete_key(int key)
{
    BNode* node_for_delete = search_node(key, root);
    if ((node_for_delete->child[0] == nullptr) && (node_for_delete->number_of_keys == t))
    {
        for (int i = 0; i < (node_for_delete->number_of_keys); i++)
        {
            if (node_for_delete->keys[i] == key)
            {
                for (int j = i; j < (node_for_delete->number_of_keys); j++)
                {
                    node_for_delete->keys[j] = node_for_delete->keys[j + 1];
                }
                node_for_delete->number_of_keys = node_for_delete->number_of_keys - 1;
            }
        }
    }
}

void Tree::print_tree(BNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    for (int i = 0; i < (order); i++)
    {
        if (root->number_of_keys >= i)
        {
            cout << root->keys[i] << ",";
        }
    }
    cout << '\n';
    for (int i = 0; i < (order + 1); i++)
    {
        if (root->child[i] != nullptr)
        {
            print_tree(root->child[i]);
        }
    }
}

int main()
{
    Tree mytree = Tree();
    mytree.add_key(6);
    mytree.add_key(12);
    mytree.print_tree(mytree.root);
    cout << '\n';
    mytree.add_key(19);
    mytree.print_tree(mytree.root);
    cout << '\n';
    mytree.add_key(3);
    mytree.print_tree(mytree.root);
    cout << '\n';
    mytree.add_key(70);
    mytree.print_tree(mytree.root);
    cout << '\n';
    mytree.delete_key(6);
    mytree.print_tree(mytree.root);
    cout << '\n';
    mytree.add_key(22);
    mytree.print_tree(mytree.root);

    return 0;
}