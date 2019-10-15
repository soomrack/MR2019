/*

     15 October 2019
     by Anton Larionov

*/
   
#include <iostream>

long int amount_credit = 1000000;
long int amount_debet = 1000000;

// Для функций вычисления прибыли одного вкладчика по месяцам/за год
// Для функции вычисления дохода банка за год от одного кредитора
int month_debt[12];
long int year_debt;
long int year_income;

// Не использовалось
struct strategy
{
	int* client_debet;
	int* client_credit;
};

// Кредиторы банка по месяцам
// Вкладчики банка по месяцам
// Кредитора банка на его деньги (а не при помощи вкладов) по месяцам
// Общее количество кредиторов на данный месяц;
// Общее количество вкладчиков на данный месяц
// Остаток неиспользованных денег банка в этом месяце
// Доход банка в конце этого месяца
int month_credit_clients[60];
int month_debet_clients[60];
int bank_money_credit_clients[60];
long int all_credit_clients[60];
long int all_debet_clients[60];
long int month_bank_money[60];
long int month_bank_income[60];

// Функция для подсчета месячного дохода банка с одного кредитора (округление не в пользу банка)
long int IncomeMonth(double credit_percent)
{
	double month_credit_percent = (credit_percent / 12.0) / 100.0;
	long int income_month = (long int)((double)(amount_credit)*month_credit_percent);
	return income_month;
}

// Функция для подсчета годового дохода банка с одного кредитора (округление не в пользу банка)
long int IncomeYear(double credit_percent)
{
	long int client_credit = amount_credit;
	year_income = (long int)((double)client_credit * (credit_percent / 100));
	return year_income;
}

// Функция для подсчета годовой прибыли одного вкладчика (округление не в пользу вкладчика)
int YearDebt(double debet_percent)
{
	long int client_account = amount_debet;
	double month_debet_percent = (debet_percent / 12.0) / 100.0;
	for (int month = 1; month < 13; month++)
	{
		long int debt_month = (long int)((double)(client_account * month_debet_percent));
		client_account += debt_month;
	}
	year_debt = client_account - amount_debet;
	;
	return year_debt;
}

// Функция для подсчета прибыли вкладчика по месяцам (округление не в пользу вкладчика)
// НЕ ИСПОЛЬЗОВАЛАСЬ
int MonthDebt(double debet_percent)
{
	long int client_account = amount_debet;
	double month_debet_percent = (debet_percent / 12.0) / 100.0;
	for (int month = 1; month < 13; month++)
	{
		long int debt_month = (long int)((double)(client_account * month_debet_percent));
		client_account += debt_month;
		month_debt[month - 1] = debt_month;
	}
	return 0;
}

