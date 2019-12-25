#include "libilya.h"

int Vivod(int i)
{
	printf("Правильных ответов %i\n\n", i);
	Sleep(1800);
	printf("А теперь самое интересное\n\n");
	Sleep(1800);
	printf("Высчитываем результат\n");
	for (int c = 0; c < 6; c++) {
		Sleep(1000);
		printf(".");
	}
	printf("\n\n");
	Sleep(1000);
	if (i == 0) printf("Жалкое зрелище\n\n");
	if (i == 1) printf("Ты наверно забыл подумать\n\n");
	if (i == 2) printf("Wack\n\n");
	if (i == 3) printf("Not great, not terrible\n\n");
	if (i == 4) printf("Все ближе к истине\n\n");
	if (i == 5) printf("Ты получил силу, которая и не снилась твоему отцу\n\n");
	return 0;
}

int Proverka(int V)
{
	int K;
	scanf_s("%d", &K);
	int Otvet = 0;
	if (K == V) {
		printf("\nКрасава, верно\n\n");
		Otvet = 1;
	}
	else printf("\nПоходу ты ошибся\n\n");
	return Otvet;
}

int Putin() {
	printf("Победил Путин\n\n");
	mciSendString(L"open \"Молодец.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
	mciSendString(L"play mp3", NULL, 0, NULL);
	mciSendString(L"play mp3 wait", NULL, 0, NULL);
	system("pause");
	return 0;
}