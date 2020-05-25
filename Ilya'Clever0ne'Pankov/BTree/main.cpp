#include <iostream>
#include <algorithm>

using namespace std;

class BTree;

class BNode
{
    private:
        int *key;
        int t;
        void **data;
        BNode **child;
        int keys_counter;
        bool is_leaf;
    public:
        BNode(const int t, const bool is_leaf);
        ~BNode() {};
        void insertNode(const int key, void *data);
        void splitChild(const int border, BNode *node);
        void traverse();
        BNode *search(const int key);
        int findKey(const int key);
        void remove(const int key);
        void removeFromLeaf(const int index);
        void removeFromNonLeaf(const int index);
        void *getData(const int key);
        int getPrevKey(const int index);
        int getNextKey(const int index);
        void fill(const int index);
        void borrowFromPrev(const int border);
        void borrowFromNext(const int border);
        void merge(const int index);
        friend class BTree;
};

class BTree
{
    private:
        BNode *root;
        int t;
    public:
        BTree(int t);
        ~BTree() {};
        void printTree();
        void addData(const int key, void *data);
        void deleteData(const int key);
};

void BTree::printTree()
{
    if (root != nullptr)
    {
        root->traverse();
    }
}

BNode::BNode(const int t, const bool is_leaf)
{
    this->t = t;
    this->is_leaf = is_leaf;
    this->key = new int[this->t - 1];
    this->data = new void *[this->t - 1];
    this->child = new BNode *[this->t];
    this->keys_counter = 0;
}

BTree::BTree(int t)
{
    this->root = nullptr;
    this->t = t;
}

void BNode::traverse()
{
    int index = 0;
    for (index = 0; index < keys_counter; index++)
    {
        if (is_leaf == false)
        {
            child[index]->traverse();
        }
        cout << " (" << key[index] << ", " << *(char *)(data[index]) << ")";
    }
    if (is_leaf == false)
    {
        child[index]->traverse();
    }
}

BNode *BNode::search(const int key)
{
    int index = 0;
    while (index < this->keys_counter && key > this->key[index])
    {
        index++;
    }
    if (this->key[index] == key)
    {
        return this;
    }
    if (this->is_leaf == true)
    {
        return nullptr;
    }
    return child[index]->search(key);
}

void BTree::addData(const int key, void *data)
{
    if (root == nullptr)
    {
        root = new BNode(t, true);
        root->key[0] = key;
        root->data[0] = data;
        root->keys_counter = 1;
    }
    else
    {
        if (root->keys_counter == t - 1)
        {
            BNode *node = new BNode(t, false);
            node->child[0] = root;
            node->splitChild(0, root);
            int index = 0;
            if (node->key[0] < key)
            {
                index++;
            }
            node->child[index]->insertNode(key, data);
            root = node;
        }
        else
        {
            root->insertNode(key, data);
        }
    }
}

void BNode::insertNode(const int key, void *data)
{
    int index = keys_counter - 1;
    if (is_leaf == true)
    {
        while (index >= 0 && this->key[index] > key)
        {
            this->key[index + 1] = this->key[index];
            this->data[index + 1] = this->data[index];
            index--;
        }
        this->key[index + 1] = key;
        this->data[index + 1] = data;
        this->keys_counter++;
    }
    else
    {
        while (index >= 0 && this->key[index] > key)
        {
            index--;
        }
        if (child[index + 1]->keys_counter == t - 1)
        {
            splitChild(index + 1, child[index + 1]);
            if (this->key[index + 1] < key)
            {
                index++;
            }
        }
        child[index + 1]->insertNode(key, data);
    }
}

