#ifndef CPP_QUEST_H
#define CPP_QUEST_H

#include "api.h"

class DENQuestTicket : public Ticket {
public:	DENQuestTicket() {};
	  ~DENQuestTicket() {};

};

class DENQuest : public Quest {
public:
	DENQuest() {};
	~DENQuest() {};
private:
	virtual void print_hello();
	virtual void print_farewell();

};

DENQuest init_cxx_quest();

#endif
