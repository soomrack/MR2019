#include "quest.h"
#include <iostream>
DENQuest init_cxx_quest() {
	setlocale(LC_ALL, "RUSSIAN");
	DENQuestTicket ticket1;
	ticket1.set_question("1-55?");
	ticket1.add_answer("-53", false);
	ticket1.add_answer("-54", true);
	ticket1.add_answer("-55", false);
	ticket1.add_answer("-56", false);

	DENQuestTicket ticket2;
	ticket2.set_question("22+1");
	ticket2.add_answer("12", false);
	ticket2.add_answer("24", false);
	ticket2.add_answer("23", true);
	ticket2.add_answer("214", false);

	DENQuestTicket ticket3;
	ticket3.set_question("1/0");
	ticket3.add_answer("0", false);
	ticket3.add_answer("8", true);
	ticket3.add_answer("1", false);
	ticket3.add_answer("2", false);

	DENQuestTicket ticket4;
	ticket4.set_question("3*0");
	ticket4.add_answer("3", false);
	ticket4.add_answer("1", false);
	ticket4.add_answer("0", true);
	ticket4.add_answer("4", false);

	DENQuestTicket ticket5;
	ticket5.set_question("0-0");
	ticket5.add_answer("8", false);
	ticket5.add_answer("2", false);
	ticket5.add_answer("1", false);
	ticket5.add_answer("0", true);

	DENQuest quest;
	quest.add_ticket(ticket1);
	quest.add_ticket(ticket2);
	quest.add_ticket(ticket3);
	quest.add_ticket(ticket4);
	quest.add_ticket(ticket5);
	return quest;
}
void DENQuest::print_hello() {
	std::cout << "Start new Test" << "\n";
	return;
}
void DENQuest::print_farewell() {
	std::cout << "\n" << "Test finished" << "\n";
	return;
}