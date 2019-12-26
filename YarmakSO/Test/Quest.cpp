#include "Quest.h"
#include <iostream>
CXXQuest init_cxx_quest() {
	CXXQuestTicket ticket;
	ticket.set_question("Какая планета находится ближе всех к Солнцу?");
	ticket.add_answer("Марс", false);
	ticket.add_answer("Земля", false);
	ticket.add_answer("Венера", false);
	ticket.add_answer("Меркурий", true);

	CXXQuestTicket ticket2;
	ticket2.set_question("В каком году Гагарин полетел в космос?");
	ticket2.add_answer("1941", false);
	ticket2.add_answer("1951", false);
	ticket2.add_answer("1961", true);
	ticket2.add_answer("1971", false);

	CXXQuestTicket ticket3;
	ticket3.set_question("Сколько букв в английском алфавите?");
	ticket3.add_answer("25", false);
	ticket3.add_answer("26", true);
	ticket3.add_answer("27", false);
	ticket3.add_answer("28", false);
	
	CXXQuest quest;
	quest.add_ticket(ticket);
	quest.add_ticket(ticket2);
	quest.add_ticket(ticket3);
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
