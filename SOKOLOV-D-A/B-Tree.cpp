#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include<iterator>
const int M = 4;
#define MIN_SIZE ((M-1)/2)

class B_Node 
{
public:
    B_Node(int key = 0, void* data = nullptr);

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

    // метод удаления из листа
    void deleteFromLeaf(int key);
    // поиск соседей. Есть ли возможность объединиться
    std::pair<B_Node*, B_Node*> findNeighbours(B_Node* parent);

    std::vector <B_Node*> children;
    std::vector < std::pair<int, void*>> key;
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

    friend class BTreePrinter;
private:
    B_Node* root;

    // вспомогательный метод для рекурсии
    int addData(int key, B_Node* root, void* data = nullptr);
    //флаг для роста дерева вверх
    bool riseUpFlag{0};
    // метод, реализующий поднятие узла на уровень выше
    int riseUpNode(B_Node* node, B_Node* root);
    int insertToNode(B_Node* node, std::pair<int, void*> key);
    int insertNodeToRoot(B_Node* node, B_Node* root);
    void restructNodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour);
    int mergeNodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour, int key);
    B_Node* mergeChildren(B_Node* currentNode, B_Node* childL, B_Node* childR, size_t indx);
    int deleteData(int key, B_Node* node, B_Node* parent);
    int deleteLikeFromLeaf(int key, B_Node* node, B_Node* parent);
    
};


int B_Tree::addData(int key, void* data)
{
    if (!this->root) //если корень
    {
        root = new B_Node(key, data);
        return 0;
    }         
    if (this->root->canPush() && this->root->children.empty())  // если лист и можно добавить
    {
        insertToNode(this->root, std::make_pair(key, data));
        return 0;
    }
    if (!this->root->canPush() && this->root->children.empty()) // если лист и нельзя добавить
    {
        this->root->divideNode();
        addData(key, this->root, data);
        return 0;
    }
    if (!this->root->children.empty())                          // если не лист. идем глубже
    {
        addData(key, this->root, data);
    }
    riseUpFlag = false;
    return 0;
}

int B_Tree::addData(int key, B_Node* root, void* data)
{
    
    if (!root->children.empty()) // если не лист
    { 
        for (size_t i = 0; i < M - 1; i++)
        {
            if (key <= root->key.at(i).first)
            {
                addData(key, root->children[i], data);
                if (riseUpFlag)
                {
                    riseUpFlag = false;
                    riseUpNode(root->children[i], root);
                    if (!riseUpFlag)
                        addData(key, root, data);
                }
                return 0;
            }
            else
            {
                if (root->key.size() - i == 1)
                    addData(key, root->children[i + 1], data);
                else
                {
                    continue;
                }

                if (riseUpFlag)
                {
                    riseUpFlag = false;
                    riseUpNode(root->children[i + 1], root);
                    if (riseUpFlag)
                        continue;
                    addData(key, root, data);
                }
                return 0;
            }
        }
    }
    else // если лист
    {
        
        if (root->canPush())
        {
            insertToNode(root, std::make_pair(key, data));
            return 0;
        }
        else
        {
            root->divideNode();
            riseUpFlag = true;
            return 0;           
        }
    }
    return 0;
}


int B_Tree::insertToNode(B_Node* node, std::pair<int, void*> key)
{
    for (size_t i = 0; i < M - 1; i++)                                   
    {                                                                    
        if (key.first <= node->key.at(i).first)                          
        {                                                                
            if (i != (M - 2))                                            
            {                                                            
                node->shiftKeyRight();
                node->key.at(i) = key;
            }                                                            
            else                                                         
            {                                                            
                node->key.at(i) = key;
            }                                                            
            break;                                                       
        }                                                                
        else                                                             
        {                                                                
            if (node->key.size() - i == 1)
            {                                                            
                node->key.push_back(key);
                break;                                                   
            }                                                            
                                                                         
        }                                                                
    }                                                                      
    return 0;
}

