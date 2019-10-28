#include "test.h"
#include <iostream>
#include <clocale>
using namespace std;

void test(){
    string name, ans;
    int count;

    cout << "Hi, what's your name?";
    cin >> name;
    cout << "Welcome, " << name << endl << " Let's check your science knowledge" << endl;
    cout << "What scientist wrote the book <Origin of species>?" << endl;
    cout << "Charls Darwin" << endl << "Aristotel" << endl << "Thomas Edison" << endl << "Alexandr Greyam Bell" << endl;
    cin >> ans;
    while(ans != "Charls Darwin"){
        cout << "Wrong, try again" << endl;
        cin >> ans;
    }
    cout << "Well, lets continue" << endl;
    count++;
    cout << "This Belgian Catholic priest was the first to propose the big Bang theory" << endl;
    cout << "Lui Paster" << endl << "Nicola Tesla" << endl << "Charls Babbidj" << endl << "Jorj Lemetr" << endl;
    cin >> ans;
    while(ans != "Jorj Lemetr"){
        cout << "Wrong, try again" << endl;
        cin >> ans;
    }
    cout << "Well, lets continue" << endl;
    count++;
    cout << "And which Scottish-born American inventor was the first to get a patent for a phone?" << endl;
    cout << "Samyel Morse" << endl << "Alexandr Greyam Bell" << endl << "Stiv Jobs" << endl << "Alexandr Landau" << endl;
    cin >> ans;
    while(ans != "Alexandr Greyam Bell"){
        cout << "Wrong, try again" << endl;
        cin >> ans;
    }
    cout << "Well, lets continue" << endl;
    count++;
    cout << "Who discovered electricity after experimenting with a kite during a storm?" << endl;
    cout << "Nicola Tesla" << endl << "Tomas Edison" << endl << "Albert Einstein" << endl << "Benjamin Franklin" << endl;
    cin >> ans;
    while(ans != "Benjamin Franklin"){
        cout << "Wrong, try again" << endl;
        cin >> ans;
    }
    cout << "Well, lets continue" << endl;
    count++;
    cout << "Which French virologist discovered HIV in 1983?" << endl;
    cout << "Luk Montanie" << endl << "Lui Paster" << endl << "Samyel Morse" << endl << "Gotfried Leibniz" << endl;
    cin >> ans;
    while(ans != "Luk Montanie"){
        cout << "Wrong, try again" << endl;
        cin >> ans;
    }
    cout << "Well, lets continue" << endl;
    count++;
    cout << "Congratulation, you answer all  " << count << " question, you know history well" << endl;
    cout << "See you next time, " << name << ')';
}