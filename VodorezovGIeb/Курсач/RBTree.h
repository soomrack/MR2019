#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

enum Color { RED, BLACK, DOUBLE_BLACK };

struct Node
{
    int data;
    int color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data);
};

class RBTree
{
protected:
    void rotateLeft(Node*&);
    void rotateRight(Node*&);
    void fixInsertRBTree(Node*&);
    void fixDeleteRBTree(Node*&);
    int getColor(Node*&);
    void setColor(Node*&, int);
    Node* minValueNode(Node*&);
    Node* maxValueNode(Node*&);
    Node* insertBST(Node*&, Node*&);
    Node* deleteBST(Node*&, int);
    int getBlackHeight(Node*);
public:
    Node* root;
    RBTree();
    void insertValue(int);
    void deleteValue(int);
    void printDepth(Node* root);
    void printBreadth();

};


#endif //RED_BLACK_TREE_RBTREE_H
