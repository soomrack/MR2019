#include "pch.h" 
#include <iostream>
#include <algorithm>
#include "NewTestLibrary.h"


using namespace std;
char x1, x2, x3, x4;
int SB = 0, SW = 0, RZ = 0, LX = 0;


int Start_Princess_Test()
{

	int a = 0;

	setlocale(LC_ALL, "Russian");
	cout << "1. ��� �� ������ ������ � ��������� �����? \n 1) ����� \n 2) ������ \n 3) ������� \n 4) �������� ����� \n";
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
			cout << "���� ����������, ��������� ��� �����\n\n";
			a = 0;
			break;
		}

	}
	a = 0;
	cout << "2.����� ��� ������� ����? \n 1) ������� \n 2) ������� \n 3) ������ \n 4) ���������� ���� \n";
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
			cout << "���� ����������, ��������� ��� �����\n\n";
			break;
		}
	}
	a = 0;
	cout << "3.������ ���� ��������? \n 1)�������������� \n 2) ������� \n 3) ���� ���� \n 4) �������������� \n";
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
			cout << "���� ����������, ��������� ��� �����\n\n";
			break;
		}
	}
	a = 0;
	cout << "4.�����  � ��� ��������? \n 1) ���� \n 2) ���� ������ \n 3) �������� \n 4) ����� \n";
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
			cout << "���� ����������, ��������� ��� �����\n\n";
			break;
		}
	}
	if (max(max(SB, SW), max(RZ, LX)) == SB)
	{
		cout << "�����������, �� ������ ���������, ���������� ��� � ... ������� ����\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == SW)
	{
		cout << "�����������, �� ����������, ������������� �����\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == RZ)
	{
		cout << "�����������, �� ���������, ����������� ����������� � ������� �� �������� �������\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == LX)
	{
		cout << "�� �� ���������, �� ����, ��������������� ������� 73\n\n";
	}
	if (SB == SW == RZ == LX)
	{
		cout << "� ��� ���� ������ ����� �� ������ ���������) ��� �������!)\n\n";
	return 0;
	   
}
