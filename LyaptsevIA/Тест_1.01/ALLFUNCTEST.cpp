#include "libilya.h"

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

int Proverka(int V)
{
	int K;
	scanf_s("%d", &K);
	int Otvet = 0;
	if (K == V) {
		printf("\n�������, �����\n\n");
		Otvet = 1;
	}
	else printf("\n������ �� ������\n\n");
	return Otvet;
}

int Putin() {
	printf("������� �����\n\n");
	mciSendString(L"open \"�������.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString(L"play mp3", NULL, 0, NULL);
	mciSendString(L"play mp3 wait", NULL, 0, NULL);
	system("pause");
	return 0;
}