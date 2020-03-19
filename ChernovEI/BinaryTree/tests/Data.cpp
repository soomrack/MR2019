#include <cstdlib>
#include <ctime>

#include "Data.h"

Data::Data() {
    srand(time(nullptr));
    num = rand();
}

Data::Data(int num) {
    this->num = num;
}

int Data::compare_to(Data data) {
    return this->get() - data.get();
}

int Data::hash_code() {
    return num;
}

int Data::get() {
    return num;
}
