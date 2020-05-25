#include <iostream>

constexpr auto t = 2;

class BNode {
public:
    bool leaf;
    int numberOfKeys;
    int keys[2*t-1];
    BNode* children[2*t];

    void splitChild(int indexInChildrenArray, BNode* nodeForSplit);
    void insertNonFull(int key);
    int findKey(int key);

    BNode(bool leaf_) {
        leaf = leaf_;
        numberOfKeys = 0;

        for (int i=0; i<(2*t-1); i++) {
            keys[i] = 0;                
        }

        for (int i = 0; i < 2 * t; i++) {
            children[i] = nullptr;
        }
    }
};


class BTree {
public:
    BNode* root;

    BTree() {
        root = nullptr;
    }

    void addData(int key);
    BNode* search(int key, BNode* root);
	void traverse(BNode* root);
    void deleteData(int key);
};

void BTree::addData(int key) {
    if (root == nullptr) {
        root = new BNode(true);
        root->keys[0] = key;
        root->numberOfKeys = 1;
        return;
    }

    if (root->numberOfKeys == (2 * t - 1)) {
        BNode* tempRoot = new BNode(false);
        tempRoot->children[0] = root;
        tempRoot->splitChild(0, root);

        if (key > tempRoot->keys[0]) tempRoot->children[1]->insertNonFull(key);
        else tempRoot->children[0]->insertNonFull(key);

        root = tempRoot;
    }
    else root->insertNonFull(key);
}

BNode* BTree::search(int key, BNode* root) {

	int counter = 0;

	while (counter<root->numberOfKeys && key>root->keys[counter]) counter++;

	if (root->keys[counter] == key) return root;
	if (root->leaf) return nullptr;

	return search(key, root->children[counter]);
}

void BTree::traverse(BNode* root) { // Проход от наименьшего ключа к наибольшему
	int counter=0;
	for (counter; counter < root->numberOfKeys; counter++) {
		if (root->leaf==false) traverse(root->children[counter]);
		std::cout << root->keys[counter]<<" ";
	}
	if (root->leaf==false) traverse(root->children[counter]);
}

int BNode::findKey(int key) {  // Находит позицию искомого ключа среди ключей узла
    int index_of_key = 0;      
    while (keys[index_of_key] < key && index_of_key<numberOfKeys ) {
        index_of_key++;
    }
    return 0;
}

void BTree::deleteData(int key) {
    BNode* node_that_lost_key = search(key, root);
    //Самый простой случай удаления: лист с достаточным количеством ключей
    //При необходимости попробую реализовать более сложные случаи
    if (node_that_lost_key->leaf && node_that_lost_key->numberOfKeys >= t) {
        int index_of_key = node_that_lost_key->findKey(key);
        for (int i = index_of_key + 1; i < node_that_lost_key->numberOfKeys; i++) {
            node_that_lost_key->keys[i - 1] = node_that_lost_key->keys[i];
        }
        node_that_lost_key->numberOfKeys--;
    }
}

void BNode::splitChild(int indexInChildrenArray, BNode* nodeForSplit) {
    BNode* newChild = new BNode(nodeForSplit->leaf);
    newChild->numberOfKeys = t - 1;

    for (int i=0; i < t - 1; i++) newChild->keys[i] = nodeForSplit->keys[i + t];
    if (nodeForSplit->leaf == false) {
        for (int i = 0; i < t; i++) newChild->children[i] = nodeForSplit->children[i + t];
    }
    
    nodeForSplit->numberOfKeys = t - 1;

    for (int i = numberOfKeys; i >= indexInChildrenArray + 1; i--) children[i + 1] = children[i]; //Смещение детей вправо для выделения места под нового ребенка
    children[indexInChildrenArray + 1] = newChild;
    
    for (int i = numberOfKeys-1; i >= indexInChildrenArray; i--) keys[i + 1] = keys[i];
    keys[indexInChildrenArray] = nodeForSplit->keys[t - 1];

    numberOfKeys++;
}

void BNode::insertNonFull(int key) {
    int currentIndex = numberOfKeys - 1;//индекс самого правого элемента

    if (leaf) {
        while (currentIndex >= 0 && keys[currentIndex] > key) {
            keys[currentIndex + 1] = keys[currentIndex];
            currentIndex--;
        }

        keys[currentIndex + 1] = key;
        numberOfKeys++;
    }
    else {
        while (currentIndex >= 0 && keys[currentIndex] > key) currentIndex--;

        if (children[currentIndex + 1]->numberOfKeys == 2 * t - 1) {
            splitChild(currentIndex + 1, children[currentIndex + 1]);
            if (keys[currentIndex + 1] < key) currentIndex++;
        }
        children[currentIndex + 1]->insertNonFull(key);
    }
}


int main() {
    BTree Tree;
    Tree.addData(50);
	Tree.addData(35);
	Tree.addData(24);
	Tree.addData(11);
	Tree.addData(43);
	Tree.addData(15);
	Tree.addData(34);
	Tree.traverse(Tree.root);
    std::cout << std::endl;


    Tree.addData(44);
    Tree.addData(8); 
    Tree.traverse(Tree.root);

	int a = 6; //Для точки останова
}