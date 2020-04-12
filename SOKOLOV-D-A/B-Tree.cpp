#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include<iterator>
const int M = 4;
#define MIN_SIZE 1

class B_Node 
{
public:
    B_Node(int key, void* data = nullptr);

    ~B_Node(){}

    // обход + вывод в консоль
    void print();

    friend class B_Tree;
    friend class BTreePrinter;
private:
    //метод проверяет можно ли добавить ключ в узел
    bool canPush();
    // смещение ключей на один вправо
    void shiftKeyRight();
    // метод делит узел на три 
    B_Node* divideNode();
    void* search(int key);
    B_Node* searchNode(int key);
    int deleteData(int key, B_Node* parent);
    // метод удаления из листа
    void deleteFromLeaf(int key);
    // поиск соседей. Есть ли возможность объединиться
    B_Node* findNeighbour(B_Node* parent);

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
    //Удаление элемента
    int deleteData(int key);

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
                if (this->root->key.size() - i == 1)
                {
                    this->root->key.push_back(std::make_pair(key, data));
                    break;
                }
                    
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
    return 0;
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
                    if (!riseUpFlag)
                        addData(key, root, data);
                }
                return 0;
            }
            else
            {
                if (root->key.size() - i == 1)
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
                    if (root->key.size() - i == 1)
                    {
                        root->key.push_back(std::make_pair(key, data));
                        break;
                    }
                        
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
    return 0;
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
                    root->childrens[i] = node->childrens[0];
                    root->childrens[i + 1] = node->childrens[1];

                }
                else
                {
                    root->key.at(i).first = node->key.at(0).first;
                    root->childrens[i] = node->childrens[0];
                    root->childrens[i + 1] = node->childrens[1];
                }
                break;
            }
            else
            {
                if (root->key.size() - i == 1)
                {
                    root->key.push_back(std::make_pair(node->key.at(0).first, node->key.at(0).second));
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

    for (size_t i = 0; i < this->key.size(); i++)
    {
        if (key == this->key.at(i).first)
            return this->key.at(i).second;

        else if (key < this->key.at(i).first)
        {
            this->childrens[i]->search(key);
            break;
        }
        else
        {
            if (this->key.size() - i > 1)
                continue;
            this->childrens[i + 1]->search(key);
            break;
        }
    }
}

B_Node* B_Node::searchNode(int key)
{
    if (this->childrens.empty())
    {
        for (size_t i = 0; i < this->key.size(); i++)
            if (key == this->key.at(i).first)
                return this;
    }
    for (size_t i = 0; i < this->key.size(); i++)
    {
        if (key < this->key.at(i).first)
        {
            this->childrens[i]->search(key);
            break;
        }
        else
        {
            if (this->key.size() - i > 1)
                continue;
            this->childrens[i + 1]->search(key);
            break;
        }
    }
}

int B_Node::deleteData(int key, B_Node* parent)
{
    //B_Node* targetNode = this->searchNode(key);

    //if (this->childrens.empty()) // если удаление из листа
    //{
    //    if (targetNode->key.size() > MIN_SIZE)
    //    {
    //        deleteFromNode(targetNode, key);
    //    }
    //    else
    //    {

    //    }
    //}

    for (size_t i = 0; i < this->key.size(); i++)
    {
        if (key == this->key.at(i).first)
        {
            // если удаление из листа
            if (this->childrens.empty())
            {
                if (this->key.size() > MIN_SIZE)
                {
                    this->deleteFromLeaf(key);
                }
                else
                {
                    B_Node* neighbour = this->findNeighbour(parent);
                    // если есть сосед с ключами
                    if (1)
                    {

                    }
                    // иначе (соседи содержат минимум ключей)
                    else
                    {

                    }
                }
                
            }
            // иначе
            else
            {

            }
        }

        else if (key < this->key.at(i).first)
        {
            this->childrens[i]->deleteData(key, this);
            break;
        }
        else
        {
            if (this->key.size() - i > 1)
                continue;
            this->childrens[i + 1]->deleteData(key, this);
            break;
        }
    }

    return 0;
}


void B_Node::deleteFromLeaf(int key)
{
    for (auto i = this->key.begin(); i != this->key.end(); i++)
    {
        if (key == i->first)
        {
            this->key.erase(i);
            return;
        }
            
    }
}


B_Node* B_Node::findNeighbour(B_Node* parent)
{
    // если есть сосед с ключами
    for (auto i = parent->childrens.begin(); i < parent->childrens.end(); i++)
    {
        if (*i == this)
        {
            if ((*(--i))->key.size() > MIN_SIZE)
            {
                return *i;
            }
            else if ((*(++i))->key.size() > MIN_SIZE)
            {
                return *i;
            }
        }
    }
    // иначе. соседи есть, но ключей мало

    return 0;
}


void B_Node::shiftKeyRight()
{
    for (size_t i = this->numberOfKeys; i > 0; i--)
    {
        if (this->key.size() < M-1)
            this->key.push_back(std::make_pair(this->key.at(i - 1).first, this->key.at(i - 1).second));
        else
        {
            this->key[i] = this->key[i - 1];
        }
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
    for (i = 0; i < this->key.size(); i++)
    {
        if (i < this->childrens.size())
            childrens[i]->print();

        std::cout << " " << key.at(i).first;   
    }
    std::cout << "\n";
    if (i < this->childrens.size())
        childrens[i]->print();
    std::cout << "\n";
}

void B_Tree::print()
{
    this->root->print();
}

void* B_Tree::search(int key)
{
    if (this->root->childrens.empty())
    {
        for (size_t i = 0; i < M - 1; i++)
            if (key == this->root->key.at(i).first)
                return this->root->key.at(i).second;
    }
    for (size_t i = 0; i < this->root->key.size(); i++)
    {
        if (key < this->root->key.at(i).first)
        {
            this->root->childrens[i]->search(key);
            break;
        }
        else
        {
            if (this->root->key.size() - i > 1)
                continue;
            this->root->childrens[i+1]->search(key);
            break;
        }
    }

}

int B_Tree::deleteData(int key)
{
    root->deleteData(key, root);
    return 0;
}


//-----------------------------------------------------------------------
class BTreePrinter
{
    struct NodeInfo
    {
        std::string text;
        unsigned text_pos, text_end; 
    };

    typedef std::vector<NodeInfo> LevelInfo;

    std::vector<LevelInfo> levels;

    std::string node_text(std::vector < std::pair<int, void*>> const keys, unsigned key_count);

    void before_traversal()
    {
        levels.resize(0);
        levels.reserve(10);   
    }

    void visit(B_Node const* node, unsigned level = 0, unsigned child_index = 0);

    void after_traversal();

public:
    void print(B_Tree const& tree)
    {
        before_traversal();
        visit(tree.root);
        after_traversal();
    }
};


void BTreePrinter::visit(B_Node const* node, unsigned level, unsigned child_index)
{
    if (level >= levels.size())
        levels.resize(level + 1);

    LevelInfo& level_info = levels[level];
    NodeInfo info;

    info.text_pos = 0;
    if (!level_info.empty())  
        info.text_pos = level_info.back().text_end + (child_index == 0 ? 2 : 1);

    info.text = node_text(node->key, unsigned(node->key.size()));

    if (node->childrens.empty())
    {
        info.text_end = info.text_pos + unsigned(info.text.length());
    }
    else 
    {
        for (unsigned i = 0, e = unsigned(node->key.size()); i <= e; ++i)  
            visit(node->childrens[i], level + 1, i);

        info.text_end = levels[level + 1].back().text_end;
    }

    levels[level].push_back(info);
}


std::string BTreePrinter::node_text(std::vector < std::pair<int, void*>> const keys, unsigned key_count)
{
    std::ostringstream os;
    char const* sep = "";

    os << "[";
    for (unsigned i = 0; i < key_count; ++i, sep = " ")
        os << sep << keys[i].first;
    os << "]";

    return os.str();
}


void print_blanks(unsigned n)
{
    while (n--)
        std::cout << ' ';
}


void BTreePrinter::after_traversal()
{
    for (std::size_t l = 0, level_count = levels.size(); ; )
    {
        auto const& level = levels[l];
        unsigned prev_end = 0;

        for (auto const& node : level)
        {
            unsigned total = node.text_end - node.text_pos;
            unsigned slack = total - unsigned(node.text.length());
            unsigned blanks_before = node.text_pos - prev_end;

            print_blanks(blanks_before + slack / 2);
            std::cout << node.text;

            if (&node == &level.back())
                break;

            print_blanks(slack - slack / 2);

            prev_end += blanks_before + total;
        }

        if (++l == level_count)
            break;

        std::cout << "\n\n";
    }

    std::cout << "\n";
}
//--------------------------------------------------------------------------------------


int main()
{
   
    BTreePrinter printer;
    B_Tree t;

    srand(29324);

    for (unsigned i = 0; i < 14; ++i)
    {
        int p = rand() % 100;
        t.addData(p);
        
    }
    printer.print(t);
    t.addData(4);
    void* sear = t.search(56);
    t.deleteData(42);
    system("pause");
    return 0;
}
