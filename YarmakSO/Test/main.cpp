#include "api.h"
#include "Quest.h"

int main() {
	system("chcp 1251 > null");
	Person student;
	CXXQuest cxx_quest = init_cxx_quest();
	cxx_quest.run(student);
	student.print_stat();
	system("pause");
	return 0;
}