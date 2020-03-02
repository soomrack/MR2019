#include "Author_Quest.h"
#include <iostream>
#include <set>

//AuthorQuest init_author_quest()
//{
//	AuthorQuest quest;
//	// First
//	AuthorQuestTicket ticketOne;
//	ticketOne.set_question("Range of int variable is:");
//	ticketOne.add_answer("[0, 32255]", false);
//	ticketOne.add_answer("[-32768, 32767]", true);
//	quest.add_ticket(ticketOne);
//	// Second
//	AuthorQuestTicket ticketTwo;
//	ticketTwo.set_question("How much is 2 + 2?");
//	ticketTwo.add_answer("2", false);
//	ticketTwo.add_answer("4", true);
//	ticketTwo.add_answer("5", false);
//	quest.add_ticket(ticketTwo);
//	// Third
//	AuthorQuestTicket ticketThree;
//	ticketThree.set_question("When was the Polytechnic University founded?");
//	ticketThree.add_answer("1896", false);
//	ticketThree.add_answer("1897", false);
//	ticketThree.add_answer("1899", true);
//	ticketThree.add_answer("1901", false);
//	quest.add_ticket(ticketThree);
//	// Fourth
//	AuthorQuestTicket ticketFour;
//	ticketFour.set_question("Who created Google?");
//	ticketFour.add_answer("Bruce Wayne", false);
//	ticketFour.add_answer("Sergey Brin", true);
//	ticketFour.add_answer("Lawrence Page", true);
//	ticketFour.add_answer("Tony Stark", false);
//	quest.add_ticket(ticketFour);
//	//
//	return quest;
//}

void AuthorQuest::print_hello()
{
	std::cout << "\n" << "Start new AuthorQuest" << "\n";
	return;
}

void AuthorQuest::print_farewell()
{
	std::cout << "\n" << "AuthorQuest finished" << "\n";
	return;
}


////
AuthorQuestTicket::AuthorQuestTicket(const AuthorQuestTicket& ticket)
{
	connectedQuestions = ticket.connectedQuestions;
	firstAnswers = ticket.firstAnswers;
	SecondAnswers = ticket.SecondAnswers;
}

void AuthorQuestTicket::set_connected_questions(const std::string questionOne, const std::string questionTwo)
{
	connectedQuestions.questionOne = questionOne;
	connectedQuestions.questionTwo = questionTwo;
	return;
}

void AuthorQuestTicket::add_first_answers(const std::string answer, const bool is_correct)
{
	Answer struct_answer;
	struct_answer.is_correct = is_correct;
	struct_answer.answer = answer;
	this->firstAnswers.push_back(struct_answer);
	return;
}

void AuthorQuestTicket::add_second_answers(const std::string answer, const bool is_correct)
{
	Answer struct_answer;
	struct_answer.is_correct = is_correct;
	struct_answer.answer = answer;
	this->SecondAnswers.push_back(struct_answer);
	return;
}

int AuthorQuestTicket::show_easter_egg(Person& student)
{
	std::set<int> current_answers;
	int number_of_answer = 0;
	std::cout << "\n" << connectedQuestions.questionOne << "\n";
	for (std::list<Answer>::iterator current_answer = firstAnswers.begin();
		current_answer != firstAnswers.end(); current_answer++)
	{
		number_of_answer++;
		if (current_answer->is_correct)
		{
			current_answers.insert(number_of_answer);
		}
		std::cout << number_of_answer << ")" << current_answer->answer << "\n";
	}
	std::cout << "Enter number of correct answer." << "\n\n";
	std::string response;
	std::cin >> response;
	bool result = current_answers.find(std::stoi(response)) != current_answers.end();
	if (result)
	{
		int number_of_answer = 0;
		std::cout << "\n" << connectedQuestions.questionTwo << "\n";
		for (std::list<Answer>::iterator current_answer = SecondAnswers.begin();
			current_answer != SecondAnswers.end(); current_answer++)
		{
			number_of_answer++;
			if (current_answer->is_correct)
			{
				current_answers.insert(number_of_answer);
			}
			std::cout << number_of_answer << ")" << current_answer->answer << "\n";
		}
		std::cout << "Enter number of correct answer." << "\n\n";
		std::string response;
		std::cin >> response;
		bool result = current_answers.find(std::stoi(response)) != current_answers.end();
		if (result) {}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

////
void AuthorQuest::notify_user()
{
	std::cout << "\n" << "WOW! You are lucky, give the answer to two questions at once and win." << "\n" 
		<< "But even one mistake will be costly." << "\n";
	std::cout << "Are you ready?" << "\n";
	system("pause");
	return;
}

void AuthorQuest::end_surprise()
{
	std::cout << "\n" << "Unfortunately, that's all. You did a good job!" << "\n";
	return;
}

void AuthorQuest::add_special_ticket(const AuthorQuestTicket ticket)
{
	this->specialTickets.push_back(ticket);
}

int AuthorQuest::show_easter_egg(Person& student)
{
	notify_user();
	for (std::vector<AuthorQuestTicket>::iterator current_ticket = specialTickets.begin();
		current_ticket != specialTickets.end(); current_ticket++)
	{
		if (current_ticket->show_easter_egg(student))
		{
			student.score++;
			std::cout << "\n" << "Right!";
		}
		else
		{
			std::cout << "\n" << "Oh,you are lose. Don't worry!" << "\n\n";
		}
		std::cout << "Let's see, do we have anything else?" << "\n";
	}
	end_surprise();
	return 0;
}

int AuthorQuest::run_special_quest(Person& student)
{
	run(student);
	show_easter_egg(student);
	return 0;
}