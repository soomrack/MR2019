#include "mylib.h"
using namespace std;
int process_answer(string answer, string users_answer)
{
	setlocale(LC_ALL, "Russian");
	if (answer != users_answer)
	{
		cout << "Íåâåðíî\n" << endl;
		return 0;
	}
	else
	{
		cout << "Âåðíî\n" << endl;
		return 1;
	}
}

void final_test() {
	setlocale(LC_ALL, "Russian");
	int right = 0;
	int users_answer;
	vector <string> v_question{ "Â êàêîì ãîäó íà÷àëàñü Âòîðàÿ Ìèðîâàÿ âîéíà?",
								"Òî÷íàÿ äàòà ïåðâîãî ïîëåòà ÷åëîâåêà â êîñìîñ",
								"Â êàêîì ãîäó áûë ðàçðàáîòàí ïåðâûé ìåõàíè÷åñêèé àíàëîãîâûé êîìïüþòåð?",
								"Êàê çâàëè îñíîâàòåëÿ êîìïàíèè Apple?",
								"Ñêîëüêî õðîìîñîì ó êîðîâû?" };
	vector <string> v_variants{ "1)1940\n2)1939\n3)1917\n4)1941",
								"1)1 ÿíâàðÿ 1977 ãîäà\n2)15 èþíÿ 1999\n3)12 àïðåëÿ 1961\n4)23 ôåâðàëÿ 1949",
								"1)1888\n2)1927\n3)2018\n4)1934",
								"1)Áèëë Ãåéòñ\n2)Âëàäèìèð Ïóòèí\n3)Ñòèâ Äæîáñ\n4)Èëüÿ Ëÿïöåâ",
								"1)46\n2)68\n3)38\n4)120" };
	vector <string> v_answer{   "2",
								"3",
								"2",
								"3",
								"4" };
	for (int i = 0; i < v_question.size(); i++) {
		Test curque{ v_question[i], v_variants[i], v_answer[i] };
		right += curque.process_question();
	}
	cout << "Ïðàâèëüíûõ îòâåòîâ:" << right << endl;
}
//Pidorasina
