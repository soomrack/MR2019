#include "quest.h"
#include <iostream>
CXXQuest init_cxx_quest() {
	setlocale(LC_ALL, "RUSSIAN");
	CXXQuestTicket ticket1;
	ticket1.set_question("question1");
	ticket1.add_answer("1940", false);
	ticket1.add_answer("1939", true);
	ticket1.add_answer("1917", false);
	ticket1.add_answer("1941", false);

	CXXQuestTicket ticket2;
	ticket2.set_question("question2");
	ticket2.add_answer("1", false);
	ticket2.add_answer("2", false);
	ticket2.add_answer("3", true);
	ticket2.add_answer("4", false);

	CXXQuestTicket ticket3;
	ticket3.set_question("question3");
	ticket3.add_answer("1888", false);
	ticket3.add_answer("1927", true);
	ticket3.add_answer("2018", false);
	ticket3.add_answer("1934", false);

	CXXQuestTicket ticket4;
	ticket4.set_question("question4");
	ticket4.add_answer("1", false);
	ticket4.add_answer("2", false);
	ticket4.add_answer("3", true);
	ticket4.add_answer("4", false);

	CXXQuestTicket ticket5;
	ticket5.set_question("question5");
	ticket5.add_answer("46", false);
	ticket5.add_answer("68", false);
	ticket5.add_answer("38", false);
	ticket5.add_answer("120", true);

	CXXQuest quest;
	quest.add_ticket(ticket1);
	quest.add_ticket(ticket2);
	quest.add_ticket(ticket3);
	quest.add_ticket(ticket4);
	quest.add_ticket(ticket5);
	return quest;
}
void CXXQuest::print_hello() {
	std::cout << "Start new Test" << "\n";
	return;
}
void CXXQuest::print_farewell() {
	std::cout << "\n" << "Test finished" << "\n";
	return;
}