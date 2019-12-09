#include "cpp_quest.h"
#include <iostream>
CXXQuest init_cxx_quest() {
	CXXQuestTicket ticket;
	ticket.set_question("Range of int variable is:");
	ticket.add_answer("[0, 32255]", false);
	ticket.add_answer("[-32768, 32767]", true);

	CXXQuest quest;
	quest.add_ticket(ticket);
	return quest;
}
void CXXQuest::print_hello() {
	std::cout << "\n " << "Start new CXXQuest" << "\n";
	return;
}
void CXXQuest::print_farewell() {
	std::cout << "\n " << "Quest CXX finished" << "\n";
	return;
}

