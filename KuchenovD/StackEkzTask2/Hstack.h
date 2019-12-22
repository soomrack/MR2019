#include <iostream>
using namespace std;

class Stack
{
private:
	enum { MAX = 5 };
	int st[MAX];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(int var)
	{
		st[++top] = var;
	}
	int pop()
	{
		return st[top--];
	}
	void StackShow()
	{
		int i = top;
		cout << endl;
		for (i; i >= 0; i--)
		{
			cout << st[i] << endl;
		}
	}
};