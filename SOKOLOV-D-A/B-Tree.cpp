#include <iostream>
#include <vector>
const int M = 4;


struct B_Node
{
    B_Node()
    {
        childrens.clear();
        numberOfKeys = 0; 
        for (size_t i = 0; i < M - 1; i++)
        {
            this->key[i] = 0;
        }
    }

    B_Node(int key)
    {
        childrens.clear();
        this->key[0] = key;
        for (size_t i = 1; i < M - 1; i++)
        {
            this->key[i] = 0;
        }
        numberOfKeys = 1;
    }

    ~B_Node(){}

    bool canPush();
    

    std::vector <B_Node*> childrens;
    int key[M-1];
    int numberOfKeys;
    void shiftArrayRight(B_Node* node);
    void print();
};


struct B_Tree : private B_Node
{
    B_Node* root;

    B_Tree()
    {
        this->root = nullptr;
    }

    ~B_Tree(){}

    int addData(int key);
    B_Node* divideNode(B_Node* node);
    int riseUpNode(B_Node* node, B_Node* root);

private:
    int addData(int key, B_Node* root);
    bool riseUpFlag{0};
    
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
                    shiftArrayRight(this->root);
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
        divideNode(this->root);
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
                        shiftArrayRight(root);
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
            divideNode(root);
            riseUpFlag = true;
            return 0;
            //функцию поднятия вверх 
            //а точнее написать метод в класс B_Node
            //который трансформирует ноду в ключ с указателями (в корне)
            
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
                    shiftArrayRight(root);
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
        divideNode(root);
        
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


bool B_Node::canPush()
{
    if (numberOfKeys >= (M - 1)) //на всякий случай ">="
        return false;
    else
        return true;
}

B_Node* B_Tree::divideNode(B_Node* node)
{
    B_Node* main = new B_Node(node->key[(M / 2) - 1]);
    main->childrens.push_back(new B_Node(node->key[0]));
    main->childrens.push_back(new B_Node(node->key[M-2]));
    if (!node->childrens.empty())
    {
        for (size_t sourceIterator = 0, destinationIterator = 0;
            sourceIterator < node->childrens.size();
            sourceIterator++, destinationIterator = sourceIterator > 1 ? 1: 0)
        {
            main->childrens[destinationIterator]->childrens.push_back(node->childrens[sourceIterator]);
        }
    }
    *node = *main;
    return main;
}


void B_Node::shiftArrayRight(B_Node* node)
{
    for (size_t i = node->numberOfKeys; i > 0; i--)
    {
        node->key[i] = node->key[i - 1];
        if (!node->childrens.empty())
        {
            if (node->childrens.size() < M)
                node->childrens.push_back(node->childrens[i]);
            node->childrens[i] = node->childrens[i - 1];
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
