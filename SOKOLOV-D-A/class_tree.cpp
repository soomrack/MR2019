#include <iostream>




class Node
{
public:
	int key;
	void* data;
	Node* left;
	Node* right;
	Node()
		: key(0)
		, data(nullptr)
		, left(nullptr)
		, right(nullptr) {}

	Node(void *data, int key)
		: key(key)
		, data(new void* (data))
		, left(new Node())
		, right(new Node())
	{}
	Node(const Node& other)
		: key(other.key)
		, data(new void*(other.data))
		, left(other.left)
		, right(other.right)
	{}

	~Node() { }

};


class Tree : public Node
{
	Node * root;

	Node * add_data(void* data, const int key, Node* root)
	{
		Node* child = new Node(data, key);
		if (root->key == 0)
		{
			root = child;
			return root;
		}

		if (key <= root->key)
		{
			root->left = add_data(data, key, root->left);
		}

		else if (key > root->key)
		{
			root->right = add_data(data, key, root->right);
		}
		return root;

	}

	Node* repairTree(Node* root)
	{
		if (root->right != nullptr)
		{
			 root = root->right;
			 return root;
		}
			
		else
		{
			root = root->left;
			return root;
		}
			
	}
public:
	Tree()
	{
		this->root = nullptr;
	}

	~Tree() {}


	Node* search(Node* root, int key)
	{
		if (root == nullptr || root->key == key)
			return root;

		if (root->key <= key)
			return search(root->right, key);

		return search(root->left, key);
	}


	Node* findParent(Node* node, Node* root)
	{
		if (node == NULL)
			return 0;

		
		if (node == root->right || node == root->left) {
			std::cout << "parent";
			return root;
		}

		else {
			findParent(node, root->left);
			findParent(node, root->right);
		}
	}


	int add_data(void* data, const int key)
	{
		Node* child = new Node(data, key);

		if (this->root == nullptr )
		{
			this->root = child;
			return 1;
		}
		if (key <= this->root->key)
		{
			this->root->left = add_data(data, key, this->root->left);
		}

		else if (key > this->root->key)
		{
			this->root->right = add_data(data, key, this->root->right);
		}
		return 1;

		
	}


	Node* minValueNode(Node* node)
	{
		Node* current_node = node;

		
		while (current_node && current_node->left != NULL)
			current_node = current_node->left;

		return current_node;
	}


	//Могут быть ошибки, не доделал) каюсь!

	void delete_data(const int key)
	{
		Node* del_node = search(this->root, key);
		Node* new_node;
		Node* parent_del_node;

		if (root == nullptr)
			std::cout << "Tree is empty";

		else if (del_node->left->key == 0)
		{
			new_node = del_node->right;
			parent_del_node = findParent(del_node, root);
			parent_del_node->right = new_node;
			delete del_node;
		}

		else if (del_node->right->key == 0)
		{
			new_node = del_node->left;
			parent_del_node = findParent(del_node, root);
			parent_del_node->left = new_node;
			delete del_node;
		}

		else
		{
			new_node = minValueNode(del_node);
			Node* parent_new_node = findParent(new_node, root);
			parent_del_node = findParent(del_node, root);
			
			new_node->left = del_node->left;
			new_node->right = del_node->right;
			parent_del_node->left = new_node;
			parent_new_node->left = new_node->right;
			delete del_node;
		}

	}
};





int main()
{
	//bin tree
	int a = 5;
	int b = 5 * 5;
	int c = 6;
	int d = 9;
	int j = 66;
	Tree tree;
	tree.add_data(&a, 5);
	tree.add_data(&b,25);
	tree.add_data(&c, 4);
	tree.add_data(&d, 50);
	tree.add_data(&j, 23);
	tree.delete_data(25);
	
	system("pause");



	return 0;


}
