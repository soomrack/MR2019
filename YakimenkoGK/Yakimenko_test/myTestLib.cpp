//
// Created by nne_l on 26.12.2019.
//

#include "myTestLib.h"
const unsigned int questions_quantity = 2;
std::vector<List> questions(questions_quantity);


void addQuestion()
{

    questions.at(0).question = "Answer to all questions? \n";
    questions.at(0).answer = "42";
    questions.at(1).question = "How many kilometers from St. Petersburg to Moscow? \n";
    questions.at(1).answer = "1000";
}
void startTest()
{
    addQuestion();

    int points = 0;
    for (unsigned int i = 0; i < questions_quantity; ++i) {
        std::cout << questions[i].question;

        std::string writing_ans;
        std::cin >> writing_ans;

        if (questions[i].check_answer(writing_ans)) {
            points++;
            std::cout << "Good answer! +1 point" << std::endl;
        }
        else
            std::cout << "Bad answer :c Points: " << points << std::endl;
    }

    if (points >= questions_quantity - 1)
        std::cout << "\nSo easy for you! Your result: " << points << std::endl;
    else
        std::cout << "\nLucky another time. Your result:  " << points << std::endl;

}