#include "B_Tree.h"



int B_Tree::add_data(int key, void* data)
{
    if (!this->root) //если корень пуст
    {
        root = new B_Node(key, data);
        return 0;
    }
    if (this->root->can_push(M) && this->root->children.empty())  // если лист и можно добавить
    {
        insert_key(this->root, std::make_pair(key, data));
        return 0;
    }
    if (!this->root->can_push(M) && this->root->children.empty()) // если лист и нельзя добавить
    {
        this->root->split(M);
        add_data(key, this->root, data);
        return 0;
    }
    if (!this->root->children.empty())                          // если не лист. идем глубже
    {
        add_data(key, this->root, data);
    }
    lift_flag = false;
    return 0;
}

int B_Tree::add_data(int key, B_Node* root, void* data)
{

    if (!root->children.empty()) // если не лист
    {
        for (size_t i = 0; i < M - 1; i++)
        {
            if (key <= root->key.at(i).first)
            {
                add_data(key, root->children[i], data);
                if (lift_flag)
                {
                    lift_flag = false;
                    lift_node(root->children[i], root);
                    if (!lift_flag)
                        add_data(key, root, data);
                }
                return 0;
            }
            else
            {
                if (root->key.size() - i == 1)
                    add_data(key, root->children[i + 1], data);
                else
                {
                    continue;
                }

                if (lift_flag)
                {
                    lift_flag = false;
                    lift_node(root->children[i + 1], root);
                    if (lift_flag)
                        continue;
                    add_data(key, root, data);
                }
                return 0;
            }
        }
    }
    else // если лист
    {

        if (root->can_push(M))
        {
            insert_key(root, std::make_pair(key, data));
            return 0;
        }
        else
        {
            root->split(M);
            lift_flag = true;
            return 0;
        }
    }
    return 0;
}


