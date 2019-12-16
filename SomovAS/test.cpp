#include "test.h"
#include <iostream>
#include <clocale>
using namespace std;

/*class Question1{
public:
    string name;
    int count;
    string question;
    string ans;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
    void foo(){
        cout << question << endl;
        cout << ans1 << endl << ans2 << endl << ans3 << endl << ans4 << endl;
        cin >> ans;
        while(ans != ans1){
            cout << "Wrong, try again" << endl;
            cin >> ans;
        }
        cout << "Well, lets continue" << endl;
        count++;
    }
    Question1(){
        count = 0;
        question = "What scientist wrote the book <Origin of species>?";
        ans1 = "Charls Darwin";
        ans2 = "Aristotel";
        ans3 = "Thomas Edison";
        ans4 = "Alexandr Greyam Bell";
    }
}Q1;

class Question2: public Question1{
public:
    Question2(){
        question = "This Belgian Catholic priest was the first to propose the big Bang theory";
        ans1 = "Jorj Lemetr";
        ans2 = "Lui Paster";
        ans3 = "Nicola Tesla";
        ans4 = "Charls Babbidj";
    }
}Q2;

class Question3: public Question1{
public:
    Question3(){
        question = "And which Scottish-born American inventor was the first to get a patent for a phone?";
        ans1 = "Alexandr Greyam Bell";
        ans2 = "Samyel Morse";
        ans3 = "Stiv Jobs";
        ans4 = "Alexandr Landau";
    }
}Q3;
class Question4: public Question1{
public:
    Question4(){
        question = "Who discovered electricity after experimenting with a kite during a storm?";
        ans1 = "Benjamin Franklin";
        ans2 = "Nicola Tesla";
        ans3 = "Tomas Edison";
        ans4 = "Albert Einstein";
    }
}Q4;
class Question5: public Question1{
public:
    Question5(){
        question = "Which French virologist discovered HIV in 1983?";
        ans1 = "Luk Montanie";
        ans2 = "Lui Paster";
        ans3 = "Samyel Morse";
        ans4 = "Gotfried Leibniz";
    }
}Q5;
void test(){
    setlocale(LC_ALL,"RUS");
    cout << "Hi тивирп, what's your name?";
    cin >> Q1.name;
    cout << "Welcome, " << Q1.name << endl << " Let's check your science knowledge" << endl;
    Q1.foo();
    Q2.foo();
    Q3.foo();
    Q4.foo();
    Q5.foo();
    cout << "Congratulation, you answer all  " << Q1.count << " question, you know history well" << endl;
    cout << "See you next time, " << Q1.name << ')';
}*/
CXXQuest init_cxx_quest() {
    CXXQuestTicket ticket;
    ticket.set_question("Range of int variable is:");
    ticket.add_answer("[0, 32255]", false);
    ticket.add_answer("[-32768, 32767]", true);

    CXXQuest quest;
    quest.add_ticket(ticket);
    return quest;
}
void CXXQuest::print_hello() {
    cout << endl << "Start new CXXQuest" << endl;
}
void CXXQuest::print_farewell() {
    cout << endl << "Quest CXX finished" << endl;
}