//Тест создан дружной компанией из: Демчевой Александры, Игнатовой Екатерины, Патрушевой Алины и Самарины Алексея
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;
char x1, x2, x3, x4;
int SB = 0, SW = 0, RZ = 0, LX = 0;



int main()
{
	int a = 0;

	setlocale(LC_ALL, "Russian");
	cout << "1. Что вы любите делать в свободное время? \n 1) спать \n 2) гулять \n 3) мечтать \n 4) смотреть аниме \n";
	while (a < 1)
	{

		cin >> x1;
		switch (x1)
		{
		case '1':
			SB++;
			a = 2;
			break;
		case '2':
			SW++;
			a = 2;
			break;
		case '3':
			RZ++;
			a = 2;
			break;
		case '4':
			LX++;
			a = 2;
			break;
		default:
			cout << "Ваше высочество, поправьте ваш ответ\n\n";
			a = 0;
			break;
		}

	}
	a = 0;
	cout << "2.Какой ваш любимый цвет? \n 1) розовый \n 2) красный \n 3) желтый \n 4) влюбленной жабы \n";
	while (a < 1)
	{
		cin >> x2;
		switch (x2)
		{
		case '1':
			SB++;
			a = 2;
			break;
		case '2':
			SW++;
			a = 2;
			break;
		case '3':
			RZ++;
			a = 2;
			break;
		case '4':
			LX++;
			a = 2;
			break;
		default:
			cout << "Ваше высочество, поправьте ваш ответ\n\n";
			break;
		}
	}
	a = 0;
	cout << "3.Лучшее ваше качество? \n 1)мечтательность \n 2) доброта \n 3) сила духа \n 4) саркастичность \n";
	while (a < 1)
	{
		cin >> x3;
		switch (x3)
		{
		case '1':
			SB++;
			a = 2;
			break;
		case '2':
			SW++;
			a = 2;
			break;
		case '3':
			RZ++;
			a = 2;
			break;
		case '4':
			LX++;
			a = 2;
			break;
		default:
			cout << "Ваше высочество, поправьте ваш ответ\n\n";
			break;
		}
	}
	a = 0;
	cout << "4.Какой  у вас напарник? \n 1) конь \n 2) семь гномов \n 3) хамелеон \n 4) корги \n";
	while (a < 1)
	{
		cin >> x4;
		switch (x4)
		{
		case '1':
			SB++;
			a = 2;
			break;
		case '2':
			SW++;
			a = 2;
			break;
		case '3':
			RZ++;
			a = 2;
			break;
		case '4':
			LX++;
			a = 2;
			break;
		default:
			cout << "Ваше высочество, поправьте ваш ответ\n\n";
			break;
		}
	}
	if (max(max(SB, SW), max(RZ, LX)) == SB)
	{
		cout << "Поздравляем, Вы Спящая красавица, берегитесь игл и ... сладких снов\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == SW)
	{
		cout << "Поздравляем, Вы Белоснежка, остерегайтесь яблок\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == RZ)
	{
		cout << "Поздравляем, Вы Рапунцель, вооружитесь сковородкой и НИКОГДА не ровняйте кончики\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == LX)
	{
		cout << "Вы не принцесса, вы Леха, психологический возраст 73\n\n";
	}
}


