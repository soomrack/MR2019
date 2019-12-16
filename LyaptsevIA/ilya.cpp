// ilya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
ilya lyaptsev
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	int F = 0;
Vopros1:
	printf("В каком году началась Вторая Мировая война?\n1) 1940      3) 1917\n2) 1939      4) 1941\n\n");
	int K1 = _getch();
	switch (K1) {
	case '1':
	case '3':
	case '4':
		printf("Ты дурак\n\n");
		break;
	case '2':
		printf("Молодец\n\n");
		i++;
		break;
	default:
		printf("Ввел не то\n\n");
		break;
	}

	printf("Ты правильно ответил на предыдущий вопрос?\n1) Нет      3) Не знаю\n2) Да      4) Я ошибся кнопкой\n\n");
	int K2 = _getch();
	switch (K2) {
	case '1':
		if (i == 1) {
			printf("Почему ты обманываешь?\n\n");
			break;
		}
		else {
			printf("Ты дурак\n\n");
			break;
		}
	case '3':
		printf("Ты дурак\n\n");
		break;
	case '2':
		if (i == 0) {
			printf("Почему ты обманываешь?\n\n");
			break;
		}
		else {
			printf("Молодец\n\n");
			i++;
			break;
		}
	case '4':
		printf("Ща все будет\n\n");
		goto Vopros1;
		break;
	default:
		printf("Ввел не то\n\n");
		break;
	}

	printf("В каком году был разработан первый механический аналоговый компьютер?\n1) 1888      3) 2018\n2) 1927      4) 1934\n\n");
	int K3 = _getch();
	switch (K3) {
	case '1':
	case '3':
	case '4':
		printf("Неверно\n\n");
		break;
	case '2':
		printf("Верно\n\n");
		i++;
		break;
	default:
		printf("Введите число от 1 до 4\n\n");
		break;
	}

	printf("Как звали основателя компании Apple?\n1) Билл Гейтс\n2) Владимир Путин (советую выбирать во втором прохождении, несет разрушительные последствия)\n3) Стив Джобс\n4) Илья Ляпцев\n\n");
	int K4 = _getch();
	switch (K4) {
	case '1':
	case '4':
		printf("Неверно\n\n");
		break;
	case '2':
		printf("Молодец, политик, лидер и борец!!! (Но неправильно)\n\n");
		F = 1;
		break;
	case '3':
		printf("Верно\n\n");
		i++;
		break;
	default:
		printf("Введите число от 1 до 4\n\n");
		break;
	}

	printf("Сколько хромосом у коровы?\n1) 46      3) 38\n2) 68      4) 120\n\n");
	int K5 = _getch();
	switch (K5) {
	case '1':
	case '2':
	case '3':
		printf("Неверно\n\n");
		break;
	case '4':
		printf("Невероятно, но факт\n\n");
		i++;
		break;
	default:
		printf("Введите число от 1 до 4\n\n");
		break;
	}
	if (F == 1) {
		printf("Победил Путин\n\n");
		mciSendString(L"open \"Молодец.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
		mciSendString(L"play mp3", NULL, 0, NULL);
		mciSendString(L"play mp3 wait", NULL, 0, NULL);
		system("pause");
		return 0;
	}
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
	printf("Твой результат: %i из 5, если кратко:\n\n", i);
	Sleep(700);
	if (i == 0) printf("Жалкое зрелище\n\n");
	if (i == 1) printf("Ты наверно забыл подумать\n\n");
	if (i == 2) printf("Wack\n\n");
	if (i == 3) printf("Not great, not terrible\n\n");
	if (i == 4) printf("Все ближе к истине\n\n");
	if (i == 5) printf("Ты получил силу, которая и не снилась твоему отцу\n\n");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
