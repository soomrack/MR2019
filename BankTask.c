#include <stdio.h>
#include <math.h>
#include <string.h>

int transaction(long int money, long int* account1, long int* account2)
{
	if (account1 < money)
	{
		return 0;
	}
	*account1 -= money;
	*account2 += money;
	return 1;
}

long int incomeMonth(long int account, double percent)
{
	long int income = (long int)(account * percent / 100.0);
	return income;
}

void printBill(int month, int index, long int clientAccount, long int bankAccount, long int governmentAccount)
{
	printf("Month: %d, Client%d: %.2lf, Bank: %.2lf, Government: %.2lf\n", month, index, clientAccount / 100.0, bankAccount / 100.0, governmentAccount / 100.0);
}

struct Bank
{
	long int account;
	long int income;
	double percent;
};

struct Client
{
	long int account;
	long int income;
	double percent;
};

struct Government
{
	long int account;
	long int income;
	double percent;
};

int main()
{
	struct Bank Sberbank;
	struct Client Client[1000];
	struct Government RF;
	Sberbank.account = 1e6 * 100;
	RF.account = 0;
	/*printf("Enter an amount: ");
	scanf_s("%ld", &Client1.account);*/
	/*printf("Enter a percent: ");
	scanf_s("%lf", &Client1.percent);*/
	for (int index = 0; index < 1000; index++)
	{
		Client[index].account = 1000;
		Client[index].percent = 10;
		Client[index].account *= 100;
		for (int month = 1; month < 13; month++)
		{
			Client[index].income = incomeMonth(Client[index].account, Client[index].percent / 12.0);
			if (transaction(Client[index].income, &Sberbank.account, &Client[index].account) == 0) break;
			if (Client[index].percent + 10 > 17) RF.percent = 13;
			else RF.percent = 0;
			RF.income = incomeMonth(Client[index].income, RF.percent);
			if (transaction(RF.income, &Client[index].account, &RF.account) == 0) break;
			if (RF.percent != 0.0) Sberbank.percent = 7.5;
			else Sberbank.percent = 0;
			Sberbank.income = incomeMonth(RF.income, Sberbank.percent);
			if (transaction(Sberbank.income, &RF.account, &Sberbank.account) == 0) break;
			printBill(month, index, Client[index].account, Sberbank.account, RF.account);
		}
	}
	system("pause");
	return 0;
}