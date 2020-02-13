#ifndef AUTHOR_QUEST
#define AUTHOR_QUEST

#include "Interface.h"

struct Questions
{
	std::string questionOne;
	std::string questionTwo;
};

class AuthorQuestTicket : public Ticket
{
private:
	Questions connectedQuestions;
	std::list<Answer> firstAnswers;
	std::list<Answer> SecondAnswers;
public:
	AuthorQuestTicket() {};
	AuthorQuestTicket(const AuthorQuestTicket& ticket);
	~AuthorQuestTicket() {};
public:
	void set_connected_questions(const std::string questionOne, const std::string questionTwo);
	void add_first_answers(const std::string answer, const bool is_correct);
	void add_second_answers(const std::string answer, const bool is_correct);
	int show_easter_egg(Person& student);
};

class AuthorQuest : public Quest
{
private:
	std::vector<AuthorQuestTicket> specialTickets;
private:
	virtual void print_hello();
	virtual void print_farewell();
public:
	AuthorQuest() {};
	~AuthorQuest() {};	
public:
	void notify_user();
	void end_surprise();
	void add_special_ticket(const AuthorQuestTicket ticket);
	int show_easter_egg(Person& student);
	int run_special_quest(Person& student);
};

//AuthorQuest init_author_quest();

#endif
