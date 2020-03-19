#ifndef BINARYTREEV2_DATA_H
#define BINARYTREEV2_DATA_H

/**
 * Class for testing of the Tree class.
 * The num field matches a result of method hash_code()
 *
 * @version 1.0
 * */
class Data {
private:
    int num;

public:
    Data();

    Data(int num);

    /**
     * res < 0  ->  this < param
     * res > 0  ->  this > param
     * res = 0  ->  this = param
     * */
    int compare_to(Data data);

    int hash_code();

    int get();
};


#endif //BINARYTREEV2_DATA_H
