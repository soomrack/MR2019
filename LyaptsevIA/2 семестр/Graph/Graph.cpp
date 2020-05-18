#include <iostream>
#include <vector>
using namespace std;
#define SIZE 9
#define INF 100000;


int FinalNode;
int Path[SIZE][SIZE] = { 0, 4, 0, 3, 0, 0, 0, 0, 0,
4, 0, 6, 0, 2, 0, 0, 0, 0,
0, 6, 0, 0, 0, 1, 0, 0, 0,
3, 0, 0, 0, 8, 0, 9, 0, 0,
0, 2, 0, 8, 0, 5, 0, 8, 0,
0, 0, 1, 0, 5, 0, 0, 0, 11,
0, 0, 0, 9, 0, 0, 0, 7, 0,
0, 0, 0, 0, 8, 0, 7, 0, 12,
0, 0, 0, 0, 0, 11 ,0 ,12 , 0 };;
int Lenght[SIZE];
bool isused[SIZE];
int Mark[SIZE];

void Dijkstra()
{
    bool IsOk = 1;
    while (IsOk)
    {
        int NextNode = 0;
        for (int i = 0; i < SIZE; i++)
        {
            IsOk = 0;
            if (!isused[i])
            {
                IsOk = 1;
                NextNode = i;
                break;
            }
        }
        if (!IsOk)
            break;
        for (int i = 0; i < SIZE; i++)
            if ((Mark[NextNode] > Mark[i]) && !(isused[i]))
                NextNode = i;
        for (int NodePath = 0; NodePath < SIZE; NodePath++)
        {
            if (isused[NodePath])
                continue;
            if ((Mark[NodePath] > (Mark[NextNode] + Path[NextNode][NodePath])) && (Path[NextNode][NodePath] != 0))
            {
                Mark[NodePath] = Mark[NextNode] + Path[NextNode][NodePath];
                Lenght[NodePath] = NextNode;
            }
        }
        isused[NextNode] = 1;
    }
    bool isFinal = 0;
    int CurrentNode = FinalNode;
    cout << endl << "Путь до нужного узла:" << endl;
    while (!isFinal) 
    {
        cout << CurrentNode << " -> ";
        CurrentNode = Lenght[CurrentNode];
        if (CurrentNode == 0)
        {
            isFinal = 1;
            cout << "0";
        }
    }
    
}

int main()
{
    setlocale(LC_ALL, "RUS");
    memset(isused, 0, SIZE);
    for (int i = 1; i < SIZE; i++)
        Mark[i] = INF;
    for (int i = 0; i < SIZE; i++)
        Lenght[i] = 0;
    //for (int i = 0; i < SIZE; i++)
    //{
    //    Path[i][i] = 0;
    //    for (int j = i + 1; j < SIZE; j++) 
    //    {
    //        int temp;
    //        cout << endl << "Введите расстояние " << (i + 1) << " - " << (j + 1) << " ";
    //        cin >> temp;
    //        Path[i][j] = temp;
    //        Path[j][i] = temp;
    //    }
    //}
    cout << "Введите нужный узел: ";
    cin >> FinalNode;
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%5d ", Path[i][j]);
        cout << endl;
    }
    Dijkstra();
    cout << endl << "Кратчайшие расстояния до вершин: " << endl;
    for (int i = 0; i < SIZE; i++)
        printf("%5d ", Mark[i]);
    
}

