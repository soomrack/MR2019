#include <iostream>
using namespace std;

class Node
{
    int* keys;
    Node** children;
    int curr_num;
    int t;
    bool leaf;
public:
    Node(int t, bool leaf);

    void Bypass();

    Node* Search(int key);
    int FindKey(int key);
    void InsertPartial(int key);
    void splitChild(int i, Node* y);
    void Delete(int key);
    void DeleteLeafKey(int index);
    void DeleteNonLeafKey(int index);
    int GettingPred(int index);
    int GettingSuccessor(int index);
    void Filling(int index);
    void TakePrevious(int index);
    void TakeFollowing(int index);
    void Merge(int index);
    friend class BTree;
};

class BTree 
{
    Node* root;
    int t;

public:
    BTree(int t) 
    {
        root = nullptr;
        this->t = t;
    }

    void Bypass()
    {
        if (root != nullptr)
        {
            root->Bypass();
        }
    }

    Node* Search(int key) 
    {
        return (root == nullptr) ? nullptr : root->Search(key);
    }

    void Insert(int key);

    void Delete(int key);
};

Node::Node(int t, bool leaf)
{
    this->t = t;
    this->leaf = leaf;

    keys = new int[2 * t - 1];
    children = new Node * [2 * t];

    curr_num = 0;
}

void BTree::Insert(int key)
{
    if (root == nullptr)
    {
        root = new Node(t, true);
        root->keys[0] = key;
        root->curr_num = 1;
    }
    else
    {
        if (root->curr_num == 2 * t - 1)
        {
            Node* s = new Node(t, false);

            s->children[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < key)
            {
                i++;
            }
            s->children[i]->InsertPartial(key);

            root = s;
        }
        else
            root->InsertPartial(key);
    }
}

Node* Node::Search(int key)
{
    int i = 0;
    while (i < curr_num && key > keys[i])
        i++;

    if (keys[i] == key)
    {
        return this;
    }

    if (leaf == true)
    {
        return nullptr;
    }

    return children[i]->Search(key);
}

void BTree::Delete(int key)
{
    if (!root)
    {
        cout << "The tree is empty" << endl;
        return;
    }

    root->Delete(key);

    if (root->curr_num == 0)
    {
        Node* tmp = root;
        if (root->leaf)
        {
            root = nullptr;
        }
        else
            root = root->children[0];

        delete tmp;
    }
    return;
}

void Node::InsertPartial(int key)
{
    int i = curr_num - 1;

    if (leaf == true)
    {
        while (i >= 0 && keys[i] > key)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = key;
        curr_num = curr_num + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > key)
            i--;

        if (children[i + 1]->curr_num == 2 * t - 1)
        {
            splitChild(i + 1, children[i + 1]);

            if (keys[i + 1] < key)
            {
                i++;
            }
        }
        children[i + 1]->InsertPartial(key);
    }
}

void Node::Bypass()
{
    int i;
    for (i = 0; i < curr_num; i++)
    {
        if (leaf == false)
        {
            children[i]->Bypass();
        }
        cout << " " << keys[i];
    }

    if (leaf == false)
    {
        children[i]->Bypass();
    }
}

int Node::FindKey(int key)
{
    int index = 0;
    while (index < curr_num && keys[index] < key)
        ++index;
    return index;
}

void Node::Delete(int key)
{
    int index = FindKey(key);

    if (index < curr_num && keys[index] == key)
    {
        if (leaf)
        {
            DeleteLeafKey(index);
        }
        else
            DeleteNonLeafKey(index);
    }
    else 
    {
        if (leaf) 
        {
            cout << "The key " << key << " is does not exist in the tree" << endl;
            return;
        }

        bool flag = ((index == curr_num) ? true : false);

        if (children[index]->curr_num < t)
        {
            Filling(index);
        }

        if (flag && index > curr_num)
        {
            children[index - 1]->Delete(key);
        }
        else
            children[index]->Delete(key);
    }
    return;
}

void Node::DeleteLeafKey(int index)
{
    for (int i = index + 1; i < curr_num; ++i)
    {
        keys[i - 1] = keys[i];
    }
    curr_num--;

    return;
}

void Node::DeleteNonLeafKey(int index) 
{
    int key = keys[index];

    if (children[index]->curr_num >= t) 
    {
        int pred = GettingPred(index);
        keys[index] = pred;
        children[index]->Delete(pred);
    }

    else if (children[index + 1]->curr_num >= t) 
    {
        int succ = GettingSuccessor(index);
        keys[index] = succ;
        children[index + 1]->Delete(succ);
    }

    else
    {
        Merge(index);
        children[index]->Delete(key);
    }
    return;
}

