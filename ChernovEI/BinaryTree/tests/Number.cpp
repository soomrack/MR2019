#include <cstdlib>
#include <ctime>

#include "Number.h"

Number::Number() {
    srand(time(nullptr));
    num = rand();
}

Number::Number(int num) {
    this->num = num;
}

int Number::compare_to(Data number) {
    return this->get() - dynamic_cast<Number*>(&number)->get();
}

int Number::hash_code() {
    return num;
}

int Number::get() {
    return num;
}

void Number::set(int aNum) {
    num = aNum;
}

void Number::increment() {
    num++;
}
