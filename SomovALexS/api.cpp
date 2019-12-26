#include "api.h"
#include <iostream>
#include <set>

void Ticket::set_question(const string question) {
    this->question = question;
}
Ticket::Ticket(const Ticket &ticket) {
    question = ticket.question;
    answers = ticket.answers;
}

void Ticket::add_answer(const string answer, const bool is_correct) {
    Answer struct_answer;
    struct_answer.is_correct = is_correct;
    struct_answer.answer = answer;
    answers.push_back(struct_answer);
}
void Quest::add_ticket(const Ticket ticket) {
    tickets.push_back(ticket);
}
void Quest::run(Person &student) {
    print_hello();
    for(auto &current_ticket:tickets) {
        current_ticket.run(student);
    }
    print_farewell();
}
void Quest::print_hello() {
    cout << endl << "Start new Quest" << endl;
}
void Quest::print_farewell() {
    cout << endl << "Quest finished" << endl;
}
void Ticket::run(Person &student) {
    //Print questions
    int number_of_answer = 0;
    set<int> current_answers;
    for (auto &current_answer:answers) {
        number_of_answer++;
        if (current_answer.is_correct) {
            current_answers.insert(number_of_answer);
        }
        cout << number_of_answer << ")" << current_answer.answer << endl;
    }
    //Print user response
    cout << "Enter number of correct answer." << endl << endl;
    //Get user answer
    string response;
    cin >> response;
    //Check response
    bool result = current_answers.find(stoi(response)) != current_answers.end();
    //Save result
    if (result) {
        student.score++;
    }
}
void Person::print_stat() {
    cout << endl << "Your score is " << score << endl;
}


