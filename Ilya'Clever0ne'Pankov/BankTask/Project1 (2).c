#include <stdio.h>
#include <math.h>
#include <string.h>

int transaction(long int money, long int *bank_account, long int *client_account, double percent_year)
{
	if (bank_account < money)
	{
		return 0;
	}
	*bank_account -= money;
	*client_account += money;
	return 1;
}

int tax(long int income, long int *bank_account, long int *client_account, long int *government_account, double percent_year)
{
	if (percent_year + 10 > 17)
	{
		long int refund;
		long int duty;
		duty = (long int)(income * 0.13);
		*government_account += duty;
		*client_account -= duty;
		refund = (long int)(duty * 0.075);
		*government_account -= refund;
		*bank_account += refund;
	}
}

long int client_income_month(long int client_account, double percent_year)
{
	double percent_month = percent_year / 12.0;
	long int income = (long int)(client_account * percent_month / 100.0);
	return income;
}

void print_bill(int month, long int client_account, long int bank_account, long int government_account)
{
	printf("Month: %d, Client: %.2lf, Bank: %.2lf, Government: %.2lf\n", month, client_account / 100.0, bank_account / 100.0, government_account / 100.0);
}

int main()
{
	long int bank_account = 1e6 * 100;
	long int client_account;
	long int government_account = 0;
	int month = 0;
	double percent_year;
	printf("Enter an amount: ");
	scanf("%ld", &client_account);
	printf("Enter a percent: ");
	scanf("%lf", &percent_year);
	client_account *= 100;
	for(month = 1; month < 13; month++)
	{
		long int income = client_income_month(client_account, percent_year);
		if (transaction(income, &bank_account, &client_account, percent_year) == 0) break;
		tax(income, &bank_account, &client_account, &government_account, percent_year);
		print_bill(month, client_account, bank_account, government_account);
	}
	system("pause");
	return 0;
}
