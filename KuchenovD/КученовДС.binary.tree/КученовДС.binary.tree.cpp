#include <iostream>
using namespace std;

class BST
{
  private:
    struct node
    {
      int key;
      node* left;
      node* right;
    };
    node* root;
    void add_leaf_private(int key, node* Ptr);
    void print_in_order_private(node* Ptr);
    node* return_node_private(int key, node* Ptr);
    int find_smallest_private(node* Ptr);
    void remove_node_private(int key, node* parent);
    void remove_root_match();
    void remove_match(node* parent, node* match, bool left);
    node* create_leaf(int key);
    node* return_node(int key);
    void remove_subtree(node* Ptr);

  public:
    BST();
    ~BST();
    void add_leaf(int key);
    void print_in_order();
    int return_root_key();
    void print_children(int key);
    int find_smallest();
    void remove_node(int key);
};


int main()
{
  setlocale(LC_ALL, "Russian");

  int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
  BST bin_tree;

  cout << "Вывод дерева в порядке возрастания до добавления элементов:\n";
  cout << endl;

  bin_tree.print_in_order();
  cout << endl;

  for (int i = 0; i < 16; i++)
  {
    bin_tree.add_leaf(TreeKeys[i]);
  }

  bin_tree.add_leaf(1000);
  bin_tree.add_leaf(599);

  cout << "Вывод дерева в порядке возрастания после добавления элементов:\n";
  cout << endl;

  bin_tree.print_in_order();
  cout << endl;
  cout << endl;

  for (int i = 0; i < 16; i++)
  {
    bin_tree.print_children(TreeKeys[i]);
    cout << endl;
  }

  bin_tree.print_children(1000);
  cout << endl;

  cout << "Наименьший элемент в дереве: " << bin_tree.find_smallest();
  cout << endl;

  int input = 0;
  while (input != -1)
  {
    cout << "Удалить узел: ";
    cin >> input;
    {
      if (input != -1)
      {
        cout << endl;
        bin_tree.remove_node(input);
        bin_tree.print_in_order();
        cout << endl;
      }
    }
  }
  return 0;
}


