#include "Matrix.h"
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error: Could not open input.txt\n";
        return 1;
    }

    int n;
    file >> n;

    Matrix A(n), B(n);
    A.readFromFile(file);
    B.readFromFile(file);

    std::cout << "Matrix A:\n";
    A.display();

    std::cout << "\nMatrix B:\n";
    B.display();

    std::cout << "\nA + B:\n";
    Matrix sum = A + B;
    sum.display();

    std::cout << "\nA * B:\n";
    Matrix product = A * B;
    product.display();

    std::cout << "\nDiagonal sum of A: " << A.diagonalSum() << "\n";

    std::cout << "\nA with rows 0 and 1 swapped:\n";
    A.swapRows().display();

    std::cout << "\nA with columns 0 and 1 swapped:\n";
    A.swapCols().display();

    A.update(); 
    std::cout << "\nA after updating [0][0] to 100:\n";
    A.display();

    return 0;
}
