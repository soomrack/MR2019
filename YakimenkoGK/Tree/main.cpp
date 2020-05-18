#include <iostream>
#include <algorithm>

class Node {
//Свойтсва класса
public:
    //Ключ узла
    int key;
    //Данные, которые хранит узел
    void* data;
    //Указатели на левого и правого потомка
    Node* left_child;
    Node* right_child;
    //Конструктор узла
    Node (int key, void *data){
        this->key = key;
        this->data = data;
        left_child = nullptr;
        right_child = nullptr;
    };
    //Деструктор узла
    //~Node() = default;
};


class Tree {
//Свойства класса
public:
    //Корень дерева
    Node* root;
    //Конструктор дерева
    Tree() {
        root = nullptr;
    };
    //Деструктор дерева
    //~Tree() = default;
//Методы класса
public:
    //Функция для "подготовки" узла к -
    //добавлению элемента, возвращает указатель
    //на пустую ячейку и ключ
    Node* prepareNewNode(int key, Node* root);
    //Добавление элемента в дерево
    void addData(int key, void* data);
    //Поиск по дереву
    Node* search(int key, Node* root);
    //Удаление элемента
    void deleteNode(int key);
    //Поиск родителя
    Node* searchParent(int key, Node* root);
    //Вспомогательная ф-я:
    //поиск минимального элемента
    Node* findMin(Node* root);
};


Node* Tree::prepareNewNode(int key, Node* root) {
    if (key < root->key) {
        if (root->left_child == nullptr) return(root);
        return(prepareNewNode(key, root->left_child));
    }
    else {
        if (root->right_child == nullptr) return(root);
        return(prepareNewNode(key, root->right_child));
    }
}

void Tree::addData(int key, void* data) {
    Node* child = new Node(key, data);

    if (root == nullptr) {
        root = child;
        return;
    }

    Node* parent = prepareNewNode(key, child);
    if (key < parent->key) parent->left_child = child;
    else parent->right_child = child;
}


Node* Tree::search(int key, Node* root) {
    if (key == root->key) return root;
    if (key < root->key) search(key, root->left_child);
    else search(key, root->right_child);
}

void Tree::deleteNode(int key){
    Node* deleteData = search(key, root);
    if (deleteData == nullptr) return;
    Node* parentDeleteData = searchParent(key, root);

    //Один из потомков пустой
    if ((deleteData->left_child == nullptr) && (deleteData->right_child != nullptr)) {
        if (parentDeleteData->left_child == deleteData) parentDeleteData->left_child = deleteData->right_child;
        else parentDeleteData->right_child = deleteData->right_child;
        return;
    }
    if ((deleteData->left_child != nullptr) && (deleteData->right_child == nullptr)) {
        if (parentDeleteData->left_child == deleteData) parentDeleteData->left_child = deleteData->left_child;
        else parentDeleteData->right_child = deleteData->left_child;
        return;
    }
    //Оба потомка пустые
    if ((deleteData->left_child == nullptr) && (deleteData->right_child == nullptr)) {
        if (parentDeleteData->left_child == deleteData) parentDeleteData->left_child = nullptr;
        else parentDeleteData->right_child = nullptr;
        return;
    }
    //Оба потомка не пустые
    Node* temp = findMin(deleteData->right_child);
    if (temp == deleteData->right_child) {
        deleteData->key = temp->key;
        deleteData->data = temp->data;
        deleteData->right_child = temp->right_child;
        return;
    }
    else {
        deleteData->data = temp->data;
        deleteData->key = temp->key;
        deleteNode(temp->key);
        return;
    }
}

Node* Tree::searchParent(int key, Node *root) {
    if ((key == root->left_child->key) || (key == root->right_child->key)) return root;
    if (key < root->key) searchParent(key, root->left_child);
    else searchParent(key, root->right_child);
}

Node* Tree::findMin(Node *root) {
    Node* min = root;
    while(min->left_child != nullptr) {
        min = min->left_child;
    }
    return min;
}


int main() {
    //Tree test;
    //test.addData(1, nullptr);
    //test.addData(2, nullptr);
    //test.addData(1000, nullptr);
    return 0;
}