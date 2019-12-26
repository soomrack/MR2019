#ifndef SOMOVAS_API_H
#define SOMOVAS_API_H
//
#include <string>
#include <list>
#include <vector>
using namespace std;

class Person {
public:
    Person() {
        score = 0;
    };
    void print_stat();
    int score;
};

class Answer {
public:
    bool is_correct;
    string answer;
};

class Ticket {
public:
    Ticket() {
        question = "None";
    };
    Ticket(const Ticket &ticket);
    void set_question(const string question);
    void add_answer(const string answer, const bool is_correct);
    void run(Person &student);
private:
    string question;
    list<Answer> answers;
};

class Quest {
public:
    void run(Person &student);
    void add_ticket(const Ticket ticket);//construct of copies
private:
    std::vector<Ticket> tickets;
    virtual void print_hello();
    virtual void print_farewell();
};

#endif //SOMOVAS_API_H
