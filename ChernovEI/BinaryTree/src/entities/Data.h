#ifndef BINARYTREEV2_DATA_H
#define BINARYTREEV2_DATA_H

#include <string>

/**
 * Abstract data class.
 *
 * @version 2.0
 * */
class Data {
public:
    /**
     * res < 0  ->  this < param
     * res > 0  ->  this > param
     * res = 0  ->  this = param
     *
     * Subject to overriding.
     * */
    virtual int compare_to(Data data);

    /**
     * Subject to overriding.
     * */
    virtual int hash_code();

    virtual std::string to_string();
};


#endif //BINARYTREEV2_DATA_H
