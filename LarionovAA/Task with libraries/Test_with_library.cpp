
#include <iostream>
#include "LibraryTest.h"
#include "NewTestLibrary.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
	cout << "Which game do you choose? Write the number, please.\n";
	cout << "1) The first interesting test\n";
	cout << "2) The second interesting test\n\n";
	NewGame:
	string answer;
	cin >> answer;
	if (answer == "1")
	{
		StartTest();
	}
	else
	{
		if (answer == "2")
		{
			Start_Princess_Test();
		}
		goto NewGame;
	}
}

