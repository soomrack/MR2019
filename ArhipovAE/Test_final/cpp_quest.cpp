#include "cpp_quest.h"
#include <iostream>
CXXQuest init_cxx_quest() {
	CXXQuestTicket ticket1;
	ticket1.set_question("When was the first world war?");
	ticket1.add_answer("1. 1913 - 1918", false);
	ticket1.add_answer("2. 1914 - 1919", false);
	ticket1.add_answer("3. 1914 - 1918", true);
	ticket1.add_answer("4. 1912 - 1916", false);

	CXXQuestTicket ticket2;
	ticket2.set_question("The most popular element in the world?");
	ticket2.add_answer("1. H",  true);
	ticket2.add_answer("2. Ne", false);
	ticket2.add_answer("3. Fe", false);
	ticket2.add_answer("4. C",  false);
	
	CXXQuestTicket ticket3;
	ticket3.set_question("In what year founded Moscow?");
	ticket3.add_answer("1. 1123", false);
	ticket3.add_answer("2. 1147", true);
	ticket3.add_answer("3. 1136", false);
	ticket3.add_answer("4. 1154", false);

	CXXQuestTicket ticket4;
	ticket4.set_question("The result is 12*6");
	ticket4.add_answer("1. 70", false);
	ticket4.add_answer("2. 68", false);
	ticket4.add_answer("3. 74", false);
	ticket4.add_answer("4. 72", true);

	CXXQuestTicket ticket5;
	ticket5.set_question("The largest planet in the solar system?");
	ticket5.add_answer("1. Jupiter", true);
	ticket5.add_answer("2. Saturn",  false);
	ticket5.add_answer("3. Mars",    false);
	ticket5.add_answer("4. Neptune", false);

    CXXQuestTicket ticket6;
    ticket6.set_question("The record running speed of a human?");
    ticket6.add_answer("1. 40 km / h", true);
    ticket6.add_answer("2. 30 km / h", false);
    ticket6.add_answer("3. 25 km / h", false);
    ticket6.add_answer("4. 45 km / h", false);

	CXXQuest quest;
	quest.add_ticket(ticket1);
	quest.add_ticket(ticket2);
	quest.add_ticket(ticket3);
	quest.add_ticket(ticket4);
	quest.add_ticket(ticket5);
    quest.add_ticket(ticket6);
	return quest;
}
void CXXQuest::print_hello() {
	std::cout << "Start new Test" << "\n";
}
void CXXQuest::print_farewell() {
	std::cout << "\n" << "Test finished" << "\n";
}
