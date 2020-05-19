#include <iostream>

using namespace std;


class Graf // создаем класс граф
{
private:
    int MaxNodes; // максимальное кол-во узлов
    int* nodes; // массив узлов для "раскраски"
    int num_peak; // кол-во вершин
    int num_edge; // кол-во ребер
    int Last_peak; // цвет последней "окрашеной" вершины
   
    struct knot // структура узла
    {
        int v1;
        int v2;
        int weight;
    }*knots;
public:
    Graf();
    void InitGraf(); // функция задающая граф
    void sort(); // сортировка ребер по возрастанию
    int GetColor(int n); // получает "цвет" ребра,n - номер вершины
    void OutTree(); // вывод дерева на экран

};


Graf::Graf() // конструктор
{
    MaxNodes = 50;
    nodes = new int[MaxNodes];
    knots = new knot[MaxNodes];
    num_peak = 0;
    num_edge = 0;
    Last_peak = 0;
}


void Graf::InitGraf() // функция, задающая граф
{
    setlocale(LC_ALL, "Russian");
    cout << "Ввидите число вершин" << endl;
    cin >> num_peak;
    cout << endl
        << "Введите число ребер" << endl;
    cin >> num_edge;

    
    for (int i = 0; i < num_peak; i++) // задаем начальные "цвета" вершинам
        nodes[i] = -1 - i;
    cout << endl
        << "Колличество ребер : " << num_edge << endl
        << "Введите их в формате : вершина 1, вершина 2, вес"
        << endl;
    for (int i = 0; i < num_edge; i++)
    {
        cout << endl << "Вершина 1 = "; cin >> knots[i].v1;
        cout << "Вершина 2 = "; cin >> knots[i].v2;
        cout << "Вес = "; cin >> knots[i].weight;
    }
    cout << endl << "Граф задан" << endl;
}


void Graf::sort() // фунция, сортирующая ребра графа по весу, начиная с наименьшего
{
    knot tmp; // обьект типа узел
    
    for (int i = 0; i < num_edge - 1; i++) // пузырьковая сортировка
        for (int j = 0; j < num_edge - 1; j++)
            if (knots[j].weight > knots[j + 1].weight)
            {
                tmp = knots[j];
                knots[j] = knots[j + 1];
                knots[j + 1] = tmp;
            }

}


int Graf::GetColor(int n) // функция, получающая "цвет" ребра; параметры: n - номер вершины
{
    if (nodes[n] < 0) // если "цвет" вершины с номером n - отрицательный, то...
    {
        Last_peak = n; // "цвет" последней окрашенной вершины
        return nodes[Last_peak]; // возвращаем его
    }
    else
    {
        int color;
        color = GetColor(nodes[n]); // получаем "цвет" вершины с номером n
        nodes[n] = Last_peak; // "окрашиваем" его в "цвет" вершины, с которой объединяем
        return color; // возвращаем "цвет"
    }
}


void Graf::OutTree() // функция, выводящая дерево на экран
{
    sort();
    setlocale(LC_ALL, "Russian");

    cout << "Минимальное остовное дерево состоит из ребер с весами " << endl; // сортируем ребра по возрастанию
    for (int i = 0; i < num_edge; i++)
    {
        int color1 = GetColor(knots[i].v2); // получаем "цвет" второй вершины
        int color2 = GetColor(knots[i].v1); // получаем "цвет" первой вершины

        if (color2 != color1) // если ребро соединяет вершины различных "цветов", то...
        {
            nodes[Last_peak] = knots[i].v2; // ..."перекрашиваем" вершины в "цвет" ребра
            cout << endl // добавляем вершину в минимальное остовное дерево
                << knots[i].weight;
            cout << "\n";
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    Graf graf;
    int c = 1;

    while (c != 3)
    {

        cout << "Операции" << endl;
        cout << "1. Задать граф" << endl;
        cout << "2. Построить дерево" << endl;
        cout << "3. Выход" << endl;
        cout << ">> " << endl;

        cin >> c;

        switch (c)
        {
        case 1:
            graf.InitGraf();
            break;

        case 2:
            graf.OutTree();
            break;

        case 3:
            break;

        default:
            cout << endl << "Неверный выбор" << endl;
            break;
        }
    }
    return(1);
}