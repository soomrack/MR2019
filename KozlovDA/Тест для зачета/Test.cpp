#include "api.h"
#include "quest.h"

int main() {
	Person student;
	//DENQuest den_quest = init_den_quest();
	DENQuestTicket1 ticket1;
	ticket1.set_question("22-15?");
	ticket1.add_answer("12", false);
	ticket1.add_answer("7", true);
	ticket1.add_answer("8", false);
	ticket1.add_answer("9", false);

	DENQuestTicket2 ticket2;
	ticket2.set_question("The capital of Belarus?");
	ticket2.add_answer("Kiyv", false);
	ticket2.add_answer("Brest", false);
	ticket2.add_answer("Minsk", true);
	ticket2.add_answer("Praga", false);

	DENQuestTicket2 ticket3;
	ticket3.set_question("In Africa");
	ticket3.add_answer("Iran", false);
	ticket3.add_answer("Egypet", true);
	ticket3.add_answer("Irak", false);
	ticket3.add_answer("Australia", false);

	DENQuest quest;
	quest.add_ticket(&ticket1);
	quest.add_ticket(&ticket2);
	quest.add_ticket(&ticket3);
	quest.run(student);
	student.print_stat();
	system("pause");
	return 0;
}