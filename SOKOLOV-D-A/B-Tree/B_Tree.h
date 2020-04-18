#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iterator>
#define MIN_SIZE ((M-1)/2)

class B_Node
{
public:
    B_Node(int key = 0, void* data = nullptr);
    ~B_Node() {}

    void* search(int key);                  // поиск по ключу
    void delete_key(int key);               // метод удаления из листа  
    void print();                           // обход + вывод в консоль
    void shift_right(unsigned M);                     // смещение ключей на один вправо
    bool can_push(unsigned M);                        // метод проверяет можно ли добавить ключ в узел  
    B_Node* split(unsigned M);                        // метод разделяет узел 
    std::pair<B_Node*, B_Node*> find_neighbours(B_Node* parent); // поиск соседей. Есть ли возможность объединиться

    friend class B_Tree;
    friend class BTreePrinter;
private:
    std::vector <B_Node*> children;
    std::vector < std::pair<int, void*>> key;
};


class B_Tree
{
public:
    B_Tree(int M)
        : M(M)
        , root(nullptr) {}
    ~B_Tree() {}

    const unsigned M;

    int add_data(int key, void* data = nullptr);    // метод добавления нового ключа в дерево   
    void print();                                   // вывод дерева на экран   
    void* search(int key);                          // поиск элемента по ключу
    int delete_data(int key);                       // удаление элемента

    friend class BTreePrinter;
private:
    B_Node* root;
    

    int add_data(int key, B_Node* root, void* data = nullptr);                                  // вспомогательный метод для рекурсии
    bool lift_flag{ 0 };                                                                        // флаг для роста дерева вверх
    int lift_node(B_Node* node, B_Node* root);                                                  // метод, реализующий поднятие узла на уровень выше
    int insert_key(B_Node* node, std::pair<int, void*> key);                                    // вставить ключ в узел
    int insert_node(B_Node* node, B_Node* root);                                                // вставить один узел в другой
    void restruct_nodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour);                // метод осуществляет замену ключа нужным значением. а искомый  ключ опускает ниже
    int merge_nodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour, int key);           // слияние соседних узлов
    B_Node* merge_children(B_Node* currentNode, B_Node* childL, B_Node* childR, size_t indx);   // слияние детей родителя
    int delete_data(int key, B_Node* node, B_Node* parent);                                     // вспомогательный метод удаления
    void rebalance(int key, B_Node* currentNode, B_Node* parent);                               // ребаланс дерева. предостерегает от недостатка ключей

};

