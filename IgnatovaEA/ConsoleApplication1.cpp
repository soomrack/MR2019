#include <iostream>
#include <algorithm>
using namespace std;
char x1, x2, x3, x4;
int SB = 0, SW = 0, RZ = 0;

int main()
{
	int a;

	sеtlocale(LC_ALL, "Russian");

	a = 0;
	cout << "1. Ваше любимое занятие? \n 1) спать \n 2) гулять \n 3) мечтать \n";
	while (a == 0)
	{
		cin >> x1;
		switch (x1)
		{
		case '1':
			SB++;
			a = 1;
			break;
		case '2':
			SW++;
			a = 1;
			break;
		case '3':
			RZ++;
			a = 1;
			break;
		default:
			cout << "Введите правильный ответ!\n\n";
			break;
		}

	}

	a = 0;
	cout << "2.Ваш любимый цвет? \n 1) розовый \n 2) красный \n 3) желтый \n";
	while (a == 0)
	{
		cin >> x2;
		switch (x2)
		{
		case '1':
			SB++;
			a = 1;
			break;
		case '2':
			SW++;
			a = 1;
			break;
		case '3':
			RZ++;
			a = 1;
			break;
		default:
			cout << "Введите правильный ответ!\n\n";
			break;
		}
	}

	a = 0;
	cout << "3.Ваше лучшее качество? \n 1) мечтательность \n 2) доброта \n 3) смелость \n";
	while (a == 0)
	{
		cin >> x3;
		switch (x3)
		{
		case '1':
			SB++;
			a = 1;
			break;
		case '2':
			SW++;
			a = 1;
			break;
		case '3':
			RZ++;
			a = 1;
			break;
		default:
			cout << "Введите правильный ответ!\n\n";
			break;
		}
	}

	if ((SB == SW) && (SB == RZ))
	{
		a = 0;
		cout << "4.Выберите себе напарника: \n 1) конь \n 2) семь гномов \n 3) хамелеон \n";
		while (a == 0)
		{
			cin >> x4;
			switch (x4)
			{
			case '1':
				SB++;
				a = 1;
				break;
			case '2':
				SW++;
				a = 1;
				break;
			case '3':
				RZ++;
				a = 1;
				break;
			default:
				cout << "Введите правильный ответ!\n\n";
				break;
			}
		}
	}
	
	if ((SB > SW) && (SB > RZ))
	{
		cout << "Поздравляем, Вы Спящая красавица, сладких снов!\n\n";
	}
	if ((SW > SB) && (SW > RZ))
	{
		cout << "Поздравляем, Вы Белоснежка, остерегайтесь яблок!\n\n";
	}
	if ((RZ > SB) && (RZ > SW))
	{
		cout << "Поздравляем, Вы Рапунцель, советуем вооружиться сковородкой!\n\n";
	}
}
