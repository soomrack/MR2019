#include <iostream>

using namespace std;

class Node
{
    bool is_leaf;
    int  number_of_keys;
    int  *keys;
    int  t;
    Node **node_children;

public:
    Node (int _t, bool _leaf);
    Node* search(int k);

    void insertNonFull(int k); // to insert a new key in the subtree rooted with non-full node

    void splitChild(int i, Node* y); // to split the full child "y" with index "i" of node

    friend class BTree; //for node_children and number_of_keys later correct work 
};

class BTree
{  
    Node *root;
    int  t;

public:
    BTree(int _t)
    {
        root = NULL;  t = _t;
    }

    Node* search(int k)
    {
        return (root == NULL) ? NULL : root->search(k);
    }

    void insert(int k);
};

Node::Node(int _t, bool _leaf)
{
    // Copy the given minimum degree and is_leaf property 
    t = _t;
    is_leaf = _leaf;

    keys = new int[2 * t - 1];  // Allocate memory for maximum number of possible keys 
    node_children = new Node * [2 * t]; // and child pointers 

    number_of_keys = 0;
}

Node * Node::search(int k)   // to search key "k" in subtree rooted with this node
{
    int i = 0;
    while (i < number_of_keys && k > keys[i])
        i++;

    if (keys[i] == k) return this;

    if (is_leaf == true) return NULL;
        
    return node_children[i]->search(k);
}

void BTree::insert(int k)
{
    if (root == NULL)
    {
        root = new Node(t, true);   // Allocate memory for root
        root->keys[0] = k;          // Insert key 
        root->number_of_keys = 1;   // Update number of keys in root 
    }
   
    else  
    {
        if (root->number_of_keys == 2 * t - 1) // If root is full (tree grows in height)
        { 
            Node* s = new Node(t, false);

            s->node_children[0] = root; // Make old root as child of new root 

            s->splitChild(0, root); // Split the old root and move 1 key to the new root 

            // New root has two children now.  Decide which of the 
            // two children is going to have new key 
            int i = 0;
            if (s->keys[0] < k) i++;
            s->node_children[i]->insertNonFull(k);
            root = s;
        }
        else root->insertNonFull(k);
    }
}

void Node::insertNonFull(int k)
{  
    int i = number_of_keys - 1; //index of the rightest element
 
    if (is_leaf == true)
    {
        while (i >= 0 && keys[i] > k) //to find the location for the new key
        {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        number_of_keys = number_of_keys + 1;
    }
   
    else
    {
        while (i >= 0 && keys[i] > k) i--;
 
        if (node_children[i + 1] -> number_of_keys == 2 * t - 1) //if the found child is full split it
        {
            splitChild(i + 1, node_children[i + 1]);
            if (keys[i + 1] < k) i++;
        }
        node_children[i + 1] -> insertNonFull(k);
    }
}

void Node::splitChild(int i, Node* y)
{
    Node* z = new Node(y->t, y->is_leaf); // Create a new node for (t-1) keys 
    z->number_of_keys = t - 1;

    for (int j = 0; j < t - 1; j++) // Copy the last keys
        z->keys[j] = y->keys[j + t];

    if (y->is_leaf == false) // Copy the last children
    {
        for (int j = 0; j < t; j++)
            z->node_children[j] = y->node_children[j + t];
    }

    y->number_of_keys = t - 1; // Reduce the number of keys in y 

    for (int j = number_of_keys; j >= i + 1; j--)
        node_children[j + 1] = node_children[j];

    node_children[i + 1] = z; // Link the new child to this node 

    for (int j = number_of_keys - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1]; // Copy the middle key of y to this node 

    number_of_keys = number_of_keys + 1;// Increment count of keys in this node 
}