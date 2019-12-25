#include "cpp_quest.h"
#include <iostream>
CXXQuest init_cxx_quest() {
	setlocale(LC_ALL, "RUSSIAN");

	CXXQuestTicket ticket_m1;
	ticket_m1.set_multi();

	CXXQuestTicket ticket_m2;
	ticket_m2.set_multi();

	CXXQuestTicket ticket1;
	ticket1.set_question("В каком году началась Вторая Мировая война?");
	ticket1.add_answer("1940", false);
	ticket1.add_answer("1939", true);
	ticket1.add_answer("1917", false);
	ticket1.add_answer("1941", false);

	CXXQuestTicket ticket2;
	ticket2.set_question("Точная дата первого полета человека в космос");
	ticket2.add_answer("1 января 1977 года", false);
	ticket2.add_answer("15 июня 1999", false);
	ticket2.add_answer("12 апреля 1961", true);
	ticket2.add_answer("23 февраля 1949", false);
	
	CXXQuestTicket ticket3;
	ticket3.set_question("В каком году был разработан первый механический аналоговый компьютер?");
	ticket3.add_answer("1888", false);
	ticket3.add_answer("1927", true);
	ticket3.add_answer("2018", false);
	ticket3.add_answer("1934", false);

	CXXQuestTicket ticket4;
	ticket4.set_question("Как звали основателя компании Apple?");
	ticket4.add_answer("Билл Гейтс", false);
	ticket4.add_answer("Владимир Путин", false);
	ticket4.add_answer("Стив Джобс", true);
	ticket4.add_answer("Илья Ляпцев", false);

	CXXQuestTicket ticket5;
	ticket5.set_question("Сколько хромосом у коровы?");
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
