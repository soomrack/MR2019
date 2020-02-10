#include "cpp_quest.h"
#include <iostream>

CPPQuest initCPPQuest()
{
    CPPQuestTicket ticket;
    ticket.setQuestion("Range of int variable is ");
    ticket.addAnswer("[0, 32767]", false);
    ticket.addAnswer("[-32768, 32767]", true);
    ticket.addAnswer("[-1, 1]", false);
    CPPQuest quest;
    quest.addTicket(ticket);
    return quest;
}

void CPPQuest::printHello()
{
    std::cout << std::endl << "Start new Quest CPP" << std::endl;
    return;
}

void CPPQuest::printFarewell()
{
    std::cout << std::endl << "Quest CPP finished" << std::endl;
    return;
}

