//
// Created by nne_l on 26.12.2019.
//

#include "TestLIb.h"
#include <iostream>
#include <stdint.h>
#include <string>
using namespace std;

Question::Question()
{
    string question;
    string answer;
    string right_answer;
}

string Question::toNextQuestion(int32_t number_of_question)
{
    switch (number_of_question)
    {
        case 1:
            return "How many genders?";
        case 2:
            return "\nAnswer of all questions?";
        default:
            break;
    }
}

void Question::toRightAnswer(int32_t number_of_question, string right_answer)
{
    switch (number_of_question)
    {
        case 1:
            right_answer = "2";
        case 2:
            right_answer = "42";

        default:
            break;
    }
}

void Question::enterQuestion(string &question, basic_string<char> next_question)
{
    question = next_question;
}

void Question::coutQuestion(string &question)
{
    cout << question;
}

bool Question::checkAnswer(string answer, string right_answer)
{
    if (answer == right_answer) return true;
    else return false;
}

void Question::enterYourAnswer(string answer)
{
    cin >> answer;
}

void printScore(int32_t score)
{
    cout << score << "/10";
}

void Question::startTest()
{
    int32_t number_of_question = 0;
    int32_t score = 0;
    for(number_of_question = 1; number_of_question <= 10; number_of_question++)
    {
        enterQuestion(question, toNextQuestion(number_of_question));
        coutQuestion(question);
        enterYourAnswer(answer);
        toRightAnswer(number_of_question, right_answer);
        if (checkAnswer(answer, right_answer))
            score++;
        printScore(score);
    }
}