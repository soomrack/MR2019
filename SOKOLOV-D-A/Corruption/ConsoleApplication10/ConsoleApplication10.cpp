#include "stdafx.h"
#include <iostream>
#include <cstdlib>
struct Strategy {
	int client_debet;
	int client_credit;
};
Strategy* PerMonth = new Strategy[12];
Strategy* Optimal = new Strategy[12];
long int maxCapital = 0;
long int startupMoney = 1000000;
struct Strategy optimal(int period, long int capital, double debet_percent, double credit_percent, int max_credit_clients);
int revenueMonth(int money, double percent_year, int numOfClientsCredit, int numOfClientsDebet);
int expensesMonth(int money, double percent_year, int numOfClientsCredit, int numOfClientsDebet);
int* perebor(int* array[]);
bool transaction(const int incomeMoney, const int outcomeMoney , long int &bank);
void printMonth(long int account);
void printYear(long int account, int year);
//void giveMemory(struct Strategy array[]);
//void delMemory(struct Strategy *array);
void makeCredit(long int &bank, int numOfClientsCredit, long int money);
void makeDebet(long int &bank, int numOfClientsDebet, long int money);
void printArray(struct Strategy array[], int size);
void printArray(int array[], int size);
void swap(struct Strategy reciever[], struct Strategy transmitter[], int size);

int main(void)
{
	system("chcp 1251 > null");
	/*giveMemory(PerMonth);
	giveMemory(Optimal);*/
	
	//Optimal[12].client_credit = new int;
	for (int i = 0; i < 12; i++) {
		PerMonth[i].client_credit = 0;
		PerMonth[i].client_debet  = 0;
		Optimal[i].client_credit  = 0;
		Optimal[i].client_debet  = 0;
	}
    optimal(5, 20000000, 8.0, 25.0, 100);
	printArray(Optimal, 12);
	delete[] Optimal;
	delete[] PerMonth;
	system("pause");
	return 0;
}

struct Strategy optimal(int period, long int capital, double debet_percent, double credit_percent, int max_credit_clients) {
	int A[12] = { 0 };
	int limits[12] = { 3,3,3,3,3,3,3,3,3,3,3,3 };
	int counter = 0;
	while (A[11] < limits[11])
	{
		int i = 0;
		while (A[i] >= limits[i]){
			A[i] = 0;
			i++;
		}
		A[i]++;
		for (int i = 0; i < 12; i++) {
			//printf("%d ", A[i]);//cout << A[i] << " ";
			(PerMonth[i].client_debet) = A[i];
			(PerMonth[i].client_credit) = A[i];
		}
		//printf("\n");//cout << endl;
		for (int year = 1; year <= period; year++) {
			for (int month = 1; month < 13; month++) {
				makeCredit(capital, PerMonth[month - 1].client_credit, startupMoney);// дал кредит
				makeDebet(capital, PerMonth[month - 1].client_debet, startupMoney);// получил вклад
				int income = revenueMonth(startupMoney, credit_percent, PerMonth[month - 1].client_credit, PerMonth[month - 1].client_debet);
				int outcome = expensesMonth(startupMoney, debet_percent, PerMonth[month - 1].client_credit, PerMonth[month - 1].client_debet);
				transaction(income, outcome, capital);
				if (!transaction(income, outcome, capital)) {
					//printf("\nОшибка транзакции\n");
					break;
				}
				if (year > 1) {
					capital -= startupMoney * PerMonth[month - 1].client_debet;
				}
				//printMonth(capital);
			}
			printYear(capital, year);
			if (capital >= maxCapital) {
				maxCapital = capital;
				swap(Optimal, PerMonth, 12);
				//printf("\n%ld \n", maxCapital);
			}
			if (capital < 0) break;
		}
			//printf("\n%ld \n", maxCapital);
			counter++;
	}
	printf("\nМаксимальный капитал: %ld, число подборов: %d \n", maxCapital, counter);
	return PerMonth[12];
}
int expensesMonth(int money, double percent_year, int numOfClientsCredit, int numOfClientsDebet) {
	double percent_month = percent_year / 1200.0;
	//double money_month = money / 12.0;
	int outcome = (int)((double)money * percent_month) * numOfClientsDebet;
	return outcome;
}

int revenueMonth(int money, double percent_year, int numOfClientsCredit, int numOfClientsDebet) {
	double percent_month = percent_year / 1200.0;
	double money_month = money / 12.0;
	int income = (int)((double)money * percent_month) * numOfClientsCredit;
	return income;
}
bool transaction(const int incomeMoney, const int outcomeMoney, long int &bank) {
	if ((bank + incomeMoney) < (outcomeMoney)) {
		//printf("Деньги закончились\n");
		return false;
	}
	bank += incomeMoney;
	bank -= outcomeMoney;
	return true;
}
void printMonth(long int account) {
	printf("\nБаланс в месяц : %ld ", account);
}
void printYear(long int account, int year) {

	printf("\nБаланс в %d год : %ld \n", year, account);
}
//void giveMemory(struct Strategy array[]) {
//	for (int i = 0; i < 12; i++) {
//		array[i].client_debet = new int;
//		array[i].client_credit = new int;
//	}
//}
//void delMemory(struct Strategy array) {
//	delete[] array;
//	delete[] array;
//}
void makeCredit(long int &bank, int numOfClientsCredit, long int money) {
	bank -= money * numOfClientsCredit;
}
void makeDebet(long int &bank, int numOfClientsDebet, long int money) {
	bank += money * numOfClientsDebet;
}
int* perebor(int* array[]) {
	int A[12] = { 0 };
	int limits[12] = { 1,100,1,100,1,100,1,100,1,100,1,100 };
	int counter = 0;
	while (A[11] < limits[11])
	{
		int i = 0;
		while (A[i] >= limits[i])
		{
			A[i] = 0;
			i++;
		}
		A[i]++;
		for (int i = 0; i < 12; i++) {
			//printf("%d ", A[i]);//cout << A[i] << " ";
			*(array[i]) = A[i];
		}
		//printf("\n");//cout << endl;
		counter++;
	}
	//printf("%d \n", counter);//cout << counter << endl;
	return array[12];
}
void printArray(struct Strategy array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("\n%d ", (array[i].client_credit));
		printf("%d ", (array[i].client_debet));
	}
}
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("\n%d ", array[i]);
		printf("%d ", array[i]);
	}
}
void swap(struct Strategy reciever[], struct Strategy transmitter[], int size) {
	for (int i = 0; i < size; i++) {
		reciever[i].client_credit = transmitter[i].client_credit;
		reciever[i].client_debet = transmitter[i].client_debet;
	}
}