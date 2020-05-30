#include <iostream>
using namespace std;
const int t = 2; ///минимальная степень

class B_Node {
public:
    int keys[(2 * t - 1)]{};
    B_Node *children[(2 * t)]{};
    int count;
    bool leaf;
    explicit B_Node(int key);
};

B_Node::B_Node(int key) {
    this->keys[0] = key;
    for (int i = 1; i < (2 * t - 1); i++)
        this->keys[i] = 0;
    for (auto & i : this->children)
        i = nullptr;
    this->leaf = true;
    this->count = 1;
}

class B_Tree {
public:
    B_Node* root;
    B_Tree() { root = nullptr; }

    void ADD(int key);
    static B_Node* FIND(int key, B_Node* root);
    void REMOVE(int key);
    static void PRINT(B_Node* root);
private:
    static void simple_insert(int key, B_Node* node);
    static void sort(B_Node *node);
    void restruct(B_Node* node);
    static B_Node* find_parent(B_Node* node, B_Node* root);
};

void B_Tree::ADD(int key) {
    if (root == nullptr) {
        root = new B_Node(key);
        return;
    }
    B_Node *temp = root;
    while (!temp->leaf) {
        for (int i = 0; i < (2 * t - 1); i++) {
            if (temp->keys[i] != 0) {
                if (key < temp->keys[i]) {
                    temp = temp->children[i];
                    break;
                }
                if ((temp->keys[i+1] == 0) && (key > temp->keys[i])) {
                    temp = temp->children[i + 1];
                    break;
                }
            }
            else
                break;
        }
    }
    simple_insert(key, temp);
    B_Node* temp_parent = find_parent(temp, root);
    while (temp->count >= (2*t-1)) {
        if (temp == root)
            restruct(temp);
        else {
            restruct(temp);
            temp = temp_parent;
        }
    }
}

void B_Tree::simple_insert(int key, B_Node* node) {
    node->keys[node->count] = key;
    node->count = node->count + 1;
    sort(node);
}

void B_Tree::sort(B_Node* node) {
    int temp;
    for (int i = 0; i < (node->count); i++) {
        for (int j = i + 1; j < (node->count); j++) {
            if (node->keys[i] > node->keys[j]) {
                temp = node->keys[i];
                node->keys[i] = node->keys[j];
                node->keys[j] = temp;
            }
        }
    }
}

B_Node* B_Tree::FIND(int key, B_Node* root) {
    for (int i = 0; i < (root->count); i++) {
        if (root->keys[i] == key)
            return root;
    }
    for (int i = 0; i < (root->count); i++) {
        if (key < root->keys[i])
            return FIND(key, root->children[i]);
        if ((key > root->keys[i]) && (root->count = (i + 1)))
            return FIND(key, root->children[i + 1]);
    }
    return nullptr;
}

void B_Tree::restruct(B_Node* node) {
    auto* new_child1 = new B_Node(0);
    new_child1->count = 0;
    auto* new_child2 = new B_Node(0);
    new_child2->count = 0;

    for (int i = 0; i < (t - 1); i++) {
        new_child1->keys[i] = node->keys[i];
        new_child2->keys[i] = node->keys[i + t];
    }
    new_child1->count = t - 1;
    new_child2->count = t - 1;
    if (node->children[0] != nullptr) {
        for (int i = 0; i <= (t - 1); i++) {
            new_child1->children[i] = node->children[i];
            new_child2->children[i] = node->children[i + t];
        }
        new_child1->leaf = false;
        new_child2->leaf = false;
    }

    if (node == root) {
        node->keys[0] = node->keys[t-1];
        for (int i = 1; i < (2 * t - 1); i++)
            node->keys[i] = 0;
        node->count = 1;
        node->children[0] = new_child1;
        node->children[1] = new_child2;
        for (int i = 2; i < (2 * t); i++)
            node->children[i] = nullptr;
        node->leaf = false;
    }
    else {
        B_Node* parent_node = find_parent(node, root);
        simple_insert(node->keys[t - 1], parent_node);
        for (auto & i : parent_node->children) {
            if (i == node)
                i = nullptr;
        }
        for (int i = 0; i < (2 * t); i++) {
            if (parent_node->children[i] == nullptr) {
                for (int j = (2 * t - 1); j > (i + 1); j--)
                    parent_node->children[j] = parent_node->children[j - 1];
                parent_node->children[i + 1] = new_child2;
                parent_node->children[i] = new_child1;
                break;
            }
        }
        parent_node->leaf = false;
    }
}

B_Node* B_Tree::find_parent(B_Node* node, B_Node* root) {
    for (auto & i : root->children) {
        if (i == node)
            return root;
    }
    for (auto & i : root->children) {
        if (i != nullptr)
            find_parent(node, i);
    }
    return nullptr;
}

void B_Tree::REMOVE(int key) {
    B_Node* node_for_delete = FIND(key, root);
    if ((node_for_delete->leaf = true) && (node_for_delete->count = t)) { // если узел был листом и при удалении у него останется t-1 ключей
        for (int i = 0; i < (node_for_delete->count); i++) {
            if (node_for_delete->keys[i] == key) {
                for (int j = i; j < (node_for_delete->count); j++)
                    node_for_delete->keys[j] = node_for_delete->keys[j + 1];
                node_for_delete->count = node_for_delete->count - 1;
            }
        }
    }
}

void B_Tree::PRINT(B_Node* root) {
    if (root == nullptr)
        return;
    for (int i = 0; i < (2 * t - 1); i++) {
        if (root->count > i)
            cout << root->keys[i] << ",";
    }
    cout << '\n';
    for (auto & i : root->children) {
        if (i != nullptr)
            PRINT(i);
    }
}

int main() {
    B_Tree tree1 = B_Tree();

    tree1.ADD(5);
    tree1.ADD(9);
    tree1.ADD(12);
    tree1.PRINT(tree1.root);
    cout << endl;
    tree1.REMOVE(12);
    tree1.PRINT(tree1.root);

    return 0;
}