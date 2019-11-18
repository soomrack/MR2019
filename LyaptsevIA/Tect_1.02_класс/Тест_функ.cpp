#include "Тест.h"

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

int Proverka(int V, int K)
{
	int Otvet = 0;
	if (K == V) {
		printf("\nКрасава, верно\n\n");
		Otvet = 1;
	}
	else {
		printf("\nПоходу ты ошибся\n\nПравильный ответ был %i\n\n", V);
	}
	return Otvet;
}

void Test()
{
	int Otvet = 0;
	setlocale(LC_ALL, "Russian");
	
	Test_class q1{ "В каком году началась Вторая Мировая война?\n",
						"1) 1888      3) 2018\n2) 1927      4) 1934\n\n",
						2 };
	Otvet += q1.process_question();

	Test_class q2{ "В каком году был разработан первый механический аналоговый компьютер?\n",
						"1)1 января 1977 года  2)15 июня 1999  3)12 апреля 1961  4)23 февраля 1949",
						2 };
	Otvet += q2.process_question();

	Test_class q3{ "Сколько хромосом у коровы?\n",
						"1) 46      3) 38\n2) 68      4) 120\n\n",
						4 };
	Otvet += q3.process_question();

	Test_class q4{ "Кто разработал BionicKangaroo?\n",
						"1) Apple      3) Lyaptsev Incorporated\n2) Festo Bionic Learning Network       4) Fablab \n\n",
						2 };
	Otvet += q4.process_question();

	Test_class q5{ "Как назывался первый полнометражный цветной фильм?\n",
						"1) Титаник      3) Бекки Шарп\n2) La Cucaracha       4) Парад в Дели \n\n",
						3};
	Otvet += q5.process_question();

	Vivod(Otvet);
}