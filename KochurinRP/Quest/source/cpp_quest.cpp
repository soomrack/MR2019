#include <iostream>
#include "cpp_quest.h"
#include "api.h"

CPPQuest init_cpp_quest() {
	CPPQuestTicket ticket1;
	ticket1.set_question("How many oceans are there on the earth?");
	ticket1.add_answer("4", false);
	ticket1.add_answer("5", true);
	ticket1.add_answer("6",false);
	CPPQuestTicket ticket2;
	ticket2.set_question("What is the longest river in the world?");
	ticket2.add_answer("Amazon", true);
	ticket2.add_answer("Nile", false);
	ticket2.add_answer("Lena", false);
	CPPQuestTicket ticket3;
	ticket3.set_question("How many chromosomes are there in the human genome?");
	ticket3.add_answer("23", false);
	ticket3.add_answer("47", false);
	ticket3.add_answer("46", true);
	CPPQuestTicket ticket4;
	ticket4.set_question("Which element of the periodic system of chemical elements is denoted as 'Ag'?");
	ticket4.add_answer("Silver", true);
	ticket4.add_answer("Gold", false);
	ticket4.add_answer("Platinum", false);
	CPPQuestTicket ticket5;
	ticket5.set_question("How many planets are there in the solar system?");
	ticket5.add_answer("7", false);
	ticket5.add_answer("8", true);
	ticket5.add_answer("9", false);
	CPPQuest quest;
	quest.add_ticket(ticket1);
	quest.add_ticket(ticket2);
	quest.add_ticket(ticket3);
	quest.add_ticket(ticket4);
	quest.add_ticket(ticket5);
	return quest;
}

void CPPQuest::print_hello() {
	std::cout << "\n " << "Start new Quest" << "\n";
	return;
}

void CPPQuest::print_farewell() {
	std::cout << "\n " << "Quest finished" << "\n";
	return;
}
