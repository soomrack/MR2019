#include "clever0ne_quest.h"
#include <iostream>

Clever0neQuest initClever0neQuest()
{
    Clever0neQuestTicket ticket[10];
    Clever0neQuest quest;
    for(int number_of_question = 0; number_of_question < 10; number_of_question++)
    {
        returnQuestion(&ticket[number_of_question], number_of_question);
        returnVariants(&ticket[number_of_question], number_of_question);
        quest.addTicket(ticket[number_of_question]);
    }
    return quest;
}

void Clever0neQuest::printHello()
{
    std::cout << std::endl << "Start Clever0ne's Quest" << std::endl;
    return;
}

void Clever0neQuest::printFarewell()
{
    std::cout << std::endl << "Clever0ne's Quest finished" << std::endl;
    return;
}

void returnQuestion(Clever0neQuestTicket *ticket, int number_of_question)
{
    switch (number_of_question)
    {
        case 0:
            ticket->setQuestion("2 + 2 * 2 = ");
            break;
        case 1:
            ticket->setQuestion("int i = 5;\n++i + ++i = ");
            break;
        case 2:
            ticket->setQuestion("150 + 150 = ");
            break;
        case 3:
            ticket->setQuestion("sizeof(int8_t) = ");
            break;
        case 4:
            ticket->setQuestion("Speed of light (m/s) = ");
            break;
        case 5:
            ticket->setQuestion("Answer to the Ultimate Question of Life, the Universe, and Everything: ");
            break;
        case 6:
            ticket->setQuestion("Number of genders: ");
            break;
        case 7:
            ticket->setQuestion("Number of planets in the Solar System: ");
            break;
        case 8:
            ticket->setQuestion("Number of letters in the Russian alphabet: ");
            break;
        case 9:
            ticket->setQuestion("Number of days in the week: ");
            break;
        default:
            break;
    }
}

void returnVariants(Clever0neQuestTicket *ticket, int number_of_question)
{
    switch (number_of_question)
    {
        case 0:
            ticket->addAnswer("8", false);
            ticket->addAnswer("6", true);
            ticket->addAnswer("222", false);
            break;
        case 1:
            ticket->addAnswer("14", true);
            ticket->addAnswer("13", false);
            ticket->addAnswer("12", false);
            break;
        case 2:
            ticket->addAnswer("300", true);
            ticket->addAnswer("Three hundred", true);
            ticket->addAnswer("228", false);
            break;
        case 3:
            ticket->addAnswer("8", false);
            ticket->addAnswer("2", false);
            ticket->addAnswer("1", true);
            break;
        case 4:
            ticket->addAnswer("3.0e8", false);
            ticket->addAnswer("300000", false);
            ticket->addAnswer("299792458", true);
            break;
        case 5:
            ticket->addAnswer("42", true);
            ticket->addAnswer("Gladiolus", false);
            ticket->addAnswer("a", false);
            break;
        case 6:
            ticket->addAnswer("3", false);
            ticket->addAnswer("2", true);
            ticket->addAnswer("207", false);
            break;
        case 7:
            ticket->addAnswer("8", true);
            ticket->addAnswer("9", false);
            ticket->addAnswer("10", false);
            break;
        case 8:
            ticket->addAnswer("26", false);
            ticket->addAnswer("32", false);
            ticket->addAnswer("33", true);
            break;
        case 9:
            ticket->addAnswer("5", false);
            ticket->addAnswer("7", true);
            ticket->addAnswer("31", false);
            break;
        default:
            break;
    }
}
