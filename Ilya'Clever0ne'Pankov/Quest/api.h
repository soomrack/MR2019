#ifndef API_H
#define API_H

#include <string>
#include <list>
#include <vector>

class Person
{
    public:
        int score;
    public:
        Person()
        {
            score = 0;
        };
        ~Person(){};
    public:
        void printStat();
};

struct Answer
{
    bool is_correct;
    std::string answer;
};

class Ticket
{
    private:
        std::string question;
        std::list<Answer> answers;
    public:
        Ticket(){};
        Ticket(const Ticket &ticket);
        ~Ticket(){};
    public:
        void setQuestion(const std::string question);
        void addAnswer(const std::string answer, const bool is_correct);
        int run(Person &student);
};

class Quest
{
    private:
        std::vector<Ticket> tickets;
    public:
        Quest(){};
        ~Quest(){};
    private:
        virtual void printHello();
        virtual void printFarewell();
    public:
        int run(Person &student);
        void addTicket(const Ticket ticket);
};

#endif