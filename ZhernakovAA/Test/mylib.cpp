#include "mylib.h"

int Test()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	printf("� ����� ���� �������� ������ ������� �����?\n1) 1940      3) 1917\n2) 1939      4) 1941\n");
	int K1 = _getch();
	switch (K1) {
	case '2':
		printf("�����\n");
		i++;
		break;
	case '1':
	case '3':
	case '4':
		printf("�������\n");
		break;
	default:
		printf("������� ����� �� 1 �� 4\n");
		break;
	}
	printf("������ ���� ������� ������ �������� � ������\n1) 1 ������ 1977 ����      3) 12 ������ 1961\n2) 15 ���� 1999      4) 23 ������� 1949\n");
	int K2 = _getch();
	switch (K2) {
	case '1':
	case '2':
	case '4':
		printf("�������\n");
		break;
	case '3':
		printf("�����\n");
		i++;
		break;
	default:
		printf("������� ����� �� 1 �� 4\n");
		break;
	}
	printf("� ����� ���� ��� ���������� ������ ������������ ���������� ���������?\n1) 1888      3) 2018\n2) 1927      4) 1934\n");
	int K3 = _getch();
	switch (K3) {
	case '1':
	case '3':
	case '4':
		printf("�������\n");
		break;
	case '2':
		printf("�����\n");
		i++;
		break;
	default:
		printf("������� ����� �� 1 �� 4\n");
		break;
	}
	printf("��� ����� ���������� �������� Apple?\n1) ���� �����      3) ���� �����\n2) �������� �����      4) ���� ������\n");
	int K4 = _getch();
	switch (K4) {
	case '1':
	case '2':
	case '4':
		printf("�������\n");
		break;
	case '3':
		printf("�����\n");
		i++;
		break;
	default:
		printf("������� ����� �� 1 �� 4\n");
		break;
	}
	printf("������� �������� � ������?\n1) 46      3) 38\n2) 68      4) 120\n");
	int K5 = _getch();
	switch (K5) {
	case '1':
	case '2':
	case '3':
		printf("�������\n");
		break;
	case '4':
		printf("�����\n");
		i++;
		break;
	default:
		printf("������� ����� �� 1 �� 4\n");
		break;
	}
	printf("���������� ������� %i", i);
	return 0;
}