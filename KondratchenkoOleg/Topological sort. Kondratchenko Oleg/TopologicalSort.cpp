#include <iostream> 
#include <locale.h>
#include <list> 
#include <stack> 
using namespace std;

class Graph
{
    // Количество вершин
    int Vertex;
    // Указатель смежности
    list<int> *adj_list;
    public:
        // Конструктор
        Graph(int vertex);
        // Рекурсивная функция обхода в глубину
        void dfs(int vertex, bool visited[], stack<int>& Stack);
        // Сортировка
        void topologicalSort();
        // Добавление узла в граф
        void addEdge(int vertex, int w);
        // Вывод вершин после сортировки
        // из стека
        void printEdge(stack<int>& Stack);
        ~Graph()
        {;}
};

Graph::Graph(int vertex)
{
    this->Vertex = vertex;
    adj_list = new list<int>[Vertex];
}

// Создание графа путем соединения вершин
// в порядке vertex -> edge
void Graph::addEdge(int vertex, int edge)
{
    adj_list[vertex].push_back(edge);
}

void Graph::dfs(int vertex, bool visited[], stack<int>& Stack)
{
    // После входа в тело функции
    // отмечаем вершину как посещенная
    visited[vertex] = true;

    list<int>::iterator i;
    for (i = adj_list[vertex].begin(); i != adj_list[vertex].end(); ++i)
    {
        if (!visited[*i])
        {
            dfs(*i, visited, Stack);
        }
    }
    //Заносим в стек вершину
    Stack.push(vertex);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    bool* visited = new bool[Vertex];

    // Обнуление посещения вершин
    for (int i = 0; i < Vertex; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < Vertex; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, visited, Stack);
        }
    }
    // Вывод отсортированных вершин
    printEdge(Stack);
}

void Graph::printEdge(stack<int>& Stack)
{
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Graph testGraph(7);
    testGraph.addEdge(6, 3);
    testGraph.addEdge(6, 2);
    testGraph.addEdge(2, 3);
    testGraph.addEdge(2, 1);
    testGraph.addEdge(3, 4);
    testGraph.addEdge(1, 4);
    testGraph.addEdge(1, 0);
    testGraph.addEdge(4, 5);
    testGraph.addEdge(5, 0);
    cout << "Отсортированный граф с помощью топологической сортировки: \n";
    testGraph.topologicalSort();
}