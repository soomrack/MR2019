#ifndef BTREE_TREE_H
#define BTREE_TREE_H

const int t = 2;
struct Node {
    int keys[2 * t];
    Node *children[2 * t + 1];
    Node *parent;
    int countKeys;
    int countSons;
    bool leaf;
};

class Tree {
private:
    Node *root;

    void insert_to_node(int key, Node *node);

    void sort(Node *node);

    void restruct(Node *node);

    void deletenode(Node *node);

    bool searchKey(int key, Node *node);

    void remove(int key, Node *node);

    void removeFromNode(int key, Node *node);

    void removeLeaf(int key, Node *node);

    void lconnect(Node *node, Node *othernode);

    void rconnect(Node *node, Node *othernode);

    void repair(Node *node);

public:
    Tree();

    ~Tree();

    void insert(int key);

    bool search(int key);

    void remove(int key);
};


#endif //BTREE_TREE_H