int B_Tree::insertNodeToRoot(B_Node* node, B_Node* root)
{
    for (size_t i = 0; i < M - 1; i++)
    {
        if (node->key.at(0).first <= root->key.at(i).first)
        {
            if (i != (M - 2))
            {
                root->shiftKeyRight();
                root->key.at(i).first = node->key.at(0).first;
                root->children[i] = node->children[0];
                root->children[i + 1] = node->children[1];

            }
            else
            {
                root->key.at(i).first = node->key.at(0).first;
                root->children[i] = node->children[0];
                root->children[i + 1] = node->children[1];
            }
            break;
        }
        else
        {
            if (root->key.size() - i == 1)
            {
                root->key.push_back(std::make_pair(node->key.at(0).first, node->key.at(0).second));
                root->children[i + 1] = node->children[0];
                root->children.push_back(node->children[1]);

            }
            else
                continue;

            break;
        }
    }
    return 0;
}


int B_Tree::riseUpNode(B_Node* node, B_Node* root)
{
    if (root->canPush())
    {
        insertNodeToRoot(node, root);
        return 0;
    }
    else
    {
        insertNodeToRoot(node, root);
        root->divideNode();
        

        if (root == this->root)
            riseUpFlag = false;
        else
            riseUpFlag = true;
        return 0;
    }
}


B_Node::B_Node(int key, void* data)
{
    children.clear();
    this->key.push_back(std::make_pair(key, data));
}


bool B_Node::canPush()
{
    if (this->key.size() >= (M - 1))
        return false;
    else
        return true;
}

