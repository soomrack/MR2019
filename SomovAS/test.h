//
// Created by Fuxtrel on 28.10.2019.
//
#ifndef SOMOVAS_TEST_H
#define SOMOVAS_TEST_H

#include "api.h"

void test();

class CXXQuestTicket : public Ticket {
};

class CXXQuest : public Quest {
private:
    virtual void print_hello();
    virtual void print_farewell();
};

CXXQuest init_cxx_quest();
#endif //SOMOVAS_TEST_H
