#ifndef CPP_QUEST_H
#define CPP_QUEST_H

#include "api.h"

class CPPQuestTicket : public Ticket
{
    public:
        CPPQuestTicket(){};
        ~CPPQuestTicket(){};
};

class CPPQuest : public Quest
{
    public:
        CPPQuest(){};
        ~CPPQuest(){};
    private:
        virtual void printHello();
        virtual void printFarewell();
};

CPPQuest initCPPQuest();

#endif