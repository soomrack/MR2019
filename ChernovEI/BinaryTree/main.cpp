#include <iostream>
#include "tests/Data.h"

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << (new Data())->get() << std::endl;
    }
    return 0;
}