#include <iostream>
#include "RandomTest.h"

// Comment 4

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

