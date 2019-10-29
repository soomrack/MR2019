#include "test.h"
#include <iostream>
#include <clocale>
using namespace std;
class Question1{
public:
    string name;
    int count;
    string question;
    string ans;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
    void foo();
};
Question1 Question1(string question = "What scientist wrote the book <Origin of species>?", string ans1 = "Charls Darwin", string ans2 = "Aristotel")
Question1 Question1(string ans3 = "Thomas Edison", string ans4 = "Alexandr Greyam Bell")
Question1::foo(){
    cout << Question1.question << endl;
    cout << Question1.ans1 << endl << Question1.ans2 << endl << Question1.ans3 << endl << Question1.ans4 << endl;
    cin >> ans;
    while(ans != Question1.ans1){
        cout << "Wrong, try again" << endl;
        cin >> ans;
    }
    cout << "Well, lets continue" << endl;
    Question1.count++;
}
class Question2:Question1{
public:
    Question1 Question1(string question = "This Belgian Catholic priest was the first to propose the big Bang theory",\
    string ans1 = "Jorj Lemetr", string ans2 = "Lui Paster")
    Question1 Question1(string ans3 = "Nicola Tesla", string ans4 = "Charls Babbidj")
};
class Question3:Question1{
public:
    Question1 Question1(string question = "And which Scottish-born American inventor was the first to get a patent for a phone?",\
    string ans1 = "Alexandr Greyam Bell", string ans2 = "Samyel Morse")
    Question1 Question1(string ans3 = "Stiv Jobs", string ans4 = "Alexandr Landau")
};
class Question4:Question1{
public:
    Question1 Question1(string question = "Who discovered electricity after experimenting with a kite during a storm?", \
    string ans1 = "Benjamin Franklin", string ans2 = "Nicola Tesla")
    Question1 Question1(string ans3 = "Tomas Edison", string ans4 = "Albert Einstein")
};
class Question5:Question1{
public:
    Question1 Question1(string question = "Which French virologist discovered HIV in 1983?", string ans1 = "Luk Montanie", \
    string ans2 = "Lui Paster")
    Question1 Question1(string ans3 = "Samyel Morse", string ans4 = "Gotfried Leibniz")
};
void test(){
    cout << "Hi, what's your name?";
    cin >> Question1.name;
    cout << "Welcome, " << name << endl << " Let's check your science knowledge" << endl;
    Question1.foo();
    Question2.foo();
    Question3.foo();
    Question4.foo();
    Question5.foo();
    cout << "Congratulation, you answer all  " << Question1.count << " question, you know history well" << endl;
    cout << "See you next time, " << name << ')';
}