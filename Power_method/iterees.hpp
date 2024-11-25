
#ifndef ITEREES_HPP
#define ITEREES_HPP
#include <cmath>
#include <iostream>
using namespace std;

class EigenSolver {
private:
    static const int n = 5; 
    double A[n][n];
    double x[n];
    double lambda_old;
    double lambda_new;
    double eps;

public:
    EigenSolver(double matrix[n][n], double initial_x[n]); 
    double normalizeVector(double vector[]);
    double calculateDotProduct(double vector1[], double vector2[]);
    void solveEigenvalue();
    void displayMat();
};

#endif
