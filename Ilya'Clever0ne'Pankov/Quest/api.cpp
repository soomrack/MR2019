#include <iostream>
#include "api.h"
#include <vector>
#include <set>

void Ticket::setQuestion(const std::string question)
{
    this->question = question;
    return;
}

Ticket::Ticket(const Ticket &ticket)
{
    question = ticket.question;
    answers = ticket.answers;
}

void Ticket::addAnswer(const std::string answer, const bool is_correct)
{
    Answer struct_answer;
    struct_answer.is_correct = is_correct;
    struct_answer.answer = answer;
    this->answers.push_back(struct_answer);
    return;
}

int Ticket::run(Person &student)
{
    int number_of_answer = 0;
    std::set<int> current_answers;
    std::cout << question << std::endl;
    for(std::list<Answer>::iterator current_answer = answers.begin(); current_answer != answers.end(); current_answer++)
    {
        number_of_answer++;
        if(current_answer->is_correct)
        {
            current_answers.insert(number_of_answer);
        }
        std::cout << number_of_answer << ") " << current_answer->answer << std::endl;
    }
    std::cout << "Enter number of correct answer" << std::endl << std::endl;
    std::string response;
    std::cin >> response;
    bool result = current_answers.find(std::stoi(response)) != current_answers.end();
    if(result)
    {
        student.score++;
    }
    return 0;
}

void Quest::addTicket(const Ticket ticket)
{
    this->tickets.push_back(ticket);
    return;
}

int Quest::run(Person &student)
{
    printHello();
    for(std::vector<Ticket>::iterator current_ticket = tickets.begin(); current_ticket != tickets.end(); current_ticket++)
    {
        current_ticket->run(student);
    }
    printFarewell();
    return 0;
}

void Quest::printHello()
{
    std::cout << std::endl << "Start new Quest" << std::endl;
    return;
}

void Quest::printFarewell()
{
    std::cout << std::endl << "Quest finished" << std::endl;
    return;
}

void Person::printStat()
{
    std::cout << std::endl << "Your score is " << score << "/10" << std::endl;
}