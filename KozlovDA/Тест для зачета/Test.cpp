#include "api.h"
#include "quest.h"

int main() {
	Person student;
	DENQuest den_quest = init_cxx_quest();
	den_quest.run(student);
	student.print_stat();
	system("pause");
	return 0;
}