#include "Interface.h"
#include "Author_Quest.h"

AuthorQuest init_author_quest()
{
	AuthorQuest quest;
	// First
	AuthorQuestTicket ticketOne;
	ticketOne.set_question("Range of int variable is:");
	ticketOne.add_answer("[0, 32255]", false);
	ticketOne.add_answer("[-32768, 32767]", true);
	quest.add_ticket(ticketOne);
	// Second
	AuthorQuestTicket ticketTwo;
	ticketTwo.set_question("How much is 2 + 2?");
	ticketTwo.add_answer("2", false);
	ticketTwo.add_answer("4", true);
	ticketTwo.add_answer("5", false);
	quest.add_ticket(ticketTwo);
	// Third
	AuthorQuestTicket ticketThree;
	ticketThree.set_question("When was the Polytechnic University founded?");
	ticketThree.add_answer("1896", false);
	ticketThree.add_answer("1897", false);
	ticketThree.add_answer("1899", true);
	ticketThree.add_answer("1901", false);
	quest.add_ticket(ticketThree);
	// Fourth
	AuthorQuestTicket ticketFour;
	ticketFour.set_question("Who created Google?");
	ticketFour.add_answer("Bruce Wayne", false);
	ticketFour.add_answer("Sergey Brin", true);
	ticketFour.add_answer("Lawrence Page", true);
	ticketFour.add_answer("Tony Stark", false);
	quest.add_ticket(ticketFour);
	////
	AuthorQuestTicket ticketFive;
	ticketFive.set_connected_questions("When did the first Iphone come out?", "The name of the person who presented it.");
	ticketFive.add_first_answers("09.01.2007", true);
	ticketFive.add_first_answers("14.02.2008", false);
	ticketFive.add_first_answers("11.01.2007", false);
	ticketFive.add_first_answers("01.06.2009", false);
	ticketFive.add_second_answers("William", false);
	ticketFive.add_second_answers("Steven", true);
	ticketFive.add_second_answers("Stefan", false);
	quest.add_special_ticket(ticketFive);
	//
	AuthorQuestTicket ticketSix;
	ticketSix.set_connected_questions("The birthplace of the Arduino.", "The year the platform was born.");
	ticketSix.add_first_answers("Spain", false);
	ticketSix.add_first_answers("England", false);
	ticketSix.add_first_answers("Italy", true);
	ticketSix.add_second_answers("2003", false);
	ticketSix.add_second_answers("2005", true);
	ticketSix.add_second_answers("2007", false);
	quest.add_special_ticket(ticketSix);
	return quest;
}

int main()
{
	Person student;
	AuthorQuest new_author_quest = init_author_quest();
	new_author_quest.run_special_quest(student);
	student.print_stat();
	system("pause");
	return 0;
}