B_Node* B_Node::divideNode()
{
    B_Node* main = new B_Node(this->key.at((M / 2) - 1).first, this->key.at((M / 2) - 1).second);
    main->children.push_back(new B_Node(this->key.at(0).first, this->key.at(0).second));
    main->children.push_back(new B_Node(this->key.at(M - 2).first, this->key.at(M - 2).second));
    if (this->key.size() > (M - 1))
        main->children[1]->key.push_back(this->key.back());

    if (!this->children.empty())
    {
        for (size_t sourceIterator = 0, destinationIterator = 0;
            sourceIterator < this->children.size();
            sourceIterator++, destinationIterator = sourceIterator > 1 ? 1: 0)
        {
            main->children[destinationIterator]->children.push_back(this->children[sourceIterator]);
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

        if (key < this->key.at(i).first)
        {
            this->children[i]->search(key);
            break;
        }
        if (key > this->key.at(i).first && !this->children.empty())
        {
            if (this->key.size() - i > 1)
                continue;
            this->children[i + 1]->search(key);
            break;
        }
    }
    return nullptr;
}

//B_Node* B_Node::searchNode(int key)
//{
//    if (this->children.empty())
//    {
//        for (size_t i = 0; i < this->key.size(); i++)
//            if (key == this->key.at(i).first)
//                return this;
//    }
//    for (size_t i = 0; i < this->key.size(); i++)
//    {
//        if (key < this->key.at(i).first)
//        {
//            this->children[i]->search(key);
//            break;
//        }
//        else
//        {
//            if (this->key.size() - i > 1)
//                continue;
//            this->children[i + 1]->search(key);
//            break;
//        }
//    }
//}

int B_Tree::deleteData(int key, B_Node* currentNode, B_Node* parent)
{
    for (size_t i = 0; i < currentNode->key.size(); i++)
    {
        if (key == currentNode->key.at(i).first) // если ключ найден
        {
            
            if (currentNode->children.empty())   // если удаление из листа
            {
                deleteLikeFromLeaf(key, currentNode, parent); // ПЕРЕИМЕНОВАТЬ!!!!!!!!!
            }
            else // иначе - рекурсия
            {
                // удаление по алгоритму, но если в ребенке ключ совпадает с удаляемым - особый случай.
                // это указывает на то, что происходит удаление. сразу можно удалить, если ключей много

                if (currentNode->children[i]->key.size() > MIN_SIZE ||      // если ключей достаточно
                    currentNode->children[i + 1]->key.size() > MIN_SIZE)    // переносим ключ вверх
                {
                    B_Node* child = (currentNode->children[i]->key.size() > MIN_SIZE) ?
                        currentNode->children[i] :
                        currentNode->children[i + 1];

                    if (child->key[0].first > key)
                    {
                        currentNode->key.at(i) = child->key.at(0);
                        deleteData(child->key[0].first, child, currentNode);
                    }
                    else
                    {
                        currentNode->key.at(i) = child->key.back();
                        deleteData(child->key[0].first, child, currentNode);
                    }
                }
                else //ключей у детей мало
                {
                    if (currentNode->key.size() > MIN_SIZE)
                    {
                        B_Node* tmp = mergeChildren(currentNode, currentNode->children[i], currentNode->children[i + 1], i);
                        insertToNode(tmp, currentNode->key.at(i));
                        //currentNode->deleteFromLeaf(key);
                        deleteData(key, currentNode, parent);
                        deleteData(key, tmp, currentNode);
                    }
                    else
                    {
                        B_Node* tmp = mergeChildren(currentNode, currentNode->children[i], currentNode->children[i + 1], i);
                        insertToNode(tmp, currentNode->key.at(i));
                        //----
                        auto neighbours = currentNode->findNeighbours(parent);

                        if (neighbours.first->key.size() > MIN_SIZE ||         // если есть сосед с ключами
                            neighbours.second->key.size() > MIN_SIZE)
                        {
                            B_Node* neighbour = (neighbours.first->key.size() > MIN_SIZE) ?
                                neighbours.first :
                                neighbours.second;

                            restructNodes(currentNode, parent, neighbour);     // метод перестройки

                            currentNode->deleteFromLeaf(key);
                        }
                        else // иначе (соседи содержат минимум ключей)
                        {
                            B_Node* neighbour = (key == neighbours.first->key[0].first ? neighbours.second : neighbours.first);
                            mergeNodes(currentNode, parent, neighbour, key); // метод слияния
                            
                        }
                        deleteData(key, currentNode, parent);
                    }
                }
            }
            return 0;
        }

        else if (key < currentNode->key.at(i).first) // если ключ меньше
        {
            deleteData(key, currentNode->children[i], currentNode);
            break;
            // проверит на ребаланс
        }
        else                                  // если ключ больше
        {
            if (currentNode->key.size() - i > 1)
                continue;
            deleteData(key, currentNode->children[i + 1], currentNode);
            break;
            // проверка
        }
    }

    return 0;
}


int B_Tree::deleteLikeFromLeaf(int key, B_Node* currentNode, B_Node* parent)
{
    if (currentNode->key.size() > MIN_SIZE)
    {
        currentNode->deleteFromLeaf(key);
        return 0;
    }
    else
    {
        auto neighbours = currentNode->findNeighbours(parent);

        if (neighbours.first->key.size() > MIN_SIZE ||         // если есть сосед с ключами
            neighbours.second->key.size() > MIN_SIZE)
        {
            B_Node* neighbour = (neighbours.first->key.size() > MIN_SIZE) ?
                neighbours.first :
                neighbours.second;

            restructNodes(currentNode, parent, neighbour);     // метод перестройки
        }
        else // иначе (соседи содержат минимум ключей)
        {
            B_Node* neighbour = (key == neighbours.first->key[0].first ? neighbours.second : neighbours.first);
            mergeNodes(currentNode, parent, neighbour, key); // метод слияния
        }
    }

    return 0;
}



void B_Tree::restructNodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour)
{
    size_t currentNodeIndex = 0;
    size_t neighbourIndex = 0;

    for (size_t i = 0; i < parent->children.size(); i++)
    {
        if (parent->children[i] == currentNode)
            currentNodeIndex = i;
        if (parent->children[i] == neighbour)
            neighbourIndex = i;
    }
    size_t parentKeyIndex = currentNodeIndex < neighbourIndex ? currentNodeIndex : neighbourIndex;
    size_t neighbourKeyIndex = currentNodeIndex < neighbourIndex ? 0 : (neighbour->key.size() - 1);

    insertToNode(currentNode, parent->key[parentKeyIndex]);
    parent->key[parentKeyIndex] =
        neighbour->key[neighbourKeyIndex];
    neighbour->deleteFromLeaf(neighbour->key[neighbourKeyIndex].first);

    if (currentNodeIndex < neighbourIndex)
    {
        currentNode->children.push_back(neighbour->children.at(0));
        neighbour->children.erase(neighbour->children.begin());
    }
    else
    {
        currentNode->children.insert(currentNode->children.begin(), neighbour->children.back());
        neighbour->children.erase(neighbour->children.end());
    }

}


