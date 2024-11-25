#include "iterees.hpp"

int main() {
    double matrix[5][5] = {{2, -1, 0, 0, 0}, {-1, 2, -1, 0, 0}, {0, -1, 2, -1, 0}, {0, 0, -1, 2, -1}, {0, 0, 0, -1, 2}};
    double initial_x[5] = {1, 1, 1, 1, 1};

    EigenSolver eigenSolver(matrix, initial_x);
    eigenSolver.solveEigenvalue();
    
    return 0;
}
