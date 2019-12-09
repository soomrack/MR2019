#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int globalM = 0;

class Matrix {
public:
    vector<vector<long long>> matr;
    Matrix(){
        matr.resize(2, vector<long long>(2, 1));
        matr[1][1] = 0;
    }
    Matrix(long long x00, long long x01, long long x10, long long x11) {
        matr.resize(2, vector<long long>(2, 1));
        matr[0][0] = x00;
        matr[0][1] = x01;
        matr[1][0] = x10;
        matr[1][1] = x11;
    }
    const long long getElem(const int y, const int x) const {
        return matr[y][x];
    }
    const Matrix operator*(const Matrix &rMatrix) {
        return Matrix((matr[0][0] * rMatrix.getElem(0, 0) + matr[0][1] * rMatrix.getElem(1, 0)) % globalM, (matr[0][0] * rMatrix.getElem(0, 1) + matr[0][1] * rMatrix.getElem(1, 1)) % globalM, (matr[1][0] * rMatrix.getElem(0, 0) + matr[1][1] * rMatrix.getElem(1, 0)) % globalM, (matr[1][0] * rMatrix.getElem(0, 1) + matr[1][1] * rMatrix.getElem(1, 1)) % globalM);
    }

};

Matrix pow(const Matrix &a, long long n) {
    if (n == 0) {
        return Matrix(1, 0, 0, 1);
    }
    if (n == 1) {
        return a;
    } else if (n % 2 == 0) {
        Matrix tmp = pow(a, n / 2);
        return tmp * tmp;
    } else {
        Matrix tmp = pow(a, n / 2);
        tmp = tmp * tmp;
        return tmp * a;
    }
}

class Fibonacci {
public:
    static int get_remainder(long long n, int m) {
        assert(n >= 1);
        assert(m >= 2);
        Matrix ans = pow(Matrix(), n - 1);
        return ans.getElem(0, 0);
    }
};

int main(void) {
    long long n;
    int m = 100000;
    std::cin >> n >> m;
    globalM = m;
    std::cout << Fibonacci::get_remainder(n, m) <<  std::endl;
    return 0;
}