int B_Tree::insert_key(B_Node* node, std::pair<int, void*> key)
{
    for (size_t i = 0; i < M - 1; i++)
    {
        if (key.first <= node->key.at(i).first)
        {
            node->key.insert(node->key.begin() + i, key);
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

int B_Tree::insert_node(B_Node* node, B_Node* root)
{
    for (size_t i = 0; i < M - 1; i++)
    {
        if (node->key.at(0).first <= root->key.at(i).first)
        {
            if (i != (M - 2))
            {
                root->shift_right(M);
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


int B_Tree::lift_node(B_Node* node, B_Node* root)
{
    if (root->can_push(M))
    {
        insert_node(node, root);
        return 0;
    }
    else
    {
        insert_node(node, root);
        root->split(M);


        if (root == this->root)
            lift_flag = false;
        else
            lift_flag = true;
        return 0;
    }
}


B_Node::B_Node(int key, void* data)
{
    children.clear();
    this->key.push_back(std::make_pair(key, data));
}


bool B_Node::can_push(unsigned M)
{
    if (this->key.size() >= (M - 1))
        return false;
    else
        return true;
}

B_Node* B_Node::split(unsigned M)
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
            sourceIterator++, destinationIterator = sourceIterator > 1 ? 1 : 0)
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




int B_Tree::delete_data(int key, B_Node* currentNode, B_Node* parent)
{
    for (size_t i = 0; i < currentNode->key.size(); i++)
    {
        if (key == currentNode->key.at(i).first) // если ключ найден
        {

            if (currentNode->children.empty())   // если удаление из листа
            {
                if (currentNode->key.size() > MIN_SIZE)
                {
                    currentNode->delete_key(key);
                    return 0;
                }
                else
                {
                    rebalance(key, currentNode, parent);
                    currentNode->delete_key(key);
                }
            }
            else
            {
                if (currentNode->children[i]->key.size() > MIN_SIZE ||      // если ключей достаточно
                    currentNode->children[i + 1]->key.size() > MIN_SIZE)    // переносим ключ вверх
                {
                    B_Node* child = (currentNode->children[i]->key.size() > MIN_SIZE) ?
                        currentNode->children[i] :
                        currentNode->children[i + 1];

                    if (child->key[0].first > key)
                    {
                        delete_data(child->key[0].first, child, currentNode);
                        currentNode->key.at(i) = child->key.at(0);

                    }
                    else
                    {
                        delete_data(child->key[0].first, child, currentNode);
                        currentNode->key.at(i) = child->key.back();
                    }
                }
                else //ключей у детей мало
                {
                    if (currentNode->key.size() > MIN_SIZE)
                    {
                        B_Node* tmp = merge_children(currentNode, currentNode->children[i], currentNode->children[i + 1], i);
                        insert_key(tmp, currentNode->key.at(i));
                        currentNode->delete_key(key);
                        delete_data(key, tmp, currentNode);
                    }
                    else
                    {
                        rebalance(key, currentNode, parent);
                        delete_data(key, currentNode, parent);
                    }
                }
            }
            return 0;
        }

        else if (key < currentNode->key.at(i).first) // если ключ меньше
        {
            delete_data(key, currentNode->children[i], currentNode);
            break;
        }
        else                                  // если ключ больше
        {
            if (currentNode->key.size() - i > 1)
                continue;
            delete_data(key, currentNode->children[i + 1], currentNode);
            break;
        }
    }

    return 0;
}



void B_Tree::rebalance(int key, B_Node* currentNode, B_Node* parent)
{
    auto neighbours = currentNode->find_neighbours(parent);

    if (neighbours.first->key.size() > MIN_SIZE ||         // если есть сосед с ключами
        neighbours.second->key.size() > MIN_SIZE)
    {
        B_Node* neighbour = (neighbours.first->key.size() > MIN_SIZE) ?
            neighbours.first :
            neighbours.second;

        restruct_nodes(currentNode, parent, neighbour);     // метод перестройки
    }
    else // иначе (соседи содержат минимум ключей)
    {
        B_Node* neighbour = (key == neighbours.first->key[0].first ? neighbours.second : neighbours.first);
        merge_nodes(currentNode, parent, neighbour, key); // метод слияния
    }
}



void B_Tree::restruct_nodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour)
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

    insert_key(currentNode, parent->key[parentKeyIndex]);
    parent->key[parentKeyIndex] =
        neighbour->key[neighbourKeyIndex];
    neighbour->delete_key(neighbour->key[neighbourKeyIndex].first);

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


int B_Tree::merge_nodes(B_Node* currentNode, B_Node* parent, B_Node* neighbour, int key)
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
    insert_key(currentNode, parent->key[parentKeyIndex]);
    insert_key(currentNode, neighbour->key.at(0));
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
    //delete_data(key, currentNode, parent);
    //currentNode->delete_key(key);
    return 0;
}


B_Node* B_Tree::merge_children(B_Node* currentNode, B_Node* childL, B_Node* childR, size_t indx)
{
    insert_key(childR, childL->key.back());
    currentNode->children.erase(currentNode->children.begin() + indx);
    return childR;
}


void B_Node::delete_key(int key)
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


std::pair<B_Node*, B_Node*> B_Node::find_neighbours(B_Node* parent)
{
    for (auto i = parent->children.begin(); i < parent->children.end(); i++)
    {
        if (*i == this)
        {
            return std::make_pair((i != parent->children.begin()) ? *(i - 1) : *i,
                (i != --parent->children.end()) ? *(i + 1) : *i);

        }
    }
    return std::make_pair(nullptr, nullptr);
}


void B_Node::shift_right(unsigned M)
{
    for (size_t i = this->key.size(); i > 0; i--)
    {
        if (this->key.size() < M - 1)
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
            this->root->children[i + 1]->search(key);
            break;
        }
    }
    return nullptr;

}

int B_Tree::delete_data(int key)
{
    delete_data(key, root, root);
    return 0;
}

