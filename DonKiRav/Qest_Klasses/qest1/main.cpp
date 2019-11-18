#include <iostream>
#include <string>
#include "QestLib.h"

int main() {
    Question question1;
    question1.question = "Who was the first";
    question1.var1 = "egg";
    question1.var2 = "chicken";
    question1.var3 = "man";
    question1.body();
    question1.right_answer = question1.var1;
    question1.scan_answer();
    question1.verdict();

    Question question2;
    question2.question = "Who was the second";
    question2.var1 = "egg";
    question2.var2 = "chicken";
    question2.var3 = "man";
    question2.body();
    question2.right_answer = question1.var2;
    question2.scan_answer();
    question2.verdict();
    return 0;
}