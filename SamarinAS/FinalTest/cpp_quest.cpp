#include "stdafx.h"
#include "cpp_quest.h"
#include <iostream>


CXXQuest init_cxx_quest() {
	setlocale(LC_ALL, "RUSSIAN");
	CXXQuestTicket ticket;
	ticket.set_question("Вопрос номер 1 \nСолько будет 2+2*2?");
	ticket.add_answer("[8]", false);
	ticket.add_answer("[6]", true);
	ticket.add_answer("[4]", false);
	ticket.add_answer("[2]", false);

	CXXQuestTicket ticket1;
	ticket1.set_question("Вопрос номер 2\nЧему равен Sin30");
	ticket1.add_answer("[0]", false);
	ticket1.add_answer("[1]", false);
	ticket1.add_answer("[2]", false);
	ticket1.add_answer("[1/2]", true);

	CXXQuestTicket ticket2;
	ticket2.set_question("Вопрос номер 3\nПродолжи фразу от перестановки слагаемых...");
	ticket2.add_answer("[слагаемые мняются местами]", false);
	ticket2.add_answer("[частное станет меньше]", false);
	ticket2.add_answer("[значение суммы не меняется]", true);
	ticket2.add_answer("[лучше не станет]", false);

	CXXQuest quest;
	quest.add_ticket(ticket);
	quest.add_ticket(ticket1);
	quest.add_ticket(ticket2);
	return quest;
}
void CXXQuest::print_hello() {
	std::cout << "\n " << "Тест начат!" << "\n";
	return;
}
void CXXQuest::print_farewell() {
	std::cout << "\n " << "Тест окончен..." << "\n";
	return;
}
