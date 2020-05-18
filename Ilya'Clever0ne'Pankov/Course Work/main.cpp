#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

#define SIZE       100
#define MAX_NUMBER 500

static const unsigned int a = 24;
static const unsigned int b = 55;

static unsigned int laggedFibGen(const unsigned int *x, const unsigned int index)
{
    return (unsigned int)(x[index - a] + x[index - b]) % (RAND_MAX + 1);
}

int main()
{
    // Задаём начальное значение для функции rand
    srand(time(NULL));
    // Создаём массив для последовательности псевдослучайных чисел
    unsigned int x[__max(a, b) + SIZE + 1] = {0};
    // Заполняем инициализирующий вектор псевдослучайными числами
    for (unsigned int index = 0; index <= __max(a, b); index++)
    {
        x[index] = rand() % (MAX_NUMBER + 1);
    }
    // Генерируем последовательность псевдослучайных  чисел
    for (unsigned int index = __max(a, b) + 1; index <= __max(a, b) + SIZE; index++)
    {
        x[index] = laggedFibGen(x, index) % (MAX_NUMBER + 1);
    }
    // создаём поток для вывода последовательности в текстовый файл
    fstream result;
    result.open("result.txt", fstream::in | fstream::out);
    // Выводим последовательность в текстовый файл
    for (unsigned int index = __max(a, b) + 1; index <= __max(a, b) + SIZE; index++)
    {
        result << x[index] << endl;
    }
    result.close();
}