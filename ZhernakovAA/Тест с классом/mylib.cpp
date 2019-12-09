#include <iostream>
#include <conio.h>
using namespace std;
int process_answer(string answer, string users_answer)
{
	setlocale(LC_ALL, "Russian");
	if (answer != users_answer)
	{
		cout << "Íåâåðíî" << endl;
		return 0;
	}
	else 
	{
		cout << "Âåðíî" << endl;
		return 1;
	}
}
//sdsdsds
//aaa
