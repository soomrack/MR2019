#include <iostream>
#include "Hstack.h"
using namespace std;


int main()
{
	int j;
	Stack st1;

	do
	{
		setlocale(LC_ALL, "RUSSIAN");
		cout << endl;
		cout << "0 - Выход." << endl;
		cout << "1 - Положить число." << endl;
		cout << "2 - Убрать число." << endl;
		cout << "3 - Показать стек." << endl;

		cout << "Что вы хотите сделать? Введите цифру: ";
		cin >> j;

		switch (j)
		{
		case 0: break;

		case 1:
			int a;
			cout << "Введите число, чтобы положить его в стек:" << endl;
			cin >> a;
			st1.push(a);
			break;

		case 2:
			st1.pop();
			break;

		case 3:
			st1.StackShow();
			break;

		default:
			cout << "Неверный выбор!" << endl;
		}
	} while (j!= 0);

	return 0;
}