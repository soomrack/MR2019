#include "source/cpp_quest.h"

int main() {
	Person student;
	CPPQuest cpp_quest = init_cpp_quest();
	cpp_quest.run(student);
	student.print_stat();
	system("pause");
	return 0;
}
