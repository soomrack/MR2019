#include "api.h"
#include <iostream>
#include <set>

void Ticket::set_question(const std::string question) {
	this->question = question;
	return;
}
Ticket::Ticket(const Ticket& ticket) {
	question = ticket.question;
	answers = ticket.answers;

}

void Ticket::add_answer(const std::string answer, const bool is_correct) {
	Answer struct_answer;
	struct_answer.is_correct = is_correct;
	struct_answer.answer = answer;
	this->answers.push_back(struct_answer);
	return;
}
void Quest::add_ticket(const Ticket ticket) {
	this->tickets.push_back(ticket);
}
int Quest::run(Person &student) {
	print_hello();

	for (std::vector<Ticket>::iterator current_ticket = tickets.begin();
		current_ticket != tickets.end();
		current_ticket++) {
		current_ticket->run(student);

	}
	print_farewell();
	return 0;
}
void Quest::print_hello() {
	std::cout << "\n " << "Start new Quest" << "\n";
	return;
}
void Quest::print_farewell() {
	std::cout << "\n " << "Quest finished" << "\n";
	return;
}
int Ticket::run(Person &student) {
	//Print questions
	int number_of_answer = 0;
	std::set<int> current_answers;
	for (std::list<Answer>::iterator current_answer = answers.begin();
		current_answer != answers.end();
		current_answer++) {
		number_of_answer++;
		if (current_answer->is_correct) {
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
	if (result) {
		student.score++;
	}
	return 0;
}
void Person::print_stat() {
	std::cout << "\n " << "Your score is " << score <<"\n";
	return;
}
