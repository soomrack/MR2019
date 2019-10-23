#include "libilya.h"

int Test()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	int F = 0;
	printf("В каком году началась Вторая Мировая война?\n1) 1940      3) 1917\n2) 1939      4) 1941\n\n");
	i += Proverka(2);

	printf("В каком году был разработан первый механический аналоговый компьютер?\n1) 1888      3) 2018\n2) 1927      4) 1934\n\n");
	i += Proverka(2);

	printf("Сколько хромосом у коровы?\n1) 46      3) 38\n2) 68      4) 120\n\n");
	i += Proverka(4);

	if (F == 1) {
		Putin();
		return 0;
	}

	Vivod(i);
	return 0;
}