void BNode::splitChild(const int border, BNode *node)
{
    BNode *new_node = new BNode(node->t, node->is_leaf);
    new_node->keys_counter = t / 2 - 1;
    for (int index = 0; index < t / 2 - 1; index++)
    {
        new_node->key[index] = node->key[index + t / 2];
        new_node->data[index] = node->data[index + t / 2];
    }
    if (node->is_leaf == false)
    {
        for (int index = 0; index < t / 2; index++)
        {
            new_node->child[index] = node->child[index + t / 2];
        }
    }
    node->keys_counter = t / 2 - 1;
    for (int index = keys_counter; index >= border + 1; index--)
    {
        child[index + 1] = child[index];
    }
    child[border + 1] = new_node;
    for (int index = keys_counter - 1; index >= border; index--)
    {
        key[index + 1] = node->key[index];
        data[index + 1] = node->data[index];
    }
    key[border] = node->key[t / 2 - 1];
    data[border] = node->data[t / 2 - 1];
    keys_counter++;
}

int BNode::findKey(const int key)
{
    int index = 0;
    while (index < this->keys_counter && this->key[index] < key)
    {
        index++;
    }
    return index;
}

void *BNode::getData(const int key)
{
    int index = findKey(key);
    if (index < this->keys_counter && this->key[index] == key)
    {
        return this->data[index];
    }
    else
    {
        return child[index - 1]->getData(key);
    }
}

void BNode::remove(const int key)
{
    int index = findKey(key);
    if (index < this->keys_counter && this->key[index] == key)
    {
        if (this->is_leaf == true)
        {
            removeFromLeaf(index);
        }
        else
        {
            removeFromNonLeaf(index);
        }
    }
    else
    {
        if (this->is_leaf == true)
        {
            cout << "There is no data with the key " << key << " in the tree!" << endl;
        }
        else
        {
            bool is_node_filled = (index == this->keys_counter) ? true : false;
            if (child[index]->keys_counter < t / 2)
            {
                fill(index);
            }
            if (is_node_filled == true && index > this->keys_counter)
            {
                child[index - 1]->remove(key);
            }
            else
            {
                child[index]->remove(key);
            }
        }
    }
}

void BNode::removeFromLeaf(const int border)
{
    for (int index = border + 1; index < this->keys_counter; index++)
    {
        this->key[index - 1] = this->key[index];
        this->data[index - 1] = this->data[index];
    }
    keys_counter--;
}

void BNode::removeFromNonLeaf(const int index)
{
    int key = this->key[index];
    if (child[index]->keys_counter >= t / 2)
    {
        int prev_key = getPrevKey(index);
        this->key[index] = prev_key;
        this->data[index] = getData(prev_key);
        child[index]->remove(prev_key);
    }
    else if (child[index + 1]->keys_counter >= t / 2)
    {
        int next_key = getNextKey(index);
        this->key[index] = next_key;
        this->data[index] = getData(next_key);
        child[index + 1]->remove(next_key);
    }
    else
    {
        merge(index);
        child[index]->remove(key);
    }
}

int BNode::getPrevKey(const int index)
{
    BNode *current_node = child[index];
    while (current_node->is_leaf == false)
    {
        current_node = current_node->child[current_node->keys_counter];
    }
    return current_node->key[current_node->keys_counter - 1];
}

int BNode::getNextKey(const int index)
{
    BNode *current_node = child[index + 1];
    while (current_node->is_leaf == false)
    {
        current_node = current_node->child[0];
    }
    return current_node->key[0];
}

void BNode::fill(const int index)
{
    if (index != 0 && child[index - 1]->keys_counter >= t / 2)
    {
        borrowFromPrev(index);
    }
    else if (index != keys_counter && child[index + 1]->keys_counter >= t / 2)
    {
        borrowFromNext(index);
    }
    else
    {
        if (index != keys_counter)
        {
            merge(index);
        }
        else
        {
            merge(index - 1);
        }
    }
}

