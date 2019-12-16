#include "stdafx.h"
#ifndef API_H
#define API_H
#include <string>
#include <list>
#include <vector>

class Person {
public:
	Person() { score = 0; };
	~Person() {};
public:
	void print_stat();
	int score;
};

struct Answer {
	bool is_correct;
	std::string answer;
};

class Ticket {
public:
	Ticket() { question = "None"; };
	Ticket(const Ticket& ticket);
	~Ticket() {};
public:
	void set_question(const std::string question);
	void add_answer(const std::string answer, const bool is_correct);
	int run(Person &student);
private:
	std::string question;
	std::list<Answer> answers;

};

class Quest {
private:
	std::vector<Ticket> tickets;
	virtual void print_hello();
	virtual void print_farewell();
public: Quest() {};
		~Quest() {};
public:
	int run(Person &student);
	void add_ticket(const Ticket ticket);//construct of copies
};

#endif#pragma once