int Node::GettingPred(int index)
{
    Node* cur = children[index];
    while (!cur->leaf)
        cur = cur->children[cur->curr_num];

    return cur->keys[cur->curr_num - 1];
}

int Node::GettingSuccessor(int index)
{
    Node* cur = children[index + 1];
    while (!cur->leaf)
        cur = cur->children[0];

    return cur->keys[0];
}

void Node::Filling(int index)
{
    if (index != 0 && children[index - 1]->curr_num >= t)
    {
        TakePrevious(index);
    }

    else if (index != curr_num && children[index + 1]->curr_num >= t)
    {
        TakeFollowing(index);
    }

    else 
    {
        if (index != curr_num)
        {
            Merge(index);
        }
        else
            Merge(index - 1);
    }
    return;
}
void Node::Merge(int index)
{
    Node* child = children[index];
    Node* neighbor = children[index + 1];

    child->keys[t - 1] = keys[index];

    for (int i = 0; i < neighbor->curr_num; ++i)
    {
        child->keys[i + t] = neighbor->keys[i];
    }

    if (!child->leaf)
    {
        for (int i = 0; i <= neighbor->curr_num; ++i)
        {
            child->children[i + t] = neighbor->children[i];
        }
    }

    for (int i = index + 1; i < curr_num; ++i)
    {
        keys[i - 1] = keys[i];
    }

    for (int i = index + 2; i <= curr_num; ++i)
    {
        children[i - 1] = children[i];
    }

    child->curr_num += neighbor->curr_num + 1;
    curr_num--;

    delete (neighbor);
    return;
}

void Node::TakePrevious(int index)
{
    Node* child = children[index];
    Node* neighbor = children[index - 1];

    for (int i = child->curr_num - 1; i >= 0; --i)
    {
        child->keys[i + 1] = child->keys[i];
    }
    if (!child->leaf)
    {
        for (int i = child->curr_num; i >= 0; --i)
        {
            child->children[i + 1] = child->children[i];
        }
    }

    child->keys[0] = keys[index - 1];

    if (!child->leaf)
    {
        child->children[0] = neighbor->children[neighbor->curr_num];
    }

    keys[index - 1] = neighbor->keys[neighbor->curr_num - 1];

    child->curr_num += 1;
    neighbor->curr_num -= 1;

    return;
}

void Node::TakeFollowing(int index)
{
    Node* child = children[index];
    Node* neighbor = children[index + 1];

    child->keys[(child->curr_num)] = keys[index];

    if (!(child->leaf))
    {
        child->children[(child->curr_num) + 1] = neighbor->children[0];
    }

    keys[index] = neighbor->keys[0];

    for (int i = 1; i < neighbor->curr_num; ++i)
    {
        neighbor->keys[i - 1] = neighbor->keys[i];
    }

    if (!neighbor->leaf)
    {
        for (int i = 1; i <= neighbor->curr_num; ++i)
        {
            neighbor->children[i - 1] = neighbor->children[i];
        }
    }

    child->curr_num += 1;
    neighbor->curr_num -= 1;

    return;
}

void Node::splitChild(int i, Node* y)
{
    Node* z = new Node(y->t, y->leaf);
    z->curr_num = t - 1;

    for (int j = 0; j < t - 1; j++)
    {
        z->keys[j] = y->keys[j + t];
    }

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
        {
            z->children[j] = y->children[j + t];
        }
    }

    y->curr_num = t - 1;

    for (int j = curr_num; j >= i + 1; j--)
    {
        children[j + 1] = children[j];
    }

    children[i + 1] = z;

    for (int j = curr_num - 1; j >= i; j--)
    {
        keys[j + 1] = keys[j];
    }

    keys[i] = y->keys[t - 1];

    curr_num = curr_num + 1;
}

int main() {
    BTree MyTree(3);
    MyTree.Insert(95);
    MyTree.Insert(55);
    MyTree.Insert(89);
    MyTree.Insert(60);
    MyTree.Insert(78);
    MyTree.Insert(12);

    cout << "The B-tree is: ";
    MyTree.Bypass();
    cout << endl;

    int key = 78;
    (MyTree.Search(key) != nullptr) ? cout << endl
        << key << " is found" << endl
        : cout << endl
        << key << " is not Found" << endl;

    key = 15;
    (MyTree.Search(key) != nullptr) ? cout << endl
        << key << " is found" << endl
        : cout << endl
        << key << " is not Found" << endl;

    MyTree.Delete(12);

    cout << "\nThe B-tree after deletion is: ";
    MyTree.Bypass();
    cout << endl;
}
