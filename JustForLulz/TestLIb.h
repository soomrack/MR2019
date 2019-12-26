//
// Created by nne_l on 26.12.2019.
//

#ifndef JUSTFORLULZ_TESTLIB_H
#define JUSTFORLULZ_TESTLIB_H
#include <string>

using namespace std;

class Question
{
private:
    string question;
    string answer;
    string right_answer;
    string getNextQuestion(int32_t);
public:
    Question();
    void enterQuestion(string &, basic_string<char>);
    void printQuestion(string &);
    void getRightAnswer(int32_t, string);
    void enterYourAnswer(string);
    bool checkAnswer(string, string);
    void startTest();
};
#endif //JUSTFORLULZ_TESTLIB_H
