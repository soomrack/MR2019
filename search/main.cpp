//#include <iostream>
//
//int search(int *a, int first, int last, int x){
//    if (first >= last)
//        if (a[first] == x){
//            return (first);
//        }
//        else return (-1);
//    int middle = (last - first) / 2 + first;
//    //if (a[middle] == x) return middle;
//    if (a[middle] < x) return (search(a, middle + 1, last, x));
//    return (search(a, first, middle, x));
//}
//
//int main() {
//
//};
#define _CRT_SECURE_NO_WARNINGS // для корректной работы scanf()
#include <stdio.h>
#include <stdlib.h> // для использования функций system()
int main()
{
    int k[20]; // массив ключей основной таблицы
    int r[20]; // массив записей основной таблицы
    int key, i;
    system("chcp 1251"); // перевод русского языка в консоли
    system("cls");     // очистка окна консоли
    // Инициализация ключевых полей упорядоченными значениями
    k[0] = 8;  k[1] = 14;
    k[2] = 26;  k[3] = 28;
    k[4] = 38;  k[5] = 47;
    k[6] = 56;  k[7] = 60;
    k[8] = 64;  k[9] = 69;
    k[10] = 70; k[11] = 78;
    k[12] = 80; k[13] = 82;
    k[14] = 84; k[15] = 87;
    k[16] = 90; k[17] = 92;
    k[18] = 98; k[19] = 108;
    // Ввод записей
    for (i = 0; i < 20; i++)
    {
        printf("%2d. k[%2d]=%3d: r[%2d]= ", i, i, k[i], i);
        scanf("%d", &r[i]);
    }
    printf("Введите key: "); // вводим искомое ключевое поле
    scanf("%d", &key);
    int left = 0; // задаем левую и правую границы поиска
    int right = 19;
    int search = -1; // найденный индекс элемента равен -1 (элемент не найден)
    while (left <= right) // пока левая граница не "перескочит" правую
    {
        int mid = (left + right) / 2; // ищем середину отрезка
        if (key == k[mid]) {  // если ключевое поле равно искомому
            search = mid;     // мы нашли требуемый элемент,
            break;            // выходим из цикла
        }
        if (key < k[mid])     // если искомое ключевое поле меньше найденной середины
            right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
        else                  // иначе
            left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
    }
    if (search == -1)     // если индекс элемента по-прежнему -1, элемент не найден
        printf("Элемент не найден!\n");
    else          // иначе выводим элемент, его ключ и значение
        printf("%d. key= %d. r[%d]=%d", search, k[search], search, r[search]);
    getchar(); getchar();
    return 0;
}
