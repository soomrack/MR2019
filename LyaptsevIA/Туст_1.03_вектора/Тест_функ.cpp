#include "����.h"

int Vivod(int i)
{
	printf("���������� ������� %i\n\n", i);
	Sleep(1800);
	printf("� ������ ����� ����������\n\n");
	Sleep(1800);
	printf("����������� ���������\n");
	for (int c = 0; c < 6; c++) {
		Sleep(1000);
		printf(".");
	}
	printf("\n\n");
	Sleep(1000);
	if (i == 0) printf("������ �������\n\n");
	if (i == 1) printf("�� ������� ����� ��������\n\n");
	if (i == 2) printf("Wack\n\n");
	if (i == 3) printf("Not great, not terrible\n\n");
	if (i == 4) printf("��� ����� � ������\n\n");
	if (i == 5) printf("�� ������� ����, ������� � �� ������� ������ ����\n\n");
	return 0;
}

int Proverka(int V, int K)
{
	int Otvet = 0;
	if (K == V) {
		printf("\n�������, �����\n\n");
		Otvet = 1;
	}
	else {
		printf("\n������ �� ������\n\n���������� ����� ��� %i\n\n", V);
	}
	return Otvet;
}

void Test()
{
	int Otvet = 0;
	int U_answer;
	setlocale(LC_ALL, "Russian");
	vector <string> v_question{ "� ����� ���� �������� ������ ������� �����?\n", 
								"� ����� ���� ��� ���������� ������ ������������ ���������� ���������?\n", 
								"������� �������� � ������?\n",
								"��� ���������� BionicKangaroo?\n",
								"��� ��������� ������ �������������� ������� �����?\n"};

	vector <string> v_variants{ "1) 1940      3) 1917\n2) 1939      4) 1941\n\n",
								"1) 1888      3) 2018\n2) 1927      4) 1934\n\n",
								"1) 46      3) 38\n2) 68      4) 120\n\n",
								"1) Apple      3) Lyaptsev Incorporated\n2) Festo Bionic Learning Network       4) Fablab \n\n",
								"1) �������      3) ����� ����\n2) La Cucaracha       4) ����� � ���� \n\n"};

	vector <int> v_answer{2, 2, 4, 2, 3};

	for (int i = 0; i < v_question.size(); i++) 
	{
		Test_questions Osnova{ v_question[i], v_variants[i], v_answer[i]};
		Otvet += Osnova.process_question();
	}
	
	Vivod(Otvet);
}