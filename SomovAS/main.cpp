#include "test.h"
#include "../YakimenkoGK/LibExp_Yakimenko/sumator.h"
using namespace std;
int main(){
 //test();
    Person student;
    CXXQuest cxx_quest = init_cxx_quest();
    cxx_quest.run(student);
    student.print_stat();
    system("pause");
// sum();
}