BST::BST()
{
  root = NULL;
}
BST::node* BST::create_leaf(int key)
{
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void BST::add_leaf(int key)
{
  add_leaf_private(key, root);
}

void BST::add_leaf_private(int key, node* Ptr)
{
  if (root == NULL)
  {
    root = create_leaf(key);
  }
  else if (key < Ptr->key)
  {
    if (Ptr->left != NULL)
    {
      add_leaf_private(key, Ptr->left);
    }
    else
    {
      Ptr->left = create_leaf(key);
    }
  }
  else if (key > Ptr->key)
  {
    if (Ptr->right != NULL)
    {
      add_leaf_private(key, Ptr->right);
    }
    else
    {
      Ptr->right = create_leaf(key);
    }
  }
  else
  {
    cout << "Ключ " << key << " уже был добавлен в дерево\n " << endl;
  }
}

void BST::print_in_order()
{
  print_in_order_private(root);
}

void BST::print_in_order_private(node* Ptr)
{
  if (root != NULL)
  {
    if (Ptr->left != NULL)
    {
      print_in_order_private(Ptr->left);
    }
    cout << Ptr->key << " ";
    if (Ptr->right != NULL)
    {
      print_in_order_private(Ptr->right);
    }
  }
  else
  {
    cout << "Дерево пустое\n";
  }
}

BST::node* BST::return_node(int key)
{
  return return_node_private(key, root);
}

BST::node* BST::return_node_private(int key, node* Ptr)
{
  if (Ptr != NULL)
  {
    if (Ptr->key == key)
    {
      return Ptr;
    }
    else
    {
      if (key < Ptr->key)
      {
        return return_node_private(key, Ptr->left);
      }
      else
      {
        return return_node_private(key, Ptr->right);
      }
    }
  }
  else
  {
    return NULL;
  }
}

int BST::return_root_key()
{
  if (root != NULL)
  {
    return root->key;
  }
  else
  {
    return -10000;
  }
}

void BST::print_children(int key)
{
  node* Ptr = return_node(key);

  if (Ptr != NULL)
  {
    cout << "Родительский узел = " << Ptr->key << endl;

    Ptr->left == NULL ?
      cout << "Левый потомок = NULL\n" :
      cout << "Левый потомок = " << Ptr->left->key << endl;

    Ptr->right == NULL ?
      cout << "Правый потомок = NULL\n" :
      cout << "Правый потомок = " << Ptr->right->key << endl;
  }
  else
  {
    cout << "Ключа " << key << " нет в дереве\n";
  }
}

int BST::find_smallest()
{
  return find_smallest_private(root);
}

int BST::find_smallest_private(node* Ptr)
{
  if (root == NULL)
  {
    cout << "Дерево пустое\n";
    return -10000;
  }
  else
  {
    if (Ptr->left != NULL)
    {
      return find_smallest_private(Ptr->left);
    }
    else
    {
      return Ptr->key;
    }
  }
}

void BST::remove_node(int key)
{
  remove_node_private(key, root);
}

void BST::remove_node_private(int key, node* parent)
{
  if (root != NULL)
  {
    if (root->key == key)
    {
      remove_root_match();
    }
    else
    {
      if (key < parent->key && parent->left != NULL)
      {
        parent->left->key == key ?
          remove_match(parent, parent->left, true) :
          remove_node_private(key, parent->left);
      }
      else if (key > parent->key && parent->right != NULL)
      {
        parent->right->key == key ?
          remove_match(parent, parent->right, false) :
          remove_node_private(key, parent->right);
      }
      else
      {
        cout << "Ключа " << key << " нет в дереве!\n";
      }
    }
  }
  else
  {
    cout << "Дерево пустое\n";
  }
}

void BST::remove_root_match()
{
  if (root != NULL)
  {
    node* delPtr = root;
    int rootKey = root->key;
    int smallestInRightSubtree;
    // 0 потомков
    if (root->left == NULL && root->right == NULL)
    {
      root = NULL;
      delete delPtr;
    }
    // 1 потомок
    else if (root->left == NULL && root->right != NULL)
    {
      root = root->right;
      delPtr->right = NULL;
      delete delPtr;
      cout << "Корневой узел с ключом " << rootKey << " был удалён. " <<
      "Новый корень содержит ключ " << root->key << endl;
    }
    else if (root->left != NULL && root->right == NULL)
    {
      root = root->left;
      delPtr->left = NULL;
      delete delPtr;
      cout << "Корневой узел с ключом " << rootKey << " был удалён. " <<
      "Новый корень содержит ключ " << root->key << endl;
    }
    // 2 потомка
    else
    {
      smallestInRightSubtree = find_smallest_private(root->right);
      remove_node_private(smallestInRightSubtree, root);
      root->key = smallestInRightSubtree;
      cout << "Корневой ключ, содержащий ключ " << rootKey << " был перезаписан с ключом " << root->key << endl;
    }
  }
  else
  {
    cout << "Невозможно удалить корень. Дерево пустое\n";
  }
}

void BST::remove_match(node* parent, node* match, bool left)
{
  if (root != NULL)
  {
    node* delPtr;
    int matchKey = match->key;
    int smallestInRightSubtree;
    // 0 потомков
    if (match->left == NULL && match->right == NULL)
    {
      delPtr = match;
      left == true ? parent->left = NULL : parent->right = NULL;
      delete delPtr;
      cout << "Узел, содержащий ключ " << matchKey << " был удален\n";
    }
    // 1 потомок
    else if (match->left == NULL && match->right != NULL)
    {
      left == true ? parent->left = match->right : parent->right = match->right;
      match->right = NULL;
      delPtr = match;
      delete delPtr;
      cout << "Узел, содержащий ключ " << matchKey << " был удален\n";
    }
    else if (match->left != NULL && match->right == NULL)
    {
      left == true ? parent->left = match->left : parent->right = match->left;
      match->left = NULL;
      delPtr = match;
      delete delPtr;
      cout << "Узел, содержащий ключ " << matchKey << " был удален\n";
    }
    // 2 потомка
    else
    {
      smallestInRightSubtree = find_smallest_private(match->right);
      remove_node_private(smallestInRightSubtree, match);
      match->key = smallestInRightSubtree;
    }
  }
  else
  {
    cout << "Невозможно удалить. Дерево пустое\n";
  }
}
//Деструктор
BST::~BST()
{
  remove_subtree(root);
}

void BST::remove_subtree(node* Ptr)
{
  if (Ptr != NULL)
  {
    if (Ptr->left != NULL)
    {
      remove_subtree(Ptr->left);
    }
    if (Ptr->right != NULL)
    {
      remove_subtree(Ptr->right);
    }
    cout << "Удаление узла, содержащего ключ " << Ptr->key << endl;
    delete Ptr;
  }
}