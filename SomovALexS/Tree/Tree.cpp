#include "Tree.h"

class Tree {
public:
    //Конструктор по умолчанию, создаёт пустое дерево
    Tree() : root_(nullptr) {}

    // Деструктор освобождает память, занятую узлами дерева
    virtual ~Tree() {
        deleteSubtree(root_);
    }

private:
    //писание структуры узла с сылками на детей
    struct Node {
        int key_;        // значение ключа, содержащееся в узле
        Node *left_;    // указатель на левое поддерево
        Node *right_;   // указатель на правое поддерево
        Node *p_;       // указатель на  родителя
        void *data;

        //Конструктор узла
        Node(const int key, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr, void *data = nullptr) :
                key_(key), left_(left), right_(right), p_(p) {}

        ~Node() = default;
    };

    Node *root_;

    void deleteSubtree(Node *node) {
        if (node == nullptr) {
            return;
        }
        deleteSubtree(node->left_);
        deleteSubtree(node->right_);
        delete (node);
    }

    //функция поиска адреса узла по ключу
    Node *searchNode(const int key) {
        Node *curr = root_;
        while (curr != nullptr) {
            if (curr->key_ == key) {
                return curr;
            } else if (curr->key_ < key) {
                curr = curr->left_;
            } else {
                curr = curr->right_;
            }
        }
        return curr;
    }

    //функция вставки нового элемента в лист
    void insert(const int key) {
        if (root_ == nullptr) {
            root_ = new Node(key, nullptr, nullptr, nullptr);
            return;
        }
        Node *curr = root_;
        while (curr->key_) {
            if (curr->key_ < key) {
                if (curr->left_ == nullptr) {
                    curr->left_ = new Node(key, nullptr, nullptr, curr);
                    return;
                } else {
                    curr = curr->left_;
                }
            } else {
                if (curr->right_ == nullptr) {
                    curr->right_ = new Node(key, nullptr, nullptr, curr);
                    return;
                } else {
                    curr = curr->right_;
                }
            }
        }
        throw "Just exist";
    }

    void deleteKey(const int key) {
        Node *curr = searchNode(key);
        if (curr == nullptr) {
            throw "This key doesnt exist!";
        }
        if ((curr->left_ == nullptr) && (curr->right_ == nullptr)) {
            Node *parent = curr->p_;
            if (parent == nullptr) {
                root_ = nullptr;
            } else if (parent->key_ < curr->key_) {
                parent->right_ = nullptr;
            } else {
                parent->left_ = nullptr;
            }
            delete curr;
        } else if (curr->left_ == nullptr || curr->right_ == nullptr){
            Node *child = nullptr;
            (curr->left_ != nullptr) ? child = curr->left_ : child = curr->right_;
            Node *parent  = curr->p_;

        }
    }

};



