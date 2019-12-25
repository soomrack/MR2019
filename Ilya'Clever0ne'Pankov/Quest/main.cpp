#include <iostream>
#include "api.h"
#include "cpp_quest.h"
#include "clever0ne_quest.h"

int main()
{
    Person student;
    Clever0neQuest clever0ne_quest = initClever0neQuest();
    clever0ne_quest.run(student);
    student.printStat();
    system("pause");
}