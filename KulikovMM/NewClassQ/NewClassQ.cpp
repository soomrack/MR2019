
#include <iostream>
using namespace std;

class Queue
{
private:
	enum { MAX = 10 };
	int qu[MAX];
	int tail;
	int top;
public:
	Queue()
	{
		tail = -1;
		top = 0;
	}
	int push(int n)
	{
		++tail;
		qu[tail] = n;
		return n;
	}
	int pop()
	{
		int temp;
		temp = qu[top];
		top++;
		return temp;
	}
	void viewqueue()
	{
		int j=top;
		cout << endl;
			for (j; j <= tail; j++)
			{
				cout << qu[j] << endl;
			}
	}
};

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
