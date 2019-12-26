#include "quest.h"
#include <iostream>
#include <set>

DENQuest init_den_quest() {
	DENQuestTicket1 ticket1;
	ticket1.set_question("22-15?");
	ticket1.add_answer("12", false);
	ticket1.add_answer("7", true);
	ticket1.add_answer("8", false);
	ticket1.add_answer("9", false);

	DENQuestTicket2 ticket2;
	ticket2.set_question("The capital of Belarus?");
	ticket2.add_answer("Kiyv", false);
	ticket2.add_answer("Brest", false);
	ticket2.add_answer("Minsk", true);
	ticket2.add_answer("Praga", false);

	DENQuestTicket2 ticket3;
	ticket3.set_question("In Africa");
	ticket3.add_answer("Iran", false);
	ticket3.add_answer("Egypet", true);
	ticket3.add_answer("Irak", false);
	ticket3.add_answer("Australia", false);

	DENQuest quest;
	quest.add_ticket(&ticket1);
	quest.add_ticket(&ticket2);
	quest.add_ticket(&ticket3);
	return quest;
}
int DENQuestTicket1::run(Person& student) 
{
	//Print questions
	int number_of_answer = 0;
	std::set<int> current_answers;
	std::cout << "\n" << question << std::endl;
	for (std::list<Answer>::iterator current_answer = answers.begin();
		current_answer != answers.end();
		current_answer++) 
	{
		number_of_answer++;
		if (current_answer->is_correct) 
		{
			current_answers.insert(number_of_answer);
		}
		std::cout << number_of_answer << ")" << current_answer->answer << "\n";
	}
	//Print user response
	std::cout << "Enter number of correct answer." << "\n\n";
	//Get user answer
	std::string response;
	std::cin >> response;
	//Check response
	bool result = current_answers.find(std::stoi(response)) != current_answers.end();
	//Save result
	if (result) 
	{
		student.score++;
	}
	return 0;
}
int DENQuestTicket2::run(Person& student) 
{
	int number_of_answer = 0;
	std::set<std::string> current_answers;
	std::cout << "\n" << question << '\n' << '\n';
	for (std::list<Answer>::iterator current_answer = answers.begin();
		current_answer != answers.end();
		current_answer++) 
	{
		number_of_answer++;
		if (current_answer->is_correct) 
		{
			current_answers.insert(current_answer->answer);
		}
		std::cout << current_answer->answer << "\n";
	}
	//Print user response
	std::cout << "Enter your answer." << "\n\n";
	//Get user answer
	std::string response;
	std::cin >> response;
	//Check response
	bool result = current_answers.find(response) != current_answers.end();
	//Save result
	if (result) 
	{
		student.score++;
	}
	return 0;
}
void DENQuest::print_hello() 
{
	std::cout << "Start new Test with 2 types of tickets" << "\n";
	return;
}
void DENQuest::print_farewell() 
{
	std::cout << "\n" << "Test finished" << "\n";
	return;
}
void DENQuest::add_ticket(Ticket* ticket)
{
	tickets.push_back(ticket);
}
int DENQuest::run(Person& student)
{
	print_hello();
	for (std::vector<Ticket*>::iterator current_ticket = tickets.begin();
		current_ticket != tickets.end();
		++current_ticket)
	{
		(*current_ticket)->run(student);
	}
	print_farewell();
	return 0;
}