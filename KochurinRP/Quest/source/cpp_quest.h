#ifndef CPP_QUEST_H
#define CPP_QUEST_H

#include "api.h"

class CPPQuestTicket : public Ticket {
public:	CPPQuestTicket() {};
		~CPPQuestTicket() {};

};

class CPPQuest : public Quest {
public:
	CPPQuest() {};
	~CPPQuest() {};
private:
	virtual void print_hello();
	virtual void print_farewell();
};

CPPQuest init_cpp_quest();

#endif