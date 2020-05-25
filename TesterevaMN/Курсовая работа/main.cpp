#include <iostream>
#include <string>

const int INF = 1e9;
const int ALP_SIZE = 256;
const int MAXN = 5000;

using namespace std;

int root;
int count_last_added_node;
int position;
int node_suffix_link;
int remainderr;                                      /// число явно добавляемых суффиксов.
/// Составляющие активной точки - узел, ребро, длина. По этим координатам добавляется новый суффикс.
int active_node, active_edge, active_length;

/// Структура, описывающая узел суффиксного дерева
struct Node {

	int start;                                       /// метка ребра - позиция самого правого элемента
	int end;                                         /// метка ребра - позиция самого левого элемента (для листа: inf)
	int suffix_link;                                 /// суффиксная ссылка
	int next_nodes[ALP_SIZE];                         /// массив прямых ссылок на следующие узлы/узел:
	                                                 /// для листа - заполнен нулями,
	                                                 /// для разветвления - код след символа -> номер следующего узла.
	int edge_length() {
		return (min(end, position + 1) - start);     /// расчёт длины ребра
	}
};

/// Инициализируем массив узлов - дерево
Node tree[2*MAXN];
/// Массив символов, добавленных в дерево - текст/строка
char text[MAXN];

/// Функция создания нового узла
int new_node(int start, int end = INF) {
	Node node{};
    node.start = start;
    node.end = end;
    node.suffix_link = 0;
    for (int & i : node.next_nodes)
    {i = 0;}
    /// Записываем только что созданный узел в дерево
	tree[++count_last_added_node] = node;
	return count_last_added_node;
}

/// Первый символ ребра от активной точки
char symbol_active_edge() {
	return text[active_edge];
}

/// Добавление суффиксной ссылки в узел
void add_suffix_link(int node) {
	if (node_suffix_link > 0) tree[node_suffix_link].suffix_link = node;
    node_suffix_link = node;
}

/// Нужно ли спуститься на следующий узел дальше?
bool walk_down(int node) {
    /// В случае, если активная длина больше длины ребра активного узла, переход будет совершен
	if (active_length >= tree[node].edge_length()) {
        active_edge += tree[node].edge_length();
        active_length -= tree[node].edge_length();
		active_node = node;
		return true;
	}
	return false;
}

/// Функция для инициализации каждого нового суффиксного дерева
void suffix_tree_initialization() {
    node_suffix_link = 0; count_last_added_node = -1; position = -1;
    remainderr = 0; active_node = 0; active_edge = 0; active_length = 0;
	root = active_node = new_node(-1, -1);
}

/// Функция, добавляющая символ (букву) в суффиксное дерево
void suffix_tree_extend(char symbol) {
	text[++position] = symbol;
    node_suffix_link = 0;
    remainderr++;

	while(remainderr > 0) {
	    /// Если активная точка в узле, то активное ребро определяется добавляемым символом по его позиции
		if (active_length == 0) active_edge = position;
		/// Если от активной точки двигаться дальше по нужному символу невозможно...
		if (tree[active_node].next_nodes[symbol_active_edge()] == 0) {
		    /// ...создаём новый лист
			int leaf = new_node(position);
			/// Присваиваем прямую ссылку узлу на лист
			tree[active_node].next_nodes[symbol_active_edge()] = leaf;
			/// Добавляем к активному узлу, который стал развилкой, суффиксную ссылку
			add_suffix_link(active_node);

		///remainder == 0
		} else {

			int next_node = tree[active_node].next_nodes[symbol_active_edge()];
			if (walk_down(next_node)) continue;
			/// Если суффикс, который мы хотим добавить, уже существует в дереве
			if (text[tree[next_node].start + active_length] == symbol) {
                active_length++;                /// изменяем параметры активной точки
				add_suffix_link(active_node);   /// добавляем суффиксную ссылку в активный узел, если это необходимо
				break;
			}
			/// Создание разветвления
			int split = new_node(tree[next_node].start, tree[next_node].start + active_length);
			tree[active_node].next_nodes[symbol_active_edge()] = split;
			int leaf = new_node(position);
			tree[split].next_nodes[symbol] = leaf;
			tree[next_node].start += active_length;
			tree[split].next_nodes[text[tree[next_node].start]] = next_node;
			add_suffix_link(split);
		}
        remainderr--;

		/// Если активный узел - корень, но активная точка не в узле - изменяются параметры акт точки
		if (active_node == root && active_length > 0) {
            active_length--;
            active_edge = position - remainderr + 1;
        /// Если из акт узла (не корня при этом) произошла вставка
        /// (возможно лишь когда активная длина = 0, т.е. акт точка в узле)
        /// - сменить активный узел.
		} else
			active_node = tree[active_node].suffix_link > 0 ? tree[active_node].suffix_link : root;
	}
}

/// Функция для пользователя
void create_suffix_tree() {
    string my_string;
    cout << "Введите произвольную строку:  ";
    cin >> my_string;
    suffix_tree_initialization();
    for(char i : my_string)
        suffix_tree_extend(i);
    suffix_tree_extend('$');
}

int main() {
    create_suffix_tree();
    create_suffix_tree();
    return 0;
}