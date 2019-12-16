#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char glasn[6]{ 'a','e','i','o','u','y' };
char sogl[20]{ 'b', 'c', 'd', 'f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z' };
char abc[26]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
const int symbols = 8;

int main()
{
	srand(time(NULL));

	char stroka[symbols];

	stroka[0] = abc[rand() % 26];
	printf("%c", stroka[0]);

	int chek = 0;

	for (int t = 0; t < 6; t++)
	{
		if (stroka[0] == glasn[t]) chek++;
	}

	if (chek == 1)
	{
		for (int i = 1; i < symbols; i++)
		{
			if (i % 2 == 0) stroka[i] = sogl[rand() % 20];
			else stroka[i] = glasn[rand() % 6];
			printf("%c", stroka[i]);
		};
	}

	else
	{
		for (int i = 1; i < symbols; i++)
		{
			if (i % 2 == 1) stroka[i] = glasn[rand() % 6];
			else stroka[i] = sogl[rand() % 20];
			printf("%c", stroka[i]);
		};
	}

	//printf("%s\n", stroka);
	return 0;
};
//end
//of all

