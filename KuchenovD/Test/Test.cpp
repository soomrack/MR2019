#include "Test.h"
#include <iostream>
CXXQuest init_cxx_quest() {
	setlocale(LC_ALL, "RUSSIAN");
	CXXQuestTicket ticket1;
	ticket1.set_question("Какое у Гомера Симпсона полное имя?");
	ticket1.add_answer("Гомер Джобс Симпсон", false);
	ticket1.add_answer("Гомер Джеймс Симпсон", false);
	ticket1.add_answer("Гомер Джей Симпсон", true);
	ticket1.add_answer("Гомер Джереми Симпсон", false);

	CXXQuestTicket ticket2;
	ticket2.set_question("Какая кличка у собаки Симпсонов?");
	ticket2.add_answer("Маленький Санта", false);
	ticket2.add_answer("Маленький помощник Санты", true);
	ticket2.add_answer("Маленький уборщик Санты", false);
	ticket2.add_answer("Снежок", false);

	CXXQuestTicket ticket3;
	ticket3.set_question("В каком году сериал Симпсоны вышел в эфир?");
	ticket3.add_answer("1990", false);
	ticket3.add_answer("1993", false);
	ticket3.add_answer("1986", false);
	ticket3.add_answer("1989", true);

	CXXQuestTicket ticket4;
	ticket4.set_question("Кто является создателем Симпсонов?");
	ticket4.add_answer("Мэтт Гроунинг", true);
	ticket4.add_answer("Ричард Гиббс", false);
	ticket4.add_answer("Энди Грифитс", false);
	ticket4.add_answer("Джастин Ройланд", false);

	CXXQuestTicket ticket5;
	ticket5.set_question("Кто стрелял в мистера Бернса?");
	ticket5.add_answer("Мэгги", true);
	ticket5.add_answer("Апу", false);
	ticket5.add_answer("Гомер", false);
	ticket5.add_answer("Барт", false);

	CXXQuestTicket ticket6;
	ticket6.set_question("Какой секретный ингредиент в коктейле 'Горючий Мо?");
	ticket6.add_answer("Мартини", false);
	ticket6.add_answer("Экстракт Секвойи", false);
	ticket6.add_answer("Перец-чили", false);
	ticket6.add_answer("Сироп от кашля", true);

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
	std::cout << "Simpsons Test!" << "\n";
	return;
}
void CXXQuest::print_farewell() {
	std::cout << "\n" << "Test is finished" << "\n";
	return;
}
