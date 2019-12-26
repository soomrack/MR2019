#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Quest 
{
private:						//можно получить доступ только из класса
	void Test();

public:							//можно получить доступ извне этой же структуры или класса
	vector<Quest> questions;
	string question;
	string answer;

	Quest() 
	{
		question = "";
		answer = "";
	}
	
	bool check_answer(string right)
	{
		if (answer == right) {return true;}
		else {return false;}
	}

};

extern void Start();	//чтобы main не ругалс€, 

class BadNews
{
public:
	virtual const char* message() { return "“ак не пойдЄт!"; }
};

class GoodNews : public BadNews
{
public:
	virtual const char* message() { return "ќтлична€ работа!"; }
};

extern int Result(); 