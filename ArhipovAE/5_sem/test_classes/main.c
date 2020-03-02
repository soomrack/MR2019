#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Test {
public:
    int32_t human_answer;
    int32_t correct_answer;
    int32_t score = 0;
    vector <string> question;
    vector <string> answer_1;
    vector <string> answer_2;
    vector <string> answer_3;
    vector <string> answer_4;
    void function( ){
        int32_t reset;
        do {
            reset = 0;
            for(uint32_t i = 0; i < question.size(); i++)
                cout << question[i] << " ";
            cout << endl;
            for(uint32_t i = 0; i < answer_1.size(); i++)
                cout << answer_1[i] << " ";
            cout << endl;
            for(uint32_t i = 0; i < answer_2.size(); i++)
                cout << answer_2[i] << " ";
            cout << endl;
            for(uint32_t i = 0; i < answer_3.size(); i++)
                cout << answer_3[i] << " ";
            cout << endl;
            for(uint32_t i = 0; i < answer_4.size(); i++)
                cout << answer_4[i] << " ";
            cout << endl;
            printf("Your choice: ");
            cin >> human_answer;
            if(human_answer == correct_answer) {
                printf("Correctly");
                cout << endl;
                score++;
            }if((human_answer > 4) || (human_answer < 0)) {
                printf("Error");
                cout << endl;
                reset = 1;
                continue;
            }else
                printf("Mistake");
        }while (reset == 1);
    }
};

int main() {
    Test question_1;
    question_1.question.emplace_back("When was the first world war?");
    question_1.answer_1.emplace_back("1. 1913 - 1918");
    question_1.answer_2.emplace_back("2. 1914 - 1919");
    question_1.answer_3.emplace_back("3. 1914 - 1918");
    question_1.answer_4.emplace_back("4. 1912 - 1916");
    question_1.correct_answer = 3;
    question_1.function();

    Test question_2;
    question_2.question.emplace_back("The most popular element in the world?");
    question_2.answer_1.emplace_back("1. H");
    question_2.answer_2.emplace_back("2. Ne");
    question_2.answer_3.emplace_back("3. Fe");
    question_2.answer_4.emplace_back("4. C");
    question_2.correct_answer = 1;
    question_2.function();

    Test question_3;
    question_3.question.emplace_back("In what year founded Moscow?");
    question_3.answer_1.emplace_back("1. 1123");
    question_3.answer_2.emplace_back("2. 1147");
    question_3.answer_3.emplace_back("3. 1136");
    question_3.answer_4.emplace_back("4. 1154");
    question_3.correct_answer = 2;
    question_3.function();

    Test question_4;
    question_4.question.emplace_back("The result is 12*6");
    question_4.answer_1.emplace_back("1. 70");
    question_4.answer_2.emplace_back("2. 68");
    question_4.answer_3.emplace_back("3. 74");
    question_4.answer_4.emplace_back("4. 72");
    question_4.correct_answer = 4;
    question_4.function();

    Test question_5;
    question_5.question.emplace_back("The largest planet in the solar system??");
    question_5.answer_1.emplace_back("1. Jupiter");
    question_5.answer_2.emplace_back("2. Saturn");
    question_5.answer_3.emplace_back("3. Mars");
    question_5.answer_4.emplace_back("4. Neptune");
    question_5.correct_answer = 1;
    question_5.function();

    Test question_6;
    question_6.question.emplace_back("The record running speed of a human?");
    question_6.answer_1.emplace_back("1. 40 km / h");
    question_6.answer_2.emplace_back("2. 30 km / h");
    question_6.answer_3.emplace_back("3. 25 km / h");
    question_6.answer_4.emplace_back("4. 45 km / h");
    question_6.correct_answer = 1;
    question_6.function();

    cout << "Correct answer: " << question_1.score + question_2.score + question_3.score + question_4.score + question_5.score + question_6.score << endl;


}
