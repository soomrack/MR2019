#include <iostream>
#include <list> 
#include <iterator> 
#include <queue>



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
		, left(nullptr)
		, right(nullptr)
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
private:

	Node * root;

	Node * add_data(void* data, const int key, Node* root)
	{
		Node* child = new Node(data, key);
		if (root == nullptr)
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



	void depth_traversal(Node* root, std::list<int>& list)
	{

		if (root == nullptr)
			return;

		list.push_back(root->key);
		depth_traversal(root->left, list);
		depth_traversal(root->right, list);

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
		if (node == nullptr || root == nullptr )
			return 0;

		
		if (node == root->right || node == root->left) {
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

		
		while (current_node && current_node->left != nullptr)
			current_node = current_node->left;

		return current_node;
	}



	void delete_data(const int key)
	{
		Node* del_node = search(this->root, key);
		Node* new_node;
		Node* parent_del_node;

		if (root == nullptr)
			std::cout << "Tree is empty";

		else if (del_node->left == nullptr)
		{
			new_node = del_node->right;
			parent_del_node = findParent(del_node, root);
			parent_del_node->right = new_node;
			delete del_node;
		}

		else if (del_node->right == nullptr)
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
			
			if(new_node != del_node->left)
				new_node->left = del_node->left;

			new_node->right = del_node->right;
			parent_del_node->right = new_node;
			parent_new_node->right = new_node->right;
			delete del_node;
		}

	}


	std::list<int> depth_traversal()
	{
		std::list<int> list_key;

		if (root->key == 0 || root == nullptr)
			return list_key;

		list_key.push_back(root->key);
		depth_traversal(root->left, list_key);
		depth_traversal(root->right, list_key);
		return list_key;
	}

	std::queue<int> width_traversal()
	{
		std::queue<Node*> queue_node;
		std::queue<int> queue_key;
		std::vector<bool> used;

		if (root == nullptr)
			return queue_key;

		queue_node.push(root);
		
		while (!queue_node.empty())
		{
			Node* tmp_node = queue_node.front();
			queue_key.push(tmp_node->key);
			queue_node.pop();

			if (tmp_node->left != nullptr)
				queue_node.push(tmp_node->left);

			
			if (tmp_node->right != nullptr)
				queue_node.push(tmp_node->right);
		}

		return queue_key;
	}


	void print(std::list<int> list)
	{
		std::list<int>::iterator it;
		for (it = list.begin(); it != list.end(); ++it)
			std::cout << '\t' << *it;
		std::cout << '\n';
	}
	void print(std::queue<int> queue)
	{
		while (!queue.empty())
		{
			std::cout << '\t' << queue.front();
			std::cout << '\n';
			queue.pop();
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
	//tree.delete_data(25);
	tree.print(tree.width_traversal());
	
	system("pause");

	return 0;


}
