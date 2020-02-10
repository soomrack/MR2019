//
// Created by nne_l on 26.12.2019.
//
#pragma once

#include <string.h>
#include <vector>
#include <iostream>

#ifndef YAKIMENKO_TEST_MYTESTLIB_H
#define YAKIMENKO_TEST_MYTESTLIB_H

#endif //YAKIMENKO_TEST_MYTESTLIB_H
extern void startTest();
class List {
public:
    std::string question; //Вопрос
    std::string answer; //Правильный ответ
    bool check_answer(std::string num)
    {
        if (answer == num) return true;
        return false;
    }
    List() {
        question = "";
        answer = "";

    }
};
extern std::vector<List> questions;