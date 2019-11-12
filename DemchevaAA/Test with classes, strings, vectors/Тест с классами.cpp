
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//char x1, x2, x3, x4;
int SB = 0, SW = 0, RZ = 0, LX = 0;

class TestQuestion
{
public:
	char answer;
	
	void OutputQuestion(string message)
	{
		cout << message;
	}
	char GetAnswer()
	{		
		cin >> answer;
		return answer;
	}
	int CountPoints(int a = 0)
	{
		while (a < 1)
		{
			switch (answer)
			{
			case '1':
				SB++;
				a = 2;
				break;
			case '2':
				SW++;
				a = 2;
				break;
			case '3':
				RZ++;
				a = 2;
				break;
			case '4':
				LX++;
				a = 2;
				break;
			default:
				cout << "Ваше высочество, поправьте ваш ответ\n\n";
				a = 0;
				break;
			}

		}
		a = 0;
		return  SB, SW, RZ, LX;
	}
	
	string Result() 
	{
		string Conclusion;
		if (max(max(SB, SW), max(RZ, LX)) == SB)
		{
			Conclusion = "Поздравляем, Вы Спящая красавица, берегитесь игл и ... сладких снов\n\n";
		}
		if (max(max(SB, SW), max(RZ, LX)) == SW)
		{
			Conclusion = "Поздравляем, Вы Белоснежка, остерегайтесь яблок\n\n";
		}
		if (max(max(SB, SW), max(RZ, LX)) == RZ)
		{
			Conclusion = "Поздравляем, Вы Рапунцель, вооружитесь сковородкой и НИКОГДА не ровняйте кончики\n\n";
		}
		if (max(max(SB, SW), max(RZ, LX)) == LX)
		{
			Conclusion = "Вы не принцесса, вы Леха, психологический возраст 73\n\n";
		}
	return Conclusion;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	TestQuestion question1;
	question1.OutputQuestion("1. Что вы любите делать в свободное время? \n 1) спать \n 2) гулять \n 3) мечтать \n 4) смотреть аниме \n");
	question1.GetAnswer();
	question1.CountPoints();

	TestQuestion question2;
	question2.OutputQuestion("2.Какой ваш любимый цвет? \n 1) розовый \n 2) красный \n 3) желтый \n 4) влюбленной жабы \n");
	question2.GetAnswer();
	question2.CountPoints();

	TestQuestion Princess;
	cout<< Princess.Result();

	/*cout << "1. Что вы любите делать в свободное время? \n 1) спать \n 2) гулять \n 3) мечтать \n 4) смотреть аниме \n";
	
	cout << "2.Какой ваш любимый цвет? \n 1) розовый \n 2) красный \n 3) желтый \n 4) влюбленной жабы \n";
	
	cout << "3.Лучшее ваше качество? \n 1)мечтательность \n 2) доброта \n 3) сила духа \n 4) саркастичность \n";
	
	cout << "4.Какой  у вас напарник? \n 1) конь \n 2) семь гномов \n 3) хамелеон \n 4) корги \n";
	


	
	if (max(max(SB, SW), max(RZ, LX)) == SB)
	{
		cout << "Поздравляем, Вы Спящая красавица, берегитесь игл и ... сладких снов\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == SW)
	{
		cout << "Поздравляем, Вы Белоснежка, остерегайтесь яблок\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == RZ)
	{
		cout << "Поздравляем, Вы Рапунцель, вооружитесь сковородкой и НИКОГДА не ровняйте кончики\n\n";
	}
	if (max(max(SB, SW), max(RZ, LX)) == LX)
	{
		cout << "Вы не принцесса, вы Леха, психологический возраст 73\n\n";
	}*/
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
