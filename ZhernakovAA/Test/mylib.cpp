#include "mylib.h"

int Test()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	printf("В каком году началась Вторая Мировая война?\n1) 1940      3) 1917\n2) 1939      4) 1941\n");
	int K1 = _getch();
	switch (K1) {
	case '2':
		printf("Верно\n");
		i++;
		break;
	case '1':
	case '3':
	case '4':
		printf("Неверно\n");
		break;
	default:
		printf("Введите число от 1 до 4\n");
		break;
	}
	printf("Точная дата первого полета человека в космос\n1) 1 января 1977 года      3) 12 апреля 1961\n2) 15 июня 1999      4) 23 февраля 1949\n");
	int K2 = _getch();
	switch (K2) {
	case '1':
	case '2':
	case '4':
		printf("Неверно\n");
		break;
	case '3':
		printf("Верно\n");
		i++;
		break;
	default:
		printf("Введите число от 1 до 4\n");
		break;
	}
	printf("В каком году был разработан первый механический аналоговый компьютер?\n1) 1888      3) 2018\n2) 1927      4) 1934\n");
	int K3 = _getch();
	switch (K3) {
	case '1':
	case '3':
	case '4':
		printf("Неверно\n");
		break;
	case '2':
		printf("Верно\n");
		i++;
		break;
	default:
		printf("Введите число от 1 до 4\n");
		break;
	}
	printf("Как звали основателя компании Apple?\n1) Билл Гейтс      3) Стив Джобс\n2) Владимир Путин      4) Илья Ляпцев\n");
	int K4 = _getch();
	switch (K4) {
	case '1':
	case '2':
	case '4':
		printf("Неверно\n");
		break;
	case '3':
		printf("Верно\n");
		i++;
		break;
	default:
		printf("Введите число от 1 до 4\n");
		break;
	}
	printf("Сколько хромосом у коровы?\n1) 46      3) 38\n2) 68      4) 120\n");
	int K5 = _getch();
	switch (K5) {
	case '1':
	case '2':
	case '3':
		printf("Неверно\n");
		break;
	case '4':
		printf("Верно\n");
		i++;
		break;
	default:
		printf("Введите число от 1 до 4\n");
		break;
	}
	printf("Правильных ответов %i", i);
	return 0;
}