// Функция для оптимального приема вкладов и выдачи кредитов, критерий - максимальная прибыль банка в конце срока
// Принимает параметры (срок, счет банка на начало срока, процент по вкладу, процент по кредиту, допустимое количество кредиторов в месяц)
// ПРОВЕРЯЛАСЬ ТОЛЬКО ПРИ ИЗНАЧАЛЬНО ЗАДАННЫХ ЗНАЧЕНИЯХ (5 лет, 20 000 000 у.е., 8 %, 25 %, 100 кредиторов), 1 000 000 = кредит = вклад
// "Срок" вводить в целых годах
bool StrategyOptimal(int period, long int capital, double debet_percent, double credit_percent, int month_credit_client)
{
	int start_number = capital / amount_credit;
	long int lost_capital = capital - (amount_credit * start_number);
	int lost_credit_client = month_credit_client - start_number;
	long int start_income_month = start_number * IncomeMonth(credit_percent);
	// Почему такой if -> Была задумка реализовать разные программы для разных ситуаций (сумма кредита =, >, < суммы вклада)
	if (amount_debet == amount_credit)
	{
		int first_debet_client = lost_credit_client;
		// Подсчитываю доход банка за год, затем за месяц с учетом того, что годовая прибыль вкладчиков подсчитывается и вычитается из годового дохода банка сразу
		long int year_clear_income = (lost_credit_client * IncomeYear(credit_percent) - first_debet_client * YearDebt(debet_percent)) + start_income_month * 12;
		long int month_clear_income = (long int)((double)year_clear_income / 12);
		month_credit_clients[0] = month_credit_client;
		month_debet_clients[0] = first_debet_client;
		month_bank_money[0] = lost_capital;
		month_bank_income[0] = month_clear_income;
		bank_money_credit_clients[0] = start_number;
		all_credit_clients[0] = month_credit_clients[0];
		all_debet_clients[0] = first_debet_client;
		// Цикл для первого года отдельно, т.к. тут кредиты и вклады только появляются, а не "исчезают".
		for (int i = 1; i < 12; i++)
		{
			month_bank_money[i] = month_bank_money[i - 1] + month_bank_income[i - 1];
			month_credit_clients[i] = month_credit_client;
			month_debet_clients[i] = month_credit_client;
			// Стараемся выдать новые кредиты на собственные деньги банка, т.к. это намного выгоднее
			if (month_bank_money[i] > amount_credit)
			{
				month_debet_clients[i] -= month_bank_money[i] / amount_credit;
				bank_money_credit_clients[i] = month_bank_money[i] / amount_credit;
				month_bank_money[i] -= (month_credit_client - month_debet_clients[i]) * amount_credit;
			}
			all_debet_clients[i] = all_debet_clients[i - 1] + month_debet_clients[i];
			all_credit_clients[i] = all_credit_clients[i - 1] + month_credit_clients[i];
			long int new_year_income = (all_credit_clients[i] * IncomeYear(credit_percent) - month_debet_clients[i] * YearDebt(debet_percent));
			month_bank_income[i] += new_year_income / 12;
		}
		// После первого года новый цикл с новыми условиями - кредиторы "старше 12 месяцев" возвращают взятые деньги, а вкладчики получают свои обратно
		// Деньги вкладчиков использовались только для взятия кредитов, поэтому, подразумевается, что кредиторы через 12 месяцев отдают их сразу вкладчикам минуя банк 
		period *= 12;
		for (int i = 12; i < period; i++)
		{
			// В какой то момент банк сможет брать лимит кредиторов целиком на свои деньги, важно не упустить ЭТОТ МОМЕНТ*
			if (month_debet_clients[i - 1] > 0)
			{
				// Кредиторы возвращают деньги банку
				month_bank_money[i] = month_bank_money[i - 1] + month_bank_income[i - 1] + bank_money_credit_clients[i - 12] * amount_credit;
				month_credit_clients[i] = month_credit_client;
				month_debet_clients[i] = month_credit_client;
				if (month_bank_money[i] > amount_credit)
				{
					month_debet_clients[i] -= month_bank_money[i] / amount_credit;
					bank_money_credit_clients[i] = month_bank_money[i] / amount_credit;
					month_bank_money[i] -= (month_credit_client - month_debet_clients[i]) * amount_credit;
				}
				// ЭТОТ МОМЕНТ*
				if (month_debet_clients[i] > 0)
				{
					all_debet_clients[i] = all_debet_clients[i - 1] + month_debet_clients[i] - month_debet_clients[i - 12];
					all_credit_clients[i] = all_credit_clients[i - 1] + month_credit_clients[i] - month_credit_clients[i - 12];
					long int new_year_income = (all_credit_clients[i] * IncomeYear(credit_percent) - month_debet_clients[i] * YearDebt(debet_percent));
					month_bank_income[i] += new_year_income / 12;
				}
				// Когда мы поймали этот момент, вкладчики больше не нужны, поэтому их впредь (0), но прежние вкладчики все еще есть
				else
				{
					month_bank_money[i] = month_bank_money[i - 1] + month_bank_income[i - 1] + bank_money_credit_clients[i - 12] * amount_credit;
					month_credit_clients[i] = month_credit_client;
					month_debet_clients[i] = 0;
					bank_money_credit_clients[i] = month_credit_clients[i];
					month_bank_money[i] -= (month_credit_client - month_debet_clients[i]) * amount_credit;
					all_debet_clients[i] = all_debet_clients[i - 1] + month_debet_clients[i] - month_debet_clients[i - 12];
					all_credit_clients[i] = all_credit_clients[i - 1] + month_credit_clients[i] - month_credit_clients[i - 12];
					long int new_year_income = (all_credit_clients[i] * IncomeYear(credit_percent) - month_debet_clients[i] * YearDebt(debet_percent));
					month_bank_income[i] += new_year_income / 12;
				}
			}
			// Аналогично верхнему "else"
			else
			{
				month_bank_money[i] = month_bank_money[i - 1] + month_bank_income[i - 1] + bank_money_credit_clients[i - 12] * amount_credit;
				month_credit_clients[i] = month_credit_client;
				month_debet_clients[i] = 0;
				bank_money_credit_clients[i] = month_credit_clients[i];
				month_bank_money[i] -= (month_credit_client - month_debet_clients[i]) * amount_credit; 
				all_debet_clients[i] = all_debet_clients[i - 1] + month_debet_clients[i] - month_debet_clients[i - 12];
				all_credit_clients[i] = all_credit_clients[i - 1] + month_credit_clients[i] - month_credit_clients[i - 12];
				long int new_year_income = (all_credit_clients[i] * IncomeYear(credit_percent) - month_debet_clients[i] * YearDebt(debet_percent));
				month_bank_income[i] += new_year_income / 12;
			}
			// Конечный счет банка с возвратом всех вкладов и возвращением всех кредитов
			// Предполагается, что банк играет по совести 
			// Он не считается с переплатой по вкладу (платим проценты сразу при приеме вклада) и долгом кредиторов за оставшиеся неиспользованные месяцы
			if (i == (period - 1))
			{
				month_bank_money[i] += all_credit_clients[i] * amount_credit - all_debet_clients[i] * amount_debet;
			}
		}
	}
	return true;
}


int main()
{
	int period = 5;
	long int capital = 20000000;
	double debet_percent = 8.0;
	double credit_percent = 25.0;
	int month_credit_client = 100;
	StrategyOptimal(period, capital, debet_percent, credit_percent, month_credit_client);
	// Показательная информация за каждый месяц в течение срока
	for (int i = 0; i < (period * 12); i++)
	{
		printf("Lenders this month (%i)\n%i\n", (i+1), month_credit_clients[i]);
		printf("Savers this month\n%i\n", month_debet_clients[i]);
		printf("Lenders with bank money this month\n%li\n", bank_money_credit_clients[i]);
		printf("Total savers at the moment\n%li\n", all_debet_clients[i]);
		printf("Total lenders at the moment\n%li\n", all_credit_clients[i]);
		printf("Bank account at the end of this month\n%li\n", month_bank_money[i]);
		printf("Bank profit at the end of this month\n%li\n\n", month_bank_income[i]);
		if (i == (60 - 1))
		{
			printf("\nBank account at the end without any credits and debets\n%li\n\n", month_bank_money[i]);
		}
	}
	// Количество кредиторов и вкладчиков по месяцам
	printf("\n");
	printf("  Optimal strategy   \n\n");
	for (int i = 0; i < (period * 12); i++)
	{
		printf("%2i) %i     %2i) %i\n", (i + 1), month_credit_clients[i], (i + 1), month_debet_clients[i]);
	}

}
