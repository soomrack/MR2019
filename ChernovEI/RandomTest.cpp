//
// Created by ageent on 21.10.2019.
//

#include "RandomTest.h"

#include <cstdio>
#include <string>
#include <utility>

using namespace std;

User::User() {
    countTrueAnswer = 0;
    mistake = 0;
}

int User::incrementCountTrueAnswer() {
    return countTrueAnswer++;
}

int User::incrementMistake() {
    return mistake++;
}

int User::getCountTrueAnswer() {
    return countTrueAnswer;
}

int User::getMistake() {
    return mistake;
}


Question::Question(string questionBody, string question1, string question2, string question3, string question4,
                   int trueOption) :
        questionBody(std::move(questionBody)),
        question1(std::move(question1)),
        question2(std::move(question2)),
        question3(std::move(question3)),
        question4(std::move(question4)),
        trueAnswer(trueOption) {}

string Question::toString() {
    questionBody = (questionBody.back() != '?') ? questionBody + "?" : questionBody;
    return questionBody
           + "\n 1. " + question1
           + "\n 2. " + question2
           + "\n 3. " + question3
           + "\n 4. " + question4;
}

void Question::getUserAnswer(int userAnswer, User &student) {
    bool flagLoopReset = false;

    do {
        printf("Your choice: ");

        scanf("%d", &userAnswer);

        if (userAnswer > 4 || userAnswer < 1) {
            flagLoopReset = true;
            printf("The available answer choices: 1, 2, 3, 4!\n");
        } else { // userAnswer == 1 || 2 || 3 || 4
            this->checkAnswer(userAnswer, student);
        }
    } while (flagLoopReset);
}

void Question::checkAnswer(int userAnswer, User &student) {
    if (userAnswer != trueAnswer) {
        student.incrementMistake();
        printf("Count of mistakes is %d\n\n", student.getMistake());
    } else { // userAnswer == trueAnswer
        student.incrementCountTrueAnswer();
        printf("Correctly\n\n");
    }
}

/**
 * Searches for null array elements
 * @return Message about error
 * */
bool RandomTest::checkErrorsParam(Question *questions, int questionsCount) {
// TODO
}

void RandomTest::printTestResult(int questionsCount, User &student) {
    string YOUR_MARK = "Your mark: ";
    int trueAnswersPercent = (student.getCountTrueAnswer() == 0)
                             ? (int) (((double) student.getCountTrueAnswer() / questionsCount) * 100)
                             : 0;

    if (trueAnswersPercent > 90) {
        printf("%s%d\n", YOUR_MARK.c_str(), 5);
    } else if (trueAnswersPercent > 80) {
        printf("%s%d\n", YOUR_MARK.c_str(), 4);
    } else if (trueAnswersPercent > 60) {
        printf("%s%d\n", YOUR_MARK.c_str(), 3);
    } else {    //0 < trueAnswerPercent =< 60
        printf("%s%d\n", YOUR_MARK.c_str(), 2);
    }
    printf("Count true answers: %d\n", student.getCountTrueAnswer());
    printf("Count mistake: %d\n", student.getMistake());
}

void RandomTest::loadTest(Question questions[], int questionsCount, User &student) {
    checkErrorsParam(questions, questionsCount);                                        // Сhecks for parameter
    // input errors
    printf("TEST\n\n");

    for (size_t testCounter = 0; testCounter < questionsCount; testCounter++) {
        int userAnswer = -1;

        printf("Question:\n%s\n", questions[testCounter].toString().c_str());     // Prints questions
        questions[testCounter].getUserAnswer(userAnswer, student);                       // Gets and checks answer
    }

    printTestResult(questionsCount, student);
}


int main() {
    Question question1 = *new Question("When was the first world war?",
                                       "1913 - 1918",
                                       "1914 - 1919",
                                       "1914 - 1918",
                                       "1912 - 1916",
                                       3);
    Question question2 = *new Question("The most popular element in the world",
                                       "H",
                                       "Ne",
                                       "Fe",
                                       "C",
                                       2);
    Question question3 = *new Question("End",
                                       "Yes",
                                       "No",
                                       "No",
                                       "No",
                                       1);
    Question questions[] = {question1, question2, question2, question2, question3};
    User student = *new User();

    RandomTest::loadTest(questions, 5, student);
}
