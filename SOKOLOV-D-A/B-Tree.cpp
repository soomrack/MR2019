#include <iostream>
#include <vector>
#include <map>
const int M = 4;


class B_Node
{
public:
    B_Node(int key, void* data = nullptr);

    ~B_Node(){}

    // обход + вывод в консоль
    void print();

    friend class B_Tree;
private:
    //метод проверяет можно ли добавить ключ в узел
    bool canPush();
    // смещение ключей на один вправо
    void shiftKeyRight();
    // метод делит узел на три 
    B_Node* divideNode();
    void* search(int key);

    std::vector <B_Node*> childrens;
    std::vector < std::pair<int, void*>> key;
    int numberOfKeys;
};


class B_Tree
{
public:
    B_Tree() {this->root = nullptr;}
    ~B_Tree(){}
    //метод добавления нового ключа в дерево
    int addData(int key, void* data = nullptr);
    //вывод дерева на экран
    void print();
    //Поиск элемента по ключу
    void* search(int key);

    B_Node* root;

private:
    // вспомогательный метод для рекурсии
    int addData(int key, B_Node* root, void* data = nullptr);
    //флаг для роста дерева вверх
    bool riseUpFlag{0};
    // метод, реализующий поднятие узла на уровень выше
    int riseUpNode(B_Node* node, B_Node* root);
    
};


int B_Tree::addData(int key, void* data)
{
    if (!this->root)
    {
        root = new B_Node(key, data);
        return 0;
    }
               
    if (this->root->canPush() && this->root->childrens.empty())
    {
        for (size_t i = 0; i < M - 1; i++)
        {
            if (key <= this->root->key.at(i).first)
            {
                if (i != (M - 2))
                {
                    this->root->shiftKeyRight();
                    this->root->key.at(i) = std::make_pair(key, data);
                }
                else
                {
                    this->root->key.at(i) = std::make_pair(key, data);
                }
                break;
            }
            else
            {
                if (this->root->key.at(i+1).first == 0)
                    this->root->key.at(i+1) = std::make_pair(key, data);
            }
        }
        root->numberOfKeys++;
        return 0;
    }
    else if (!this->root->canPush() && this->root->childrens.empty())
    {
        this->root->divideNode();
        addData(key, this->root, data);
    }
    else
    {
        addData(key, this->root, data);
    }
}

int B_Tree::addData(int key, B_Node* root, void* data)
{
    
    if (!root->childrens.empty())
    { 
        for (size_t i = 0; i < M - 1; i++)
        {
            if (key <= root->key.at(i).first)
            {
                addData(key, root->childrens[i], data);
                if (riseUpFlag)
                {
                    riseUpFlag = false;
                    riseUpNode(root->childrens[i], root);

                    addData(key, root, data);
                }
                return 0;
            }
            else
            {
                if (i < M / 2 && root->key.at(i+1).first == 0)
                    addData(key, root->childrens[i + 1], data);
                else if (i == M/2)
                    addData(key, root->childrens[i + 1], data);
                else
                {
                    continue;
                }

                if (riseUpFlag)
                {
                    riseUpFlag = false;
                    riseUpNode(root->childrens[i + 1], root);
                    if (riseUpFlag)
                        continue;
                    addData(key, root, data);
                }
                return 0;
            }
        }
    }
    else
    {
        
        if (root->canPush())
        {
            for (size_t i = 0; i < M - 1; i++)
            {
                if (key <= root->key.at(i).first)
                {
                    if (i != (M - 2))
                    {
                        root->shiftKeyRight();
                        root->key.at(i) = std::make_pair(key, data);
                    }
                    else
                    {
                        root->key.at(i) = std::make_pair(key, data);
                    }
                    break;
                }
                else
                {
                    if (root->key.at(i+1).first == 0)
                        root->key.at(i+1) = std::make_pair(key, data);
                }
            }

            root->numberOfKeys++;
            return 0;
        }
        else
        {// поднять наверх
            root->divideNode();
            riseUpFlag = true;
            return 0;           
        }
    }
    
}