int B_Tree::mergeNodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour, int key)
{
    size_t currentNodeIndex = 0;
    size_t neighbourIndex = 0;

    for (size_t i = 0; i < parent->children.size(); i++)
    {
        if (parent->children[i] == currentNode)
            currentNodeIndex = i;
        if (parent->children[i] == neighbour)
            neighbourIndex = i;
    }
    size_t parentKeyIndex = currentNodeIndex < neighbourIndex ? currentNodeIndex : neighbourIndex;
    insertToNode(currentNode, parent->key[parentKeyIndex]);
    insertToNode(currentNode, neighbour->key.at(0));
    if (!neighbour->children.empty())
    {
        for (size_t i = 0; i <= neighbour->children.size(); i++)
        {
            if (currentNodeIndex < neighbourIndex)
            {
                currentNode->children.push_back(neighbour->children.at(0));
                neighbour->children.erase(neighbour->children.begin());
            }
            else
            {
                currentNode->children.insert(currentNode->children.begin(), neighbour->children.back());
                neighbour->children.erase(neighbour->children.end());
            }
        }

    }
    parent->children.erase(parent->children.begin() + neighbourIndex);
    if (parent->key.size() > MIN_SIZE)
        parent->key.erase(parent->key.begin() + parentKeyIndex);
    //deleteData(key, currentNode, parent);
    currentNode->deleteFromLeaf(key);
    return 0;
}


B_Node* B_Tree::mergeChildren(B_Node* currentNode, B_Node* childL, B_Node* childR, size_t indx)
{
    insertToNode(childR, childL->key.back());
    currentNode->children.erase(currentNode->children.begin() + indx);
    return childR;
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


std::pair<B_Node*, B_Node*> B_Node::findNeighbours(B_Node* parent)
{  
    for (auto i = parent->children.begin(); i < parent->children.end(); i++)
    {
        if (*i == this)
        {
            return std::make_pair((i != parent->children.begin()) ? *(i - 1) : *i,
                                  (i != --parent->children.end()) ? *(i + 1) : *i);

        }
    }
}


void B_Node::shiftKeyRight()
{
    for (size_t i = this->key.size(); i > 0; i--)
    {
        if (this->key.size() < M-1)
            this->key.push_back(std::make_pair(this->key.at(i - 1).first, this->key.at(i - 1).second));
        else
        {
            this->key[i] = this->key[i - 1];
        }
        if (!this->children.empty())
        {
            if (this->children.size() < M)
                this->children.push_back(this->children[i]);
            this->children[i] = this->children[i - 1];
        }
    }

}


void B_Node::print()
{
    size_t i;
    for (i = 0; i < this->key.size(); i++)
    {
        if (i < this->children.size())
            children[i]->print();

        std::cout << " " << key.at(i).first;   
    }
    std::cout << "\n";
    if (i < this->children.size())
        children[i]->print();
    std::cout << "\n";
}

void B_Tree::print()
{
    this->root->print();
}

void* B_Tree::search(int key)
{
    if (this->root->children.empty())
    {
        for (size_t i = 0; i < M - 1; i++)
            if (key == this->root->key.at(i).first)
                return this->root->key.at(i).second;
    }
    for (size_t i = 0; i < this->root->key.size(); i++)
    {
        if (key < this->root->key.at(i).first)
        {
            this->root->children[i]->search(key);
            break;
        }
        else
        {
            if (this->root->key.size() - i > 1)
                continue;
            this->root->children[i+1]->search(key);
            break;
        }
    }
    return nullptr;

}

int B_Tree::deleteData(int key)
{
    deleteData(key, root, root);
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

    if (node->children.empty())
    {
        info.text_end = info.text_pos + unsigned(info.text.length());
    }
    else 
    {
        for (unsigned i = 0, e = unsigned(node->key.size()); i <= e; ++i)  
            visit(node->children[i], level + 1, i);

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

    srand(2934);

    for (int i = 1; i < 17; i++)
    {
        int p = rand() % 100;
        t.addData(i);
        
    }
    printer.print(t);
    void* sear = t.search(56);
    t.deleteData(11);
    printer.print(t);
    t.deleteData(4);
    system("pause");
    return 0;
}