void BNode::borrowFromPrev(const int border)
{
    BNode *child_node = child[border];
    BNode *sibling_node = child[border - 1];
    for (int index = child_node->keys_counter - 1; index >= 0; index--)
    {
        child_node->key[index + 1] = child_node->key[index];
        child_node->data[index + 1] = child_node->data[index];
    }
    if (child_node->is_leaf == false)
    {
        for (int index = child_node->keys_counter; index >= 0; index--)
        {
            child_node->child[index + 1] = child_node->child[index];
        }
    }
    child_node->key[0] = key[border - 1];
    if (child_node->is_leaf == false)
    {
        child_node->child[0] = sibling_node->child[sibling_node->keys_counter];
    }
    key[border - 1] = sibling_node->key[sibling_node->keys_counter - 1];
    data[border - 1] = sibling_node->data[sibling_node->keys_counter - 1];
    child_node->keys_counter++;
    sibling_node->keys_counter--;
}

void BNode::borrowFromNext(const int border)
{
    BNode *child_node = child[border];
    BNode *sibling_node = child[border + 1];
    child_node->key[child_node->keys_counter] = key[border];
    child_node->data[child_node->keys_counter] = data[border];
    if (child_node->is_leaf == false)
    {
        child_node->child[child_node->keys_counter + 1] = sibling_node->child[0];
    }
    key[border] = sibling_node->key[0];
    data[border] = sibling_node->data[0];
    for (int index = 1; index < sibling_node->keys_counter; index++)
    {
        sibling_node->key[index - 1] = sibling_node->key[index];
        sibling_node->data[index - 1] = sibling_node->data[index];
    }
    if (sibling_node->is_leaf == false)
    {
        for (int index = 1; index < sibling_node->keys_counter; index++)
        {
            sibling_node->child[index - 1] = sibling_node->child[index];
        }
    }
    child_node->keys_counter++;
    sibling_node->keys_counter--;
}

void BNode::merge(const int border)
{
    BNode *child_node = child[border];
    BNode *sibling_node = child[border + 1];
    child_node->key[t / 2 - 1] = key[border];
    child_node->data[t / 2 - 1] = data[border];
    for (int index = 0; index < sibling_node->keys_counter; index++)
    {
        child_node->key[index + t / 2] = sibling_node->key[index];
        child_node->data[index + t / 2] = sibling_node->data[index];
    }
    if (child_node->is_leaf == false)
    {
        for (int index = 0; index < sibling_node->keys_counter; index++)
        {
            child_node->child[index + t / 2] = sibling_node->child[index];
        }
    }
    for (int index = border + 1; index < keys_counter; index++)
    {
        key[index - 1] = key[index];
        data[index - 1] = data[index];
    }
    for (int index = border + 2; index <= keys_counter; index++)
    {
        child[index - 1] = child[index];
    }
    child_node->keys_counter += sibling_node->keys_counter + 1;
    keys_counter--;
    delete(sibling_node);
}

void BTree::deleteData(const int key)
{
    if (root == nullptr)
    {
        cout << "The tree is empty!" << endl;
    }
    else
    {
        root->remove(key);
        if (root->keys_counter == 0)
        {
            BNode *temp = root;
            if (root->is_leaf == true)
            {
                root = nullptr;
            }
            else
            {
                root = root->child[0];
            }
            delete temp;
        }
    }
}

typedef struct Symbol{
    int key;
    char symbol[10];
} Symbol;

int main()
{
    BTree tree = BTree(6);
    Symbol a = {1, "a"};
    Symbol b = {2, "b"};
    Symbol c = {3, "c"};
    Symbol d = {4, "d"};
    Symbol e = {5, "e"};
    Symbol f = {6, "f"};
    Symbol g = {7, "g"};
    Symbol h = {8, "h"};
    tree.addData(d.key, d.symbol);
    tree.addData(g.key, g.symbol);
    tree.addData(a.key, a.symbol);
    tree.addData(b.key, b.symbol);
    tree.addData(e.key, e.symbol);
    tree.addData(h.key, h.symbol);
    tree.addData(c.key, c.symbol);
    tree.printTree();
    tree.addData(f.key, f.symbol);
    tree.deleteData(b.key);
    tree.printTree();
    return 0;
}