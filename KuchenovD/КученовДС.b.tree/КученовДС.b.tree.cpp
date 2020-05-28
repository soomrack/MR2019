#include <iostream>
using namespace std;

class node
{
private:
  int* keys;
  node** childPtrs;
  int numKeys;
  int t;
  bool leaf;

public:
  node(int t_pass, bool _leaf);
  void print();
  node* key_search(int key);
  void deletion(int key);
  int find_key(int key);
  void insert_not_full(int key);
  void split_the_child(int i, node* y);
  void deletion_from_leaf(int ind);
  void deletion_from_not_leaf(int ind);
  int get_previous(int ind);
  int get_next(int ind);
  void fill(int ind);
  void get_from_previous(int ind);
  void get_from_next(int ind);
  void merge(int ind);
  friend class BT;
};

class BT
{
private:
  node* root;
  int t;

public:
  BT(int t_pass)
  {
    root = NULL;
    t = t_pass;
  }
  void print()
  {
    if (root != NULL) root->print();
  }
  node* key_search(int key)
  {
    return (root == NULL) ?
      NULL : root->key_search(key);
  }
  void add_leaf(int key);
  void deletion(int key);
};

int main()
{
  setlocale(LC_ALL, "Russian");

  int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
  BT bTree(3);

  for (int i = 0; i < 16; i++)
  {
    bTree.add_leaf(TreeKeys[i]);
  }

  cout << "Вывод дерева: \n";
  cout << endl;
  bTree.print();
  cout << endl;
  cout << endl;

  bTree.add_leaf(16);
  bTree.add_leaf(17);
  bTree.add_leaf(54);
  bTree.add_leaf(20);
  bTree.add_leaf(23);

  bTree.deletion(14);
  cout << "Вывод дерева после удаления элемента 14:\n";
  cout << endl;
  bTree.print();
  cout << endl;
  cout << endl;

  int val, opt, key;
  while (true)
  {
    cout << endl;
    cout << "1. Добавление\n2. Удаление\n";
    cout << "3. Поиск\n4. Вывод дерева\n";
    cout << "5. Выход\n\nВведите номер варианта: ";
    cin >> opt;
    cout << endl;

    switch (opt) {
    case 1:
      cout << "Какой элемент вы хотите добавить: ";
      cin >> val;
      bTree.add_leaf(val);
      break;
    case 2:
      cout << "Введите элемент, который хотите удалить: ";
      cin >> val;
      bTree.deletion(val);
      break;
    case 3:
      cout << "Введите элемент, который хотите найти: ";
      cin >> key;
      (bTree.key_search(key) != NULL) ?
        cout << endl << "Элемент " << key << " найден" << endl
        : cout << endl << "Элемент " << key << " не найден" << endl;
      break;
    case 4:
      bTree.print();
      break;
    case 5:
      exit(0);
    }
    cout << endl;
  }

  return 0;
}


node::node(int t1, bool leaf1)
{
  t = t1;
  leaf = leaf1;
  keys = new int[2 * t - 1];
  childPtrs = new node * [2 * t];
  numKeys = 0;
}

int node::find_key(int key)
{
  int ind = 0;
  while (ind < numKeys && keys[ind] < key)
  {
    ind++;
  }
  return ind;
}

void node::deletion(int key)
{
  int ind = find_key(key);
  if (ind < numKeys && keys[ind] == key)
  {
    if (leaf)
    {
      deletion_from_leaf(ind);
    }
    else
    {
      deletion_from_not_leaf(ind);
    }
  }
  else
  {
    if (leaf)
    {
      cout << "Элемента " << key << " нет в дереве\n";
      return;
    }
    bool flag = ((ind == numKeys) ? true : false);
    if (childPtrs[ind]->numKeys < t)
    {
      fill(ind);
    }
    if (flag && ind > numKeys)
    {
      childPtrs[ind - 1]->deletion(key);
    }
    else
    {
      childPtrs[ind]->deletion(key);
    }
  }
  return;
}

void node::deletion_from_leaf(int ind)
{
  for (int i = ind + 1; i < numKeys; ++i)
  {
    keys[i - 1] = keys[i];
  }
  numKeys--;
  return;
}

void node::deletion_from_not_leaf(int ind)
{
  int key = keys[ind];
  if (childPtrs[ind]->numKeys >= t)
  {
    int prev = get_previous(ind);
    keys[ind] = prev;
    childPtrs[ind]->deletion(prev);
  }
  else if (childPtrs[ind + 1]->numKeys >= t)
  {
    int next = get_next(ind);
    keys[ind] = next;
    childPtrs[ind + 1]->deletion(next);
  }
  else
  {
    merge(ind);
    childPtrs[ind]->deletion(key);
  }
  return;
}

int node::get_previous(int ind)
{
  node* cur = childPtrs[ind];
  while (!cur->leaf)
  {
    cur = cur->childPtrs[cur->numKeys];
  }
  return cur->keys[cur->numKeys - 1];
}

int node::get_next(int ind)
{
  node* cur = childPtrs[ind + 1];
  while (!cur->leaf)
  {
    cur = cur->childPtrs[0];
  }
  return cur->keys[0];
}

void node::fill(int ind)
{
  if (ind != 0 && childPtrs[ind - 1]->numKeys >= t)
  {
    get_from_previous(ind);
  }
  else if (ind != numKeys && childPtrs[ind + 1]->numKeys >= t)
  {
    get_from_next(ind);
  }
  else
  {
    if (ind != numKeys)
    {
      merge(ind);
    }
    else
    {
      merge(ind - 1);
    }
  }
  return;
}

