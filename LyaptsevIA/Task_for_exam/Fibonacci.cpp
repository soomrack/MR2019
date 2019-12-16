#include <iostream>
#include "Fibonacci.h"

int main()
{
    cout << "Input last Fibonacci number\n";
	int fib_num;
	cin >> fib_num; 
	int curent_num;
	int fib_final = GetAllFibonacci(fib_num);
	cout << "Your final number = " << fib_final << "\n";
	while (1);
}


