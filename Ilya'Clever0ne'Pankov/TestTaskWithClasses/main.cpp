#include <iostream>
#include <stdint.h>
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

Question::Question()
{
    string question;
    string answer;
    string right_answer;
}

string Question::getNextQuestion(int32_t number_of_question)
{
    switch (number_of_question)
    {
        case 1:
            return "2 + 2 * 2 = ";
        case 2:
            return "\nint i = 5;\n++i + ++i = ";
        case 3:
            return "\n150 + 150 = ";
        case 4:
            return "\nsizeof(int8_t) = ";
        case 5:
            return "\nSpeed of light (m/s) = ";
        case 6:
            return "\nAnswer to the Ultimate Question of Life, the Universe, and Everything: ";
        case 7:
            return "\nNumber of genders: ";
        case 8:
            return "\nNumber of planets in the Solar System: ";
        case 9:
            return "\nNumber of letters in the Russian alphabet: ";
        case 10:
            return "\nNumber of days in the week: ";
        default:
            break;
    }
}

void Question::getRightAnswer(int32_t number_of_question, string right_answer)
{
    switch (number_of_question)
    {
        case 1:
            right_answer = "6";
        case 2:
            right_answer = "14";
        case 3:
            right_answer = "300";
        case 4:
            right_answer = "1";
        case 5:
            right_answer = "299792458";
        case 6:
            right_answer = "42";
        case 7:
            right_answer = "2";
        case 8:
            right_answer = "8";
        case 9:
            right_answer = "33";
        case 10:
            right_answer = "7";
        default:
            break;
    }
}

void Question::enterQuestion(string &question, basic_string<char> next_question)
{
    question = next_question;
}

void Question::printQuestion(string &question)
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
        enterQuestion(question, getNextQuestion(number_of_question));
        printQuestion(question);
        enterYourAnswer(answer);
        getRightAnswer(number_of_question, right_answer);
        if (checkAnswer(answer, right_answer))
            score++;
        printScore(score);
    }
}

int main()
{
    Question Test = Question();
    Test.startTest();
    while(1);
}