#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

void ba_dom_tss(int dots) {
	for (int i = 0; i < dots; i++) {
		cout << ". ";
		Sleep(1000);
	}
	cout << endl;
}

void processing_of_question(char right_answer, char answer) {
	setlocale(LC_ALL, "Russian");
	while (answer != right_answer) {
		cout << "Неверно. Попробуйте еще раз." << endl;
		cin >> answer;
	}
	cout << "Верно\n" << endl;
	Sleep(500);
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	char answer, real_age;

	ba_dom_tss(3);
	cout << "Тест на психологический возраст\n" << endl;
	Sleep(1000);

	cout << "Введите номер буквы в" << endl << "1.в  2.г  3.е  4.Ё" << endl;
	cin >> answer;
	processing_of_question('1', answer);

	cout << "Введите номер буквы Г" << endl << "1.в  2.Г  3.е  4.Ё" << endl;
	cin >> answer;
	processing_of_question('2', answer);

	cout << "Введите номер буквы е" << endl << "1.В  2.Г  3.е  4.Ё" << endl;
	cin >> answer;
	processing_of_question('3', answer);

	cout << "А теперь перейдем к самому главному вопросу\n" << endl;
	Sleep(1000);
	cout << "Сколько вам лет?\n";
	cin >> real_age;

	cout << "Ваш психологический возраст:\n"; 
	ba_dom_tss(5);
	cout << rand() % 100;
}