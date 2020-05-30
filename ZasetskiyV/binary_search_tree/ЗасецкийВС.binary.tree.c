#include <iostream>
#include <queue>

//Класс узла:
class Node
{
public:
    int key;
    void * data;
    Node * left_child;
    Node * right_child;
public:
    Node(int key, void * data)
    {
        left_child = nullptr;
        right_child = nullptr;
        this->key = key;
        this->data = data;
    }
    ~Node() {}

    friend class Tree;

private:
    void print_node_sorted();
    void print_depth();


};

//Класс дерева:
class Tree
{
private:
    Node *root;
private:
    Node * find_node_to_insert(Node * node, int key);
    Node * find_deleted_node(Node * node_to_delete, int key);
    Node * find_node(Node * node, int key);
    Node * find_parent_of_deleted_node(Node * node_child, Node * node_parent, int key);
    void delete_leaf(Node * node_to_delete, Node * parent);
    void delete_node(Node * node_to_delete);
    Node * find_successor_parent(Node * parent, Node * child);
    void transfer_data(Node * node_from, Node * node_to);
public:
    Tree()
    {
        root = nullptr;
    }

    ~Tree() {}
    int add_data(int key, void * data);
    Node * search(int key);
    int delete_data(int key);
    void print_sorted();
    void traverse_width(); //обход в ширину
    void traverse_depth(); //обход в глубину

    friend class Node;
};


Node * Tree::find_node_to_insert(Node * node, int key)
{
    if (key <= node->key)
    {
        if (node->left_child != nullptr)
            return this->find_node_to_insert(node->left_child, key);
        else
            return node;
    }
    else
    {
        if (node->right_child != nullptr)
            return this->find_node_to_insert(node->right_child, key);
        else
            return node;
    }
}



int Tree::add_data(int key, void * data)
{
    Node * child = new Node(key, data);
    if (this->root == nullptr)
    {
        this->root = child;
        return 0;
    }
    Node * parent = this->find_node_to_insert(root, key);
    if (key <= parent->key)
        parent->left_child = child;
    else
        parent->right_child = child;
    return 0;
}

Node * Tree::find_node(Node * node, int key)
{
    if (node == nullptr)
        return nullptr;
    if (node->key == key)
        return node;
    if (key < node->key)
        return this->find_node(node->left_child, key);
    return this->find_node(node->right_child, key);
}

Node * Tree::search(int key)
{
    if (this->root->key == key)
        return this->root;
    Node * node_search;
    if (key < this->root->key)
        node_search = this->find_node(root->left_child, key);
    else
        node_search = this->find_node(root->right_child, key);
    if (node_search == nullptr)
    {
        std::cout << "The data is missing\n";
        return nullptr;
    }
    return node_search;
}


Node * Tree::find_parent_of_deleted_node(Node * node_child, Node * node_parent, int key)
{
    if (node_child == nullptr)
    {
        return nullptr;
    }
    if (node_child->key == key)
    {
        return node_parent;
    }
    if (key <= node_child->key)
        return this->find_parent_of_deleted_node(node_child->left_child, node_child, key);
    else
        return this->find_parent_of_deleted_node(node_child->right_child, node_child, key);
}

Node * Tree::find_deleted_node(Node * node_to_delete, int key)
{
    if (node_to_delete == nullptr)
    {
        return nullptr;
    }
    if (node_to_delete->key == key)
    {
        return node_to_delete;
    }
    if (key <= node_to_delete->key)
        return this->find_deleted_node(node_to_delete->left_child, key);
    else
        return this->find_deleted_node(node_to_delete->right_child, key);
}

void Tree::transfer_data(Node * node_from, Node * node_to)
{
    node_to->data = node_from->data;
    node_to->key = node_from->key;
    node_to->right_child = node_from->right_child;
    node_to->left_child = node_from->left_child;
}

Node * Tree::find_successor_parent(Node * parent, Node * child)
{
    if (child->left_child == nullptr)
        return parent;
    return this->find_successor_parent(child, child->left_child);
}

void Tree::delete_leaf(Node * node_to_delete, Node * parent)
{
    if (parent->left_child != nullptr)
    {
        if (parent->left_child->key == node_to_delete->key)
            parent->left_child = nullptr;
    }
    else
        parent->right_child = nullptr;
    delete node_to_delete;
}

