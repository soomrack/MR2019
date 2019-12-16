// rewrite test 1 +1
// test 2

#include <iostream>
#include <string>
//две строки, вернуть номер элемента с первым символом короткой строки в большой

using namespace std;
//hgosdhgsihellatjgrm
string Big_String = "hgosdhgsihellatjgrm1111123birjh";
string Small_String = "1112";
string test = "ab";
bool Flag = false;
int Counter_Big = 0;
int Counter_Small = 0;
char Current_Big_Char = 0;
char Current_Small_Char = 0;
bool Found_Smth = false;
bool First_Char = false;
bool IF_String = false;
int Result = 0;

char check_char(char A, char B)
{	
	bool result = 0;

	if (A == B)
	{
		result = true;
		Found_Smth = true;
	}
	else
	{
		result = false;
		Found_Smth = false;
		Counter_Small = 0;
		First_Char = false;
	}

	if (First_Char == false && Found_Smth == true)
	{
		Result = Counter_Big;
		First_Char = true;
	}

	return result;
}

bool check_end_of_string(char A)
{
	int flag = false;
	int Int_Of_Char = 1;

	Int_Of_Char = (int)A;

	if (Int_Of_Char == 0)		//check end of string
	{
		Flag = true;
		flag = true;
	}

	return flag;
}

int main()
{
	
	/*char x = Big_String[1];
	char a = test[0];
	char b = test[1];
	char c = test[2];*/

	/*int gh = (int)c;
	if (gh == 0)
	{
		Flag = true;
	}*/

	while (Flag == false)
	{			
		Current_Big_Char = Big_String[Counter_Big];
		Current_Small_Char = Small_String[Counter_Small];

		if (check_char(Current_Big_Char, Current_Small_Char) == true)
		{			
			if (check_end_of_string(Small_String[Counter_Small + 1]) == true)
			{				
				Flag = true;
				IF_String = true;
			}
			else
			{
				Counter_Small++;
			}			
		}
		else
		{
			if (check_char(Current_Big_Char, Small_String[0]) == true)
			{				
				Counter_Small = 1;
			}
		}

		if (check_end_of_string(Big_String[Counter_Big + 1]) == true)	//if end of big string -> return number of proper char
		{
			Flag = true;
		}
		Counter_Big++;
	}

	//cout << Current_Big_Char << endl;
	cout << "Check for small string: " << IF_String << endl;
	if (IF_String == true)
	{
		cout << "Number of first char: " << Result << endl;
	}
	//std::cout << "Hello World!\n";
	//cout << Flag << endl;
}

