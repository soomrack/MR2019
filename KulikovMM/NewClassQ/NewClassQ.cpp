#include <iostream>
#include "HNewClassQ.h"
using namespace std;
 
int main()
{

	Queue q;
	int i;
	do
	{
		cout << endl;
		cout << "Press 1 to add a number to the queue." << endl;
		cout << "Press 2 to remove a number from the queue." << endl;
		cout << "Press 3 to view the queue." << endl;
		cout << "Press 4 to exit." << endl;
		cout << "Enter your choise:" << " " << endl;
		cin >> i;
		if (i == 1)
		{
			int a;
			cout << "What to push?" << endl;
			cin >> a;
			q.push(a);
		}
		if (i == 2)
		{
			q.pop();
		}
		if (i == 3)
		{
			q.viewqueue();
		}
		if ((i != 1) and (i != 2) and (i != 3) and (i != 4))
		{
			cout << "Wrong choise! Choose another number." << endl;
		}
	}while (i != 4);
}