void node::get_from_previous(int ind)
{
  node* child = childPtrs[ind];
  node* brother = childPtrs[ind - 1];
  for (int i = child->numKeys - 1; i >= 0; --i)
  {
    child->keys[i + 1] = child->keys[i];
  }
  if (!child->leaf)
  {
    for (int i = child->numKeys; i >= 0; --i)
    {
      child->childPtrs[i + 1] = child->childPtrs[i];
    }
  }
  child->keys[0] = keys[ind - 1];
  if (!child->leaf)
  {
    child->childPtrs[0] = brother->childPtrs[brother->numKeys];
  }
  keys[ind - 1] = brother->keys[brother->numKeys - 1];
  child->numKeys += 1;
  brother->numKeys -= 1;
  return;
}

void node::get_from_next(int ind)
{
  node* child = childPtrs[ind];
  node* brother = childPtrs[ind + 1];
  child->keys[(child->numKeys)] = keys[ind];
  if (!(child->leaf))
  {
    child->childPtrs[(child->numKeys) + 1] = brother->childPtrs[0];
  }
  keys[ind] = brother->keys[0];
  for (int i = 1; i < brother->numKeys; ++i)
  {
    brother->keys[i - 1] = brother->keys[i];
  }
  if (!brother->leaf)
  {
    for (int i = 1; i <= brother->numKeys; ++i)
    {
      brother->childPtrs[i - 1] = brother->childPtrs[i];
    }
  }
  child->numKeys += 1;
  brother->numKeys -= 1;
  return;
}

void node::merge(int ind)
{
  node* child = childPtrs[ind];
  node* brother = childPtrs[ind + 1];
  child->keys[t - 1] = keys[ind];
  for (int i = 0; i < brother->numKeys; ++i)
  {
    child->keys[i + t] = brother->keys[i];
  }
  if (!child->leaf)
  {
    for (int i = 0; i <= brother->numKeys; ++i)
    {
      child->childPtrs[i + t] = brother->childPtrs[i];
    }
  }
  for (int i = ind + 1; i < numKeys; ++i)
  {
    keys[i - 1] = keys[i];
  }
  for (int i = ind + 2; i <= numKeys; ++i)
  {
    childPtrs[i - 1] = childPtrs[i];
  }
  child->numKeys += brother->numKeys + 1;
  numKeys--;
  delete(brother);
  return;
}

void BT::add_leaf(int key)
{
  if (root == NULL)
  {
    root = new node(t, true);
    root->keys[0] = key;
    root->numKeys = 1;
  }
  else
  {
    if (root->numKeys == 2 * t - 1)
    {
      node* s = new node(t, false);
      s->childPtrs[0] = root;
      s->split_the_child(0, root);
      int i = 0;
      if (s->keys[0] < key)
      {
        i++;
      }
      s->childPtrs[i]->insert_not_full(key);
      root = s;
    }
    else
    {
      root->insert_not_full(key);
    }
  }
}

void node::insert_not_full(int key)
{
  int i = numKeys - 1;
  if (leaf == true)
  {
    while (i >= 0 && keys[i] > key)
    {
      keys[i + 1] = keys[i];
      i--;
    }
    keys[i + 1] = key;
    numKeys = numKeys + 1;
  }
  else
  {
    while (i >= 0 && keys[i] > key)
    {
      i--;
    }
    if (childPtrs[i + 1]->numKeys == 2 * t - 1)
    {
      split_the_child(i + 1, childPtrs[i + 1]);
      if (keys[i + 1] < key)
      {
        i++;
      }
    }
    childPtrs[i + 1]->insert_not_full(key);
  }
}

void node::split_the_child(int i, node* y)
{
  node* z = new node(y->t, y->leaf);
  z->numKeys = t - 1;
  for (int j = 0; j < t - 1; j++)
  {
    z->keys[j] = y->keys[j + t];
  }
  if (y->leaf == false)
  {
    for (int j = 0; j < t; j++)
    {
      z->childPtrs[j] = y->childPtrs[j + t];
    }
  }
  y->numKeys = t - 1;
  for (int j = numKeys; j >= i + 1; j--)
  {
    childPtrs[j + 1] = childPtrs[j];
  }
  childPtrs[i + 1] = z;
  for (int j = numKeys - 1; j >= i; j--)
  {
    keys[j + 1] = keys[j];
  }
  keys[i] = y->keys[t - 1];
  numKeys = numKeys + 1;
}

void node::print()
{
  int i;
  for (i = 0; i < numKeys; i++)
  {
    if (leaf == false)
    {
      childPtrs[i]->print();
    }
    cout << " " << keys[i];
  }
  if (leaf == false)
  {
    childPtrs[i]->print();
  }
}

node* node::key_search(int key)
{
  int i = 0;
  while (i < numKeys && key > keys[i])
  {
    i++;
  }
  if (keys[i] == key)
  {
    return this;
  }
  if (leaf == true)
  {
    return NULL;
  }
  return childPtrs[i]->key_search(key);
}

void BT::deletion(int key)
{
  if (!root)
  {
    cout << "Дерево пустое\n";
    return;
  }
  root->deletion(key);
  if (root->numKeys == 0)
  {
    node* tmp = root;
    if (root->leaf)
    {
      root = NULL;
    }
    else
    {
      root = root->childPtrs[0];
    }
    delete tmp;
  }
  return;
}


