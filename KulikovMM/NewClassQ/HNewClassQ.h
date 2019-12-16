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
		int j = top;
		cout << endl;
		for (j; j <= tail; j++)
		{
			cout << qu[j] << endl;
		}
	}
};