int B_Tree::riseUpNode(B_Node* node, B_Node* root)
{
    if (root->canPush())
    {
        for (size_t i = 0; i < M - 1; i++)
        {
            if (node->key.at(0).first <= root->key.at(i).first)
            {
                if (i != (M - 2))
                {
                    root->shiftKeyRight();
                    root->key.at(i).first = node->key.at(0).first;
                    root->childrens[i] = node->childrens[i];
                    root->childrens[i + 1] = node->childrens[i + 1];

                }
                else
                {
                    root->key.at(i).first = node->key.at(0).first;
                    root->childrens[i] = node->childrens[i];
                    root->childrens[i + 1] = node->childrens[i + 1];
                }
                break;
            }
            else
            {
                if (root->key.at(i+1).first == 0)
                {
                    root->key.at(i+1).first = node->key.at(0).first;
                    root->childrens[i + 1] = node->childrens[0];
                    root->childrens.push_back(node->childrens[1]);

                }
                else
                    continue;

                break;
            }
        }
        root->numberOfKeys++;
        return 0;
    }
    else
    {
        root->divideNode();
        
        if (node->key.at(0).first <= root->key.at(0).first && root == this->root)
            riseUpNode(node, root->childrens[0]);
        else if (root == this->root)
        {
            riseUpNode(node, root->childrens[1]);
        }
        else
            riseUpFlag = true;
            


        return 0;
    }
}


B_Node::B_Node(int key, void* data)
{
    childrens.clear();
    this->key.push_back(std::make_pair(key, data));
    for (size_t i = 1; i < M - 1; i++)
    {
        this->key.push_back(std::make_pair(0, nullptr));
    }
    numberOfKeys = 1;
}


bool B_Node::canPush()
{
    if (numberOfKeys >= (M - 1))
        return false;
    else
        return true;
}

B_Node* B_Node::divideNode()
{
    B_Node* main = new B_Node(this->key.at((M / 2) - 1).first, this->key.at((M / 2) - 1).second);
    main->childrens.push_back(new B_Node(this->key.at(0).first, this->key.at(0).second));
    main->childrens.push_back(new B_Node(this->key.at(M-2).first, this->key.at(M - 2).second));
    if (!this->childrens.empty())
    {
        for (size_t sourceIterator = 0, destinationIterator = 0;
            sourceIterator < this->childrens.size();
            sourceIterator++, destinationIterator = sourceIterator > 1 ? 1: 0)
        {
            main->childrens[destinationIterator]->childrens.push_back(this->childrens[sourceIterator]);
        }
    }
    *this = *main;
    return main;
}

void* B_Node::search(int key)
{
    if (this->childrens.empty())
    {
        for (auto i = 0; i < M - 1; i++)
            if (key == this->key.at(i).first)
                return this->key.at(i).second;
    }
    for (auto i = 0; i < M - 1; i++)
    {
        if (key < this->key.at(i).first)
        {
            this->childrens[i]->search(key);
            break;
        }
        else
        {
            if (this->key.at(i+1).first != 0 && (i + 1) != M)
                continue;
            this->childrens[i + 1]->search(key);
            break;
        }
    }
}


void B_Node::shiftKeyRight()
{
    for (size_t i = this->numberOfKeys; i > 0; i--)
    {
        this->key.at(i).first = this->key.at(i - 1).first;
        if (!this->childrens.empty())
        {
            if (this->childrens.size() < M)
                this->childrens.push_back(this->childrens[i]);
            this->childrens[i] = this->childrens[i - 1];
        }
    }

}


void B_Node::print()
{
    size_t i;
    for (i = 0; i < M-1; i++)
    {
        if (i < this->childrens.size())
        {
            childrens[i]->print();
            //std::cout << "\n";
        }
        if (key.at(i).first != 0)
        {
            std::cout << " " << key.at(i).first;
            //std::cout << "\n";
        }
            
    }
    std::cout << "\n";
    if (i < this->childrens.size())
        childrens[i]->print();
}

void B_Tree::print()
{
    this->root->print();
}

void* B_Tree::search(int key)
{
    if (this->root->childrens.empty())
    {
        for (auto i = 0; i < M - 1; i++)
            if (key == this->root->key.at(i).first)
                return this->root->key.at(i).second;
    }
    for (auto i = 0; i < M - 1; i++)
    {
        if (key < this->root->key.at(i).first)
        {
            this->root->childrens[i]->search(key);
            break;
        }
        else
        {
            if (this->root->key.at(i+1).first != 0 && (i+1) != M)
                continue;
            this->root->childrens[i+1]->search(key);
            break;
        }
    }
}

int main()
{
    std::string data6 = "Putin";
    B_Tree b_tree;
    b_tree.addData(1);
    b_tree.addData(2);
    b_tree.addData(3); 
    b_tree.addData(4);
    b_tree.addData(17);
    b_tree.addData(31);
    b_tree.addData(7);
    b_tree.addData(9);
    b_tree.addData(11);
    b_tree.addData(13);
    b_tree.addData(16);
    b_tree.addData(19);
    b_tree.addData(26);
    b_tree.addData(27);
    b_tree.addData(96, &data6);
    b_tree.addData(99);
    b_tree.addData(97);
    b_tree.addData(14);
    std::string* a = 0;
    a = (std::string*)b_tree.search(96);
    b_tree.print();

    system("pause");
    return 0;
}
