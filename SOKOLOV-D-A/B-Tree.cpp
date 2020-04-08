#include <iostream>
#include <vector>
const int M = 4;


class B_Node
{
public:
    B_Node(int key = 0);

    ~B_Node(){}


    // обход + вывод в консоль
    void print();

    std::vector <B_Node*> childrens;
    int key[M - 1];
    int numberOfKeys;

    friend class B_Tree;
private:
    //метод проверяет можно ли добавить ключ в узел
    bool canPush();
    // смещение ключей на один вправо
    void shiftKeyRight();
    // метод делит узел на три 
    B_Node* divideNode();
};


class B_Tree
{
public:
    B_Tree() {this->root = nullptr;}
    ~B_Tree(){}
    //метод добавления нового ключа в дерево
    int addData(int key);

    B_Node* root;

private:
    // вспомогательный метод для рекурсии
    int addData(int key, B_Node* root);
    //флаг для роста дерева вверх
    bool riseUpFlag{0};
    // метод, реализующий поднятие узла на уровень выше
    int riseUpNode(B_Node* node, B_Node* root);
    
};


int B_Tree::addData(int key)
{
    if (!this->root)
    {
        root = new B_Node(key);
        return 0;
    }
               
    if (this->root->canPush() && this->root->childrens.empty())
    {
        for (size_t i = 0; i < M - 1; i++)
        {
            if (key <= this->root->key[i])
            {
                if (i != (M - 2))
                {
                    this->root->shiftKeyRight();
                    this->root->key[i] = key;
                }
                else
                {
                    this->root->key[i] = key;
                }
                break;
            }
            else
            {
                if (this->root->key[i + 1] == 0)
                    this->root->key[i + 1] = key;
            }
        }
        root->numberOfKeys++;
        return 0;
    }
    else if (!this->root->canPush() && this->root->childrens.empty())
    {
        this->root->divideNode();
        addData(key, this->root);
    }
    else
    {
        addData(key, this->root);
    }
}

int B_Tree::addData(int key, B_Node* root)
{
    
    if (!root->childrens.empty())
    { 
        for (size_t i = 0; i < M - 1; i++)
        {
            if (key <= root->key[i])
            {
                addData(key, root->childrens[i]);
                if (riseUpFlag)
                {
                    riseUpFlag = false;
                    riseUpNode(root->childrens[i], root);

                    addData(key, root);
                }
                return 0;
            }
            else
            {
                if (root->key[i + 1] == 0 && i < M/2)
                    addData(key, root->childrens[i + 1]);
                else if (i == M/2)
                    addData(key, root->childrens[i + 1]);
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
                    addData(key, root);
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
                if (key <= root->key[i])
                {
                    if (i != (M - 2))
                    {
                        root->shiftKeyRight();
                        root->key[i] = key;
                    }
                    else
                    {
                        root->key[i] = key;
                    }
                    break;
                }
                else
                {
                    if (root->key[i + 1] == 0)
                        root->key[i + 1] = key;
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
            if (node->key[0] <= root->key[i])
            {
                if (i != (M - 2))
                {
                    root->shiftKeyRight();
                    root->key[i] = node->key[0];
                    root->childrens[i] = node->childrens[i];
                    root->childrens[i + 1] = node->childrens[i + 1];

                }
                else
                {
                    root->key[i] = node->key[0];
                    root->childrens[i] = node->childrens[i];
                    root->childrens[i + 1] = node->childrens[i + 1];
                }
                break;
            }
            else
            {
                if (root->key[i + 1] == 0)
                {
                    root->key[i + 1] = node->key[0];
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
        
        if (node->key[0] <= root->key[0] && root == this->root)
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


B_Node::B_Node(int key = 0)
{
    childrens.clear();
    this->key[0] = key;
    for (size_t i = 1; i < M - 1; i++)
    {
        this->key[i] = 0;
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
    B_Node* main = new B_Node(this->key[(M / 2) - 1]);
    main->childrens.push_back(new B_Node(this->key[0]));
    main->childrens.push_back(new B_Node(this->key[M-2]));
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


void B_Node::shiftKeyRight()
{
    for (size_t i = this->numberOfKeys; i > 0; i--)
    {
        this->key[i] = this->key[i - 1];
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
    for (i = 0; i < M - 1; i++)
    {
        if (!this->childrens.empty())
            childrens[i]->print();
        std::cout << " " << key[i];
    }
    if (!this->childrens.empty())
        childrens[i]->print();
}

int main()
{
    B_Tree first;
    first.addData(1);
    first.addData(2);
    first.addData(3);
    first.addData(4);
    first.addData(17);
    first.addData(31);
    first.addData(7);
    first.addData(9);
    first.addData(11);
    first.addData(13);
    first.addData(16);
    first.addData(19);
    first.addData(26);
    first.addData(27);
    first.addData(96);
    first.addData(99);
    first.addData(97);
    first.addData(14);
    
    first.root->print();

    system("pause");
    return 0;
}
