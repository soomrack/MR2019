// Tic Tac Toe
// Area: three by three
// Find the number of outcome option
// playerOne is first

#include <iostream>

using namespace std;

int countCombinations = 0;
char area[9] = { '\0' };
bool checkPlayer = false;

bool put(int place)
{
	if (area[place] == '\0')
	{
		if (checkPlayer == false)
		{
			area[place] = 'X';
			checkPlayer = true;
		}
		else
		{
			area[place] = 'O';
			checkPlayer = false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool check_win(int first, int second, int third)
{
	if ( ((area[first] == 'X') && (area[second] == 'X') && (area[third] == 'X')) || ((area[first] == 'O') && (area[second] == 'O') && (area[third] == 'O')) )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_finished()
{
	if (check_win(0, 1, 2) || check_win(3, 4, 5) || check_win(6, 7, 8) || check_win(0, 3, 6) || check_win(1, 4, 7) || check_win(2, 5, 8) || check_win(0, 4, 8) || check_win(2, 4, 6) || (area[0] != '\0' && area[1] != '\0' && area[2] != '\0' && area[3] != '\0' && area[4] != '\0' && area[5] != '\0' && area[6] != '\0' && area[7] != '\0' && area[8] != '\0') )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void end()
{
	for (int i = 0; i < 9; i++)
	{
		if (put(i))
		{
			if (is_finished())
			{
				countCombinations++;
			}
			else
			{
				end();
			}
			area[i] = '\0';
		}
	}
}

int main()
{
	end();
	cout << countCombinations << endl;
}