void Tree::delete_node(Node * node_to_delete)
{
    //если есть только правый потомок
    if (node_to_delete->left_child == nullptr && node_to_delete->right_child != nullptr)
    {
        Node * child = node_to_delete->right_child;
        //переносим данные из потомка в родителя и освобождаем память от потомка
        this->transfer_data(child, node_to_delete);
        delete child;
        return;
    }
    //если есть только левый потомок
    else if (node_to_delete->right_child == nullptr && node_to_delete->left_child != nullptr)
    {
        Node * child = node_to_delete->left_child;
        //переносим данные из потомка в родителя и освобождаем память от потомка
        this->transfer_data(child, node_to_delete);
        delete child;
        return;
    }
    //если есть оба потомка
    //ищем наименьший элемент в правой части дерева
    //если правый потомок - наименьший элемент, переносим его данные, ключ и правого потомка в удаляемый узел
    if (node_to_delete->right_child->left_child == nullptr)
    {
        Node * child = node_to_delete->right_child;
        node_to_delete->data = child->data;
        node_to_delete->key = child->key;
        node_to_delete->right_child = child->right_child;
        delete child;
        return;
    }
    //иначе - ищем наименьший элемент
    Node * successor_parent = this->find_successor_parent(node_to_delete, node_to_delete->right_child);
    Node * successor = successor_parent->left_child;
    //переносим его данные и ключ в удаляемый узел
    node_to_delete->data = successor->data;
    node_to_delete->key = successor->key;
    //удаляем его
    if (successor->right_child == nullptr)
        this->delete_leaf(successor, successor_parent);
    else
        this->delete_node(successor);
}

int Tree::delete_data(int key)
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty\n";
        return 1;
    }
    if (this->root->key == key)
    {
        //если корень является листом
        if (this->root->left_child == nullptr && this->root->right_child == nullptr)
        {
            this->root = nullptr;
            return 0;
        }
        this->delete_node(root);
    }
    Node * parent_deleted_node = this->find_parent_of_deleted_node(this->root, nullptr, key);
    if (parent_deleted_node == nullptr)
    {
        std::cout << "The data is missing\n";
        return 2;
    }

    Node * node_to_delete = this->find_deleted_node(this->root, key);
    //если удаляемый элемент является листом
    if (node_to_delete->right_child == nullptr && node_to_delete->left_child == nullptr)
    {
        this->delete_leaf(node_to_delete, parent_deleted_node);
        return 0;
    }
    //если не является листом
    this->delete_node(node_to_delete);
    return 0;
}

void Node::print_node_sorted()
{
    if (this == nullptr)
        return;
    this->left_child->print_node_sorted();
    std::cout << this->key << std::endl;
    this->right_child->print_node_sorted();
}

void Tree::print_sorted()
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty\n";
        return;
    }
    this->root->left_child->print_node_sorted();
    std::cout << this->root->key << std::endl;
    this->root->right_child->print_node_sorted();
}

void Node::print_depth()
{
    if (this == nullptr)
        return;
    std::cout << this->key << std::endl;
    this->left_child->print_depth();
    this->right_child->print_depth();
}

void Tree::traverse_depth()
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty\n";
        return;
    }
    std::cout << this->root->key << std::endl;
    this->root->left_child->print_depth();
    this->root->right_child->print_depth();
}

void Tree::traverse_width()
{
    if (this->root == nullptr)
    {
        std::cout << "Tree is empty\n";
        return;
    }
    std::queue<Node *> node_queue;
    node_queue.push(this->root);
    while (!node_queue.empty())
    {
        Node * current_node = node_queue.front();
        node_queue.pop();
        std::cout << current_node->key << "\n";
        if (current_node->left_child != nullptr)
            node_queue.push(current_node->left_child);
        if (current_node->right_child != nullptr)
            node_queue.push(current_node->right_child);
    }
}


int main() {
    Tree derevo;
    derevo.add_data(15, (int *) 10);
    derevo.add_data(48, (int *) 100);
    derevo.add_data(10, (int *) 20);
    derevo.add_data(2, (int *) 40);
    derevo.add_data(12, (int *) 30);
    derevo.add_data(20, (int *) 20);
    derevo.add_data(30, (int *) 40);
    derevo.add_data(4, (int *) 30);
    derevo.add_data(60, (int *) 30);
    derevo.add_data(55, (int *) 30);
    derevo.add_data(50, (int *) 30);
    derevo.add_data(58, (int *) 30);
    derevo.add_data(70, (int *) 30);
    derevo.delete_data(2);
    derevo.print_sorted();
    return 0;
}