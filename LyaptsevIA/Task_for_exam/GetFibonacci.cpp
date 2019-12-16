#include "Fibonacci.h"
int Count;

int GetAllFibonacci(int fib_num){
	static vector <int> Fibb;
	if (fib_num <= (static_cast <int> (Fibb.size()))) {
		if (fib_num == 1) return 1;
		return Fibb[fib_num-1];
	}
	else if (fib_num == 1 || fib_num == 2)
	{
		Fibb.push_back(1);
		return 1;
	}
	else Fibb.push_back(GetAllFibonacci(fib_num - 2) + GetAllFibonacci(fib_num - 1));
	return Fibb.back();
}



