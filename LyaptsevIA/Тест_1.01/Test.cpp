#include "libilya.h"

int Test()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	int F = 0;
	printf("� ����� ���� �������� ������ ������� �����?\n1) 1940      3) 1917\n2) 1939      4) 1941\n\n");
	i += Proverka(2);

	printf("� ����� ���� ��� ���������� ������ ������������ ���������� ���������?\n1) 1888      3) 2018\n2) 1927      4) 1934\n\n");
	i += Proverka(2);

	printf("������� �������� � ������?\n1) 46      3) 38\n2) 68      4) 120\n\n");
	i += Proverka(4);

	printf("��� ���������� BionicKangaroo?\n1) Apple      3) Lyaptsev Incorporated\n2) Festo Bionic Learning Network       4) Fablab \n\n");
	i += Proverka(2);

	printf("��� ��������� ������ �������������� ������� �����?\n1) �������      3) ����� ����\n2) La Cucaracha       4) ����� � ���� \n\n");
	i += Proverka(2);

	Vivod(i);
	return 0;
}