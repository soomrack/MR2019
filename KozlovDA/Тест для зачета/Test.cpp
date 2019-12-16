#include "api.h"
#include "quest.h"

int main() {
	Person student;
	CXXQuest cxx_quest = init_cxx_quest();
	cxx_quest.run(student);
	student.print_stat();
	system("pause");
	return 0;
}