#ifndef CPP_QUEST_H
#define CPP_QUEST_H

#include "api.h"

class CXXQuestTicket : public Ticket {
public:	CXXQuestTicket() {};
		~CXXQuestTicket() {};

};

class CXXQuest : public Quest {
public:
	CXXQuest() {};
	~CXXQuest() {};
private:
	virtual void print_hello();
	virtual void print_farewell();

};

CXXQuest init_cxx_quest();

#endif
