//
// Created by chern_000 on 16.03.2020.
//

#ifndef BINARYTREEV2_DATA_H
#define BINARYTREEV2_DATA_H


class Data {
private:
    int num;

public:
    Data();

    Data(int num);

    /*
     * res < 0 -> this < param
     * res > 0 -> this > param
     * res = 0 -> this = param
     * */
    int compareTo(Data data);

    int hashCode();

    int get();
};


#endif //BINARYTREEV2_DATA_H
