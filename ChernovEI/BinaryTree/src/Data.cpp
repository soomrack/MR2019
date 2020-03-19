//
// Created by chern_000 on 16.03.2020.
//
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

int Data::compareTo(Data data) {
    return this->get() - data.get();
}

int Data::hashCode() {
    return num % INT_MAX;
}

int Data::get() {
    return num;
}
