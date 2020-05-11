
#include <iostream>

using namespace std;

class Graph
{
public:

    int communications[9][9];
    int Q[9];
    int L[9];
    int infinity = 10000;
    int step = 0;
    int ind_next_step = 0;
    Graph(int arr[9][9])
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                communications[i][j] = arr[i][j];
            }
        }

        for (int i = 0; i < 9; i++)
        {
            Q[i] = infinity;
            L[i] = 0;
        }
    }

    void Deiksrta(int start);
    void print(int finis);
    int search_min(int Q[], int ind[]);
    int big_ind[20];
};


void Graph::Deiksrta(int start)
{
    if (start > 8)
    {
        return;
    }

    if (step == 0)
    {
        Q[start] = 0;
        L[start] = 0;
        big_ind[step] = 0;
    }

    for (int j = 0; j < 9; j++)
    {
        if ((communications[start][j] != 0) && ((communications[start][j] + Q[ind_next_step]) < Q[j])) //смотрим в матрицу связей и записываем самые короткие пути до соседних элементов
        {
            Q[j] = communications[start][j] + Q[start];
            L[j] = start;
        }
    }

     ind_next_step = search_min(Q, big_ind);


    big_ind[step + 1] = ind_next_step;


    cout << step << '\n';
    for (int i = 0; i < 9; i++)
    {
        cout << Q[i]<<',';
    }

    cout << '\n';

    for (int i = 0; i < 9; i++)
    {
        cout << L[i]<<',';
    }
    cout << '\n';
    cout << ind_next_step << '\n';

    step++;

    if (ind_next_step == 8)
    {
        return;
    }
    else
    {
        Deiksrta(ind_next_step);
    }
}

int Graph::search_min(int Q[], int ind[])
{
    int copy_Q[9];

    for (int i = 0; i < 9; i++)
    {
        copy_Q[i] = Q[i];
    }

    for (int j = 0; j <= step; j++)
    {
        copy_Q[ind[j]] = 10000;
    }

    int temp = copy_Q[0];
    int min_ind = 0;

    for (int i = 0; i < 9; i++)
    {
        if (copy_Q[i] < temp)
        {
            temp = copy_Q[i];
            min_ind = i;
            
        }
    }

    return min_ind;
}


void Graph::print(int finish)
{
    cout << L[finish];

    if (L[finish] == 0)
    {
        return;
    }
    else
    {
        print(L[finish]);
    }
}

int main()
{
                   //0  1  2  3  4  5  6  7  8
    int com[9][9] = {0, 4, 0, 3, 0, 0, 0, 0, 0,      //0
                     4, 0, 6, 0, 2, 0, 0, 0, 0,      //1
                     0, 6, 0, 0, 0, 1, 0, 0, 0,      //2
                     3, 0, 0, 0, 8, 0, 9, 0, 0,      //3
                     0, 2, 0, 8, 0, 5, 0, 8, 0,      //4
                     0, 0, 1, 0, 5, 0, 0, 0, 11,     //5
                     0, 0, 0, 9, 0, 0, 0, 7, 0,      //6
                     0, 0, 0, 0, 8, 0, 7, 0, 12,     //7
                     0, 0, 0, 0, 0, 11 ,0 ,12 , 0};  //8

    Graph myGraph = Graph(com);

    myGraph.Deiksrta(0);
    myGraph.print(8);
}


