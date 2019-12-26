#ifndef DEN_QUEST_H
#define DEN_QUEST_H

#include "api.h"
#include <set>
#include <iostream>

class DENQuestTicket1 : public Ticket
{
public:	
	DENQuestTicket1() {};
	~DENQuestTicket1() {};
public:
	virtual int run(Person& student);
};

class DENQuestTicket2 : public Ticket
{
public:	
	DENQuestTicket2() {};
	~DENQuestTicket2() {};
public:
	virtual int run(Person& student);
};

class DENQuest : public Quest 
{
public:
	DENQuest() {};
	~DENQuest() {};
	virtual int run(Person& student);
	virtual void add_ticket(Ticket* ticket);
	std::vector<Ticket*> tickets;
private:
	virtual void print_hello();
	virtual void print_farewell();
};

DENQuest init_den_quest();

#endif
