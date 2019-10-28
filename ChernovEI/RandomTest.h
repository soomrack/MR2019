//
// Created by ageent on 21.10.2019.
//

#ifndef MR2019_RANDOMTEST_H
#define MR2019_RANDOMTEST_H

#include <string>

using namespace std;

class User {
private:
    int countTrueAnswer;
private:
    int mistake;

public:
    User();

public:
    int incrementCountTrueAnswer();

public:
    int incrementMistake();

public:
    int getCountTrueAnswer();

public:
    int getMistake();
};

class Question {
private:
    string questionBody;
private:
    string question1;
private:
    string question2;
private:
    string question3;
private:
    string question4;
private:
    int trueAnswer;

public:
    Question(string questionBody, string question1, string question2, string question3, string question4,
             int trueOption);

public:
    string toString();

public:
    void getUserAnswer(int userAnswer, User &student);

private:
    void checkAnswer(int userAnswer, User &student);
};

class RandomTest {
private:
    bool static checkErrorsParam(Question questions[],int questionsCount);

private:
    void static printTestResult(int questionsCount, User &student);

public:
    void static loadTest(Question questions[], int questionsCount, User &student);
};

#endif //MR2019_RANDOMTEST_H
