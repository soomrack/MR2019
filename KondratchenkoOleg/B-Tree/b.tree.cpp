#include <iostream>
using namespace std;

// Степень дерева
#define degree 2

class BNode
{
public:
    int keys[2*degree - 1];
    BNode* child[2*degree];
    int amountOfKeys;
public:
    // Конструктор
    BNode(int key);
    // Деструктор
    ~BNode();
};

BNode::BNode(int key)
{
    this->keys[0] = key;
    for (int i = 1; i < (2*degree-1); i++)
    {
        this->keys[i] = 0;
    }
    for (int i = 0; i < (2*degree); i++)
    {
        this->child[i] = nullptr;
    }
    this->amountOfKeys = 1;
}

class BTree
{
public: 
    BNode* root;
public:
    void addData(int key);
    void deleteData(int key);
    void printTreeSorted(BNode* root);
    BNode* searchNode(BNode* root, int key);
public:
    // Конструктор
    BTree();
private:
    void insertIntoNode(BNode* node, int key);
    void sortNode(BNode* node);
    void rebuildNode(BNode* node);
    void setNewChlild_ForNode(BNode* First, BNode* Second, BNode* node);
private:
    BNode* searchList(int key);
    BNode* searchParent(BNode* node, BNode* root);
};

BTree::BTree()
{
    root = nullptr;
}

void BTree::addData(const int key)
{
    if (root != nullptr)
    {
        BNode* temp = searchList(key);
        insertIntoNode(temp, key);
        BNode* parent = searchParent(temp, root);
        while (temp->amountOfKeys >= (2 * degree - 1))
        {
            if (temp == root)
            {
                rebuildNode(temp);
            }
            else
            {
                rebuildNode(temp);
                temp = parent;
            }
        }
    }
    else
    {
        root = new BNode(key);
        return;
    }
}

void BTree::deleteData(int key)
{
    BNode* deletedNode = searchNode(root, key);
    if ((deletedNode->child[0] == nullptr) && (deletedNode->amountOfKeys == degree))
    {
        for (int i = 0; i < (deletedNode->amountOfKeys); i++)
        {
            if (deletedNode->keys[i] == key)
            {
                for (int j = i; j < (deletedNode->amountOfKeys); j++)
                {
                    deletedNode->keys[j] = deletedNode->keys[j + 1];
                }
                deletedNode->amountOfKeys = deletedNode->amountOfKeys - 1;
            }
        }
    }
}

void BTree::printTreeSorted(BNode* root)
{
    if (root != nullptr)
    {
        for (int i = 0; i < (2 * degree - 1); i++)
        {
            if (root->amountOfKeys >= i)
            {
                cout << root->keys[i] << " ";
            }
        }
        cout << '\n';
        for (int i = 0; i < (2 * degree); i++)
        {
            if (root->child[i] != nullptr)
            {
                printTreeSorted(root->child[i]);
            }
        }
        cout << '\n';
    }
}

BNode* BTree::searchNode(BNode* root, int key)
{
    if (root != nullptr)
    {
        for (int i = 0; i < (root->amountOfKeys); i++)
        {
            if (root->keys[i] == key)
            {
                return root;
            }
            if (key < root->keys[i])
            {
                return searchNode(root->child[i], key);
            }
            if ((key > root->keys[i]) && (root->amountOfKeys == (i + 1)))
            {
                return searchNode(root->child[i + 1], key);
            }
        }
    }
}

void BTree::insertIntoNode(BNode* node, int key)
{
    node->keys[node->amountOfKeys] = key;
    node->amountOfKeys = node->amountOfKeys + 1;
    sortNode(node);
}

BNode* BTree::searchParent(BNode* node, BNode* root)
{
    for (int i = 0; i < (2 * degree); i++)
    {
        if (root->child[i] == node)
        {
            return root;
        }
        if (root->child[i] != nullptr)
        {
            searchParent(node, root->child[i]);
        }
    }
}

BNode* BTree::searchList(int key)
{
    BNode* temp = root;
    while (temp->child[0] != nullptr)
    {
        for (int i = 0; i < (2 * degree - 1); i++)
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
            else break;
        }
    }
    return temp;
}

void BTree::sortNode(BNode* node)
{
    int swap;
    for (int i = 0; i < (2 * degree - 1); i++)
    {
        for (int j = i + 1; j <= (2 * degree - 1); j++)
        {
            if ((node->keys[i] != 0) && (node->keys[j] != 0))
            {
                if ((node->keys[i]) > (node->keys[j]))
                {
                    swap = node->keys[i];
                    node->keys[i] = node->keys[j];
                    node->keys[j] = swap;
                }
            }
            else break;
        }
    }
}

void BTree::setNewChlild_ForNode(BNode* First, BNode* Second, BNode* node)
{
    for (int i = 0; i < (degree - 1); i++)
    {
        First->keys[i]  = node->keys[i];
        Second->keys[i] = node->keys[i + degree];
    }
    First->amountOfKeys  = degree - 1;
    Second->amountOfKeys = degree - 1;
    if (node->child[0] != nullptr)
    {
        for (int i = 0; i <= (degree - 1); i++)
        {
            First->child[i]  = node->child[i];
            Second->child[i] = node->child[i + degree];
        }
    }
}

void BTree::rebuildNode(BNode* node)
{
    BNode* FirstChild = new BNode(0);
    FirstChild->amountOfKeys = 0;

    BNode* SecondChild = new BNode(0);
    SecondChild->amountOfKeys = 0;

    setNewChlild_ForNode(FirstChild, SecondChild, node);
    if (node == root)
    {
        node->keys[0] = node->keys[degree - 1];
        for (int i = 1; i < (2 * degree - 1); i++)
        {
            node->keys[i] = 0;
        }
        node->amountOfKeys = 1;
        node->child[0] = FirstChild;
        node->child[1] = SecondChild;

        for (int i = 2; i < (2 * degree); i++)
        {
            node->child[i] = nullptr;
        }
    }
    else
    {
        BNode* parent_node = searchParent(node, root);
        insertIntoNode(parent_node, node->keys[degree - 1]);

        for (int i = 0; i < (2 * degree); i++)
        {
            if (parent_node->child[i] == node)
            {
                parent_node->child[i] = nullptr;
            }
            if (parent_node->child[i] == nullptr)
            {
                for (int j = (2 * degree - 1); j > (i + 1); j--)
                {
                    parent_node->child[j] = parent_node->child[j - 1];
                }
                parent_node->child[i] = FirstChild;
                parent_node->child[i + 1] = SecondChild;
                break;
            }
        }
    }
}

int main()
{
    BTree BtreeTest = BTree();
    BtreeTest.addData(3);
    BtreeTest.addData(4);
    BtreeTest.addData(12);
    BtreeTest.printTreeSorted(BtreeTest.root);
    BtreeTest.addData(19);
    BtreeTest.printTreeSorted(BtreeTest.root);
    BtreeTest.addData(3);
    BtreeTest.printTreeSorted(BtreeTest.root);
    BtreeTest.addData(70);
    BtreeTest.printTreeSorted(BtreeTest.root);
    BtreeTest.deleteData(6);
    BtreeTest.printTreeSorted(BtreeTest.root);
    BtreeTest.addData(22);
    BtreeTest.printTreeSorted(BtreeTest.root);
    return 0;
}