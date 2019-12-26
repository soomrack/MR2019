#include "api.h"
#include <iostream>
#include <set>

void Ticket::set_question(const std::string question) 
{
	this->question = question;
	return;
}

Ticket::Ticket(const Ticket& ticket) 
{  // как то сюда ран вставить
	this->question = ticket.question;
	this->answers = ticket.answers;
}

void Ticket::add_answer(const std::string answer, const bool is_correct) 
{
	Answer struct_answer;
	struct_answer.is_correct = is_correct;
	struct_answer.answer = answer;
	this->answers.push_back(struct_answer);
	return;
}

void Quest::add_ticket(const Ticket& ticket)
{
	this->tickets.push_back(ticket);
}

int Quest::run(Person& student) 
{
	print_hello();
	for (std::vector<Ticket>::iterator current_ticket = tickets.begin();
		current_ticket != tickets.end();
		current_ticket++) 
	{
		current_ticket->run(student);
	}
	print_farewell();
	return 0;
}

void Quest::print_hello() 
{
	std::cout << "\n" << "Start new Test" << "\n";
	return;
}

void Quest::print_farewell() 
{
	std::cout << "\n" << "Test finished" << "\n";
	return;
}

int Ticket::run(Person& student) 
{
	std::cout << "Error";
	return 0;
}

void Person::print_stat() {
	std::cout << "\n" << "Your score is " << score << "\n";
	return;
}