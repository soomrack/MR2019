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

    void* search(int key);                  // ����� �� �����
    void delete_key(int key);               // ����� �������� �� �����  
    void print();                           // ����� + ����� � �������
    void shift_right(unsigned M);                     // �������� ������ �� ���� ������
    bool can_push(unsigned M);                        // ����� ��������� ����� �� �������� ���� � ����  
    B_Node* split(unsigned M);                        // ����� ��������� ���� 
    std::pair<B_Node*, B_Node*> find_neighbours(B_Node* parent); // ����� �������. ���� �� ����������� ������������

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

    int add_data(int key, void* data = nullptr);    // ����� ���������� ������ ����� � ������   
    void print();                                   // ����� ������ �� �����   
    void* search(int key);                          // ����� �������� �� �����
    int delete_data(int key);                       // �������� ��������

    friend class BTreePrinter;
private:
    B_Node* root;
    

    int add_data(int key, B_Node* root, void* data = nullptr);                                  // ��������������� ����� ��� ��������
    bool lift_flag{ 0 };                                                                        // ���� ��� ����� ������ �����
    int lift_node(B_Node* node, B_Node* root);                                                  // �����, ����������� �������� ���� �� ������� ����
    int insert_key(B_Node* node, std::pair<int, void*> key);                                    // �������� ���� � ����
    int insert_node(B_Node* node, B_Node* root);                                                // �������� ���� ���� � ������
    void restruct_nodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour);                // ����� ������������ ������ ����� ������ ���������. � �������  ���� �������� ����
    int merge_nodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour, int key);           // ������� �������� �����
    B_Node* merge_children(B_Node* currentNode, B_Node* childL, B_Node* childR, size_t indx);   // ������� ����� ��������
    int delete_data(int key, B_Node* node, B_Node* parent);                                     // ��������������� ����� ��������
    void rebalance(int key, B_Node* currentNode, B_Node* parent);                               // �������� ������. �������������� �� ���������� ������

};

