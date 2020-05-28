#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
    struct Node
    {
        int key;
        Node* left;
        Node* right;
    };
    Node* root;
    void AddNodePrivate(int key, Node* Ptr);
    void RemoveNodePrivate(int key, Node* parent);
    Node* CreateNode(int key);
    Node* ReturnNode(int key);
    Node* ReturnNodePrivate(int key, Node* Ptr);
    int FindSmallestPrivate(Node* Ptr);
    void RemoveRootMatch();
    void RemoveMatch(Node* parent, Node* match, bool left);
    void RemoveSubTree(Node* Ptr);
    void PrintInOrderPrivate(Node* Ptr);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void AddNode(int key);
    void RemoveNode(int key);
    int ReturnRootKey();
    int FindSmallest();
    void PrintChildren(int key);
    void PrintInOrder();
};

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::Node* BinarySearchTree::CreateNode(int key)
{
    Node* n = new Node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void BinarySearchTree::AddNode(int key)
{
    AddNodePrivate(key, root);
}

void BinarySearchTree::AddNodePrivate(int key, Node* Ptr)
{
    if (root == nullptr)
    {
        root = CreateNode(key);
    }
    else if (key < Ptr->key)
    {
        if (Ptr->left != nullptr)
        {
            AddNodePrivate(key, Ptr->left);
        }
        else
        {
            Ptr->left = CreateNode(key);
        }
    }
    else if (key > Ptr->key)
    {
        if (Ptr->right != nullptr)
        {
            AddNodePrivate(key, Ptr->right);
        }
        else
        {
            Ptr->right = CreateNode(key);
        }
    }
    else
    {
        cout << "The key " << key << " has already been added to the tree\n ";
    }
}

void BinarySearchTree::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BinarySearchTree::PrintInOrderPrivate(Node* Ptr)
{
    if (root != nullptr)
    {
        if (Ptr->left != nullptr)
        {
            PrintInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << " ";
        if (Ptr->right != nullptr)
        {
            PrintInOrderPrivate(Ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty\n";
    }
}

BinarySearchTree::Node* BinarySearchTree::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BinarySearchTree::Node* BinarySearchTree::ReturnNodePrivate(int key, Node* Ptr)
{
    if (Ptr != nullptr)
    {
        if (Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if (key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        return nullptr;
    }
}

int BinarySearchTree::ReturnRootKey()
{
    if (root != nullptr)
    {
        return root->key;
    }
    else
    {
        return -10000;
    }
}

void BinarySearchTree::PrintChildren(int key)
{
    Node* Ptr = ReturnNode(key);

    if (Ptr != nullptr)
    {
        cout << "Parent Node = " << Ptr->key << endl;

        Ptr->left == nullptr ?
            cout << "Left Child = nothing\n" :
            cout << "Left Child = " << Ptr->left->key << endl;

        Ptr->right == nullptr ?
            cout << "Right Child = nothing\n" :
            cout << "Right Child = " << Ptr->right->key << endl;
    }
    else
    {
        cout << "Key " << key << " is not in the tree\n";
    }
}

void BinarySearchTree::RemoveMatch(Node* parent, Node* match, bool left)
{
    if (root != nullptr)
    {
        Node* delPtr;
        int matchKey = match->key;
        int smallestInRightSubtree;
        // 0 потомков
        if (match->left == nullptr && match->right == nullptr)
        {
            delPtr = match;
            left == true ? parent->left = nullptr : parent->right = nullptr;
            delete delPtr;
            cout << "The Node containing key " << matchKey << " was removed\n";
        }
        // 1 потомок
        else if (match->left == nullptr && match->right != nullptr)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = nullptr;
            delPtr = match;
            delete delPtr;
            cout << "The Node containing key " << matchKey << " was removed\n";
        }
        else if (match->left != nullptr && match->right == nullptr)
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = nullptr;
            delPtr = match;
            delete delPtr;
            cout << "The Node containing key " << matchKey << " was removed\n";
        }
        // 2 потомка
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        cout << "Can not remove match. The tree is empty\n";
    }
}

int BinarySearchTree::FindSmallest()
{
    return FindSmallestPrivate(root);
}

int BinarySearchTree::FindSmallestPrivate(Node* Ptr)
{
    if (root == nullptr)
    {
        cout << "The tree is empty\n";
        return -1000;
    }
    else
    {
        if (Ptr->left != nullptr)
        {
            return FindSmallestPrivate(Ptr->left);
        }
        else
        {
            return Ptr->key;
        }
    }
}

void BinarySearchTree::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}

void BinarySearchTree::RemoveNodePrivate(int key, Node* parent)
{
    if (root != nullptr)
    {
        if (root->key == key)
        {
            RemoveRootMatch();
        }
        else
        {
            if (key < parent->key && parent->left != nullptr)
            {
                parent->left->key == key ?
                    RemoveMatch(parent, parent->left, true) :
                    RemoveNodePrivate(key, parent->left);
            }
            else if (key > parent->key && parent->right != nullptr)
            {
                parent->right->key == key ?
                    RemoveMatch(parent, parent->right, false) :
                    RemoveNodePrivate(key, parent->right);
            }
            else
            {
                cout << "The key " << key << " is not in the tree!\n";
            }
        }
    }
    else
    {
        cout << "The tree is empty\n";
    }
}

void BinarySearchTree::RemoveRootMatch()
{
    if (root != nullptr)
    {
        Node* delPtr = root;
        int rootKey = root->key;
        int smallestInRightSubtree;
        // 0 потомков
        if (root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
            delete delPtr;
        }
        // 1 потомок
        else if (root->left == nullptr && root->right != nullptr)
        {
            root = root->right;
            delPtr->right = nullptr;
            delete delPtr;
            cout << "The root Node with key " << rootKey << " was deleted. " <<
                "The new root contains key " << root->key << endl;
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            root = root->left;
            delPtr->left = nullptr;
            delete delPtr;
            cout << "The root Node with key " << rootKey << " was deleted. " <<
                "The new root contains key " << root->key << endl;
        }
        // 2 потомка
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root);
            root->key = smallestInRightSubtree;
            cout << "The root key containing key " << rootKey << " was overwritten with key " << root->key << endl;
        }
    }
    else
    {
        cout << "Can't remove root. The tree is empty\n";
    }
}

BinarySearchTree::~BinarySearchTree()
{
    RemoveSubTree(root);
}

void BinarySearchTree::RemoveSubTree(Node* Ptr)
{
    if (Ptr != nullptr)
    {
        if (Ptr->left != nullptr)
        {
            RemoveSubTree(Ptr->left);
        }
        if (Ptr->right != nullptr)
        {
            RemoveSubTree(Ptr->right);
        }
        cout << "Deleting the Node containing the key " << Ptr->key << endl;
        delete Ptr;
    }
}

int main()
{
    int NumberTree[16] = { 18, 55, 59, 23, 9, 8, 16, 75, 101, 106, 45, 5, 87, 12, 66, 98 };
    BinarySearchTree MyBinaryTree;

    cout << "Printing the tree in order before adding numbers" << endl << endl;

    MyBinaryTree.PrintInOrder();
    cout << endl;

    for (int i = 0; i < 16; i++)
    {
        MyBinaryTree.AddNode(NumberTree[i]);
    }

    MyBinaryTree.AddNode(123);

    cout << "Printing the tree in order after adding numbers" << endl << endl;

    MyBinaryTree.PrintInOrder();
    cout << endl << endl;

    for (int i = 0; i < 16; i++)
    {
        MyBinaryTree.PrintChildren(NumberTree[i]);
        cout << endl;
    }

    cout << "The smallest number in the tree is " << MyBinaryTree.FindSmallest();
    cout << endl;

    int input = 0;
    while (input != -1)
    {
        cout << "Delete Node: ";
        cin >> input;
        {
            if (input != -1)
            {
                cout << endl;
                MyBinaryTree.RemoveNode(input);
                MyBinaryTree.PrintInOrder();
                cout << endl;
            }
        }
    }




    return 0;

}
