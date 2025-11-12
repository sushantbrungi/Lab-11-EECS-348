#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int size;
    int** data;

public:
    Matrix(int n);
    Matrix(const Matrix& other);
    ~Matrix();

    void readFromFile(std::istream& in);
    void display() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    int diagonalSum() const;
    Matrix swapRows(int r1 = 0, int r2 = 1) const;
    Matrix swapCols(int c1 = 0, int c2 = 1) const;
    void update(int row = 0, int col = 0, int value = 100);
};

#endif
