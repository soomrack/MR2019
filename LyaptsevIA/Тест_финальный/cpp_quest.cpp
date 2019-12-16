#include "cpp_quest.h"
#include <iostream>
CXXQuest init_cxx_quest() {
	setlocale(LC_ALL, "RUSSIAN");
	CXXQuestTicket ticket1;
	ticket1.set_question("В каком году началась Вторая Мировая война?");
	ticket1.add_answer("1940", false);
	ticket1.add_answer("1939", true);
	ticket1.add_answer("1917", false);
	ticket1.add_answer("1941", false);

	CXXQuestTicket ticket2;
	ticket2.set_question("В каком году был разработан первый механический аналоговый компьютер?");
	ticket2.add_answer("1935", false);
	ticket2.add_answer("1966", false);
	ticket2.add_answer("1946", true);
	ticket2.add_answer("1643", false);

	CXXQuestTicket ticket3;
	ticket3.set_question("Кто разработал BionicKangaroo?");
	ticket3.add_answer("Apple", false);
	ticket3.add_answer("Lyaptsev Incorporated", false);
	ticket3.add_answer("Festo Bionic Learning Network", true);
	ticket3.add_answer("Fablab", false);

	CXXQuestTicket ticket4;
	ticket4.set_question("Как назывался первый полнометражный цветной фильм?");
	ticket4.add_answer("Титаник", false);
	ticket4.add_answer("Бекки Шарп", true);
	ticket4.add_answer("La Cucaracha", false);
	ticket4.add_answer("Парад в Дели", false);

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