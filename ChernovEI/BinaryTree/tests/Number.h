#ifndef BINARYTREEV2_NUMBER_H
#define BINARYTREEV2_NUMBER_H

#include "../src/Data.h"

/**
 * Class for testing of the Tree class.
 * The num field matches a result of method hash_code()
 *
 * @version 1.0
 * */
class Number : public Data {
private:
    int num;

public:
    Number();

    explicit Number(int num);

    void increment();

    /**
     * res < 0  ->  this < param
     * res > 0  ->  this > param
     * res = 0  ->  this = param
     * */
    int compare_to(Data number) override;

    int hash_code() override;

    int get();

    void set(int aNum);
};


#endif //BINARYTREEV2_NUMBER_H
