#ifndef CLEVER0NE_QUEST_H
#define CLEVER0NE_QUEST_H

#include "api.h"
#include <string>

class Clever0neQuestTicket : public Ticket
{
    public:
        Clever0neQuestTicket(){};
        ~Clever0neQuestTicket(){};
};

class Clever0neQuest : public Quest
{
    public:
        Clever0neQuest(){};
        ~Clever0neQuest(){};
    private:
        virtual void printHello();
        virtual void printFarewell();
};

Clever0neQuest initClever0neQuest();

void returnVariants(Clever0neQuestTicket *, int);
void returnQuestion(Clever0neQuestTicket *, int);

#endif