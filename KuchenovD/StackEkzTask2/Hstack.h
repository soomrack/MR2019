#include <iostream>
using namespace std;

class Stack
{
private:
	enum { MAX = 10 };
	int st[MAX];
	int top;
public:
	Stack()
	{
		top = 0;
	}
	void push(int var)
	{
		st[++top] = var;
	}
	int pop()
	{
		return st[top--];
	}
};

