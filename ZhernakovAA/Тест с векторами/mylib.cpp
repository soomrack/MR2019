#include "mylib.h"
using namespace std;
int process_answer(string answer, string users_answer)
{
	setlocale(LC_ALL, "Russian");
	if (answer != users_answer)
	{
		cout << "�������\n" << endl;
		return 0;
	}
	else
	{
		cout << "�����\n" << endl;
		return 1;
	}
}

void final_test() {
	setlocale(LC_ALL, "Russian");
	int right = 0;
	int users_answer;
	vector <string> v_question{ "� ����� ���� �������� ������ ������� �����?",
								"������ ���� ������� ������ �������� � ������",
								"� ����� ���� ��� ���������� ������ ������������ ���������� ���������?",
								"��� ����� ���������� �������� Apple?",
								"������� �������� � ������?" };
	vector <string> v_variants{ "1)1940\n2)1939\n3)1917\n4)1941",
								"1)1 ������ 1977 ����\n2)15 ���� 1999\n3)12 ������ 1961\n4)23 ������� 1949",
								"1)1888\n2)1927\n3)2018\n4)1934",
								"1)���� �����\n2)�������� �����\n3)���� �����\n4)���� ������",
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
	cout << "���������� �������:" << right << endl;
}