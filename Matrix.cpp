#include "Matrix.h"
#include <iomanip>
#include <algorithm>

Matrix::Matrix(int n) : size(n) {
    data = new int*[size];
    for (int i = 0; i < size; ++i)
        data[i] = new int[size];
}

Matrix::Matrix(const Matrix& other) : size(other.size) {
    data = new int*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new int[size];
        for (int j = 0; j < size; ++j)
            data[i][j] = other.data[i][j];
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < size; ++i)
        delete[] data[i];
    delete[] data;
}

void Matrix::readFromFile(std::istream& in) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            in >> data[i][j];
}

void Matrix::display() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            std::cout << std::setw(4) << data[i][j];
        std::cout << std::endl;
    }
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];
        }
    return result;
}

int Matrix::diagonalSum() const {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += data[i][i];              
        sum += data[i][size - i - 1];   
    }
    return sum;
}

Matrix Matrix::swapRows(int r1, int r2) const {
    Matrix result(*this);
    if (r1 >= 0 && r2 >= 0 && r1 < size && r2 < size)
        std::swap(result.data[r1], result.data[r2]);
    return result;
}

Matrix Matrix::swapCols(int c1, int c2) const {
    Matrix result(*this);
    if (c1 >= 0 && c2 >= 0 && c1 < size && c2 < size)
        for (int i = 0; i < size; ++i)
            std::swap(result.data[i][c1], result.data[i][c2]);
    return result;
}

void Matrix::update(int row, int col, int value) {
    if (row >= 0 && col >= 0 && row < size && col < size)
        data[row][col] = value;
}
