#include <iostream>
#include "Hstack.h"
using namespace std;


int main()
{

	Stack s1;

	s1.push(11);
	s1.push(22);
	s1.push(33);
	s1.push(44);
	s1.push(55);
	s1.push(66);
	
	s1.pop();
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	return 0;
}
