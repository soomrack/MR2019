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

	printf("Кто разработал BionicKangaroo?\n1) Apple      3) Lyaptsev Incorporated\n2) Festo Bionic Learning Network       4) Fablab \n\n");
	i += Proverka(2);

	printf("Как назывался первый полнометражный цветной фильм?\n1) Титаник      3) Бекки Шарп\n2) La Cucaracha       4) Парад в Дели \n\n");
	i += Proverka(2);

	Vivod(i);
	return 0;
}