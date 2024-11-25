#ifndef GRADIENT_HPP
#define GRADIENT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <ctime>

using namespace std;

class GradientDescentSolver {
private:
    vector<vector<float>> A; // Matrice des coefficients
    vector<float> b, x, r;   // Vecteurs : constants, solution, résidus
    int n;                   // Taille de la matrice
    bool solved;             // Indicateur de convergence

public:
    GradientDescentSolver();  // Constructeur par défaut
    GradientDescentSolver(const string& filePath); // Constructeur avec chargement des données
    ~GradientDescentSolver() = default; // Destructeur par défaut

    void load(const string& filePath);  // Charger les données depuis un fichier
    void solve();                       // Résoudre le système
    void showMatrix(int precision = 3) const;  // Afficher la matrice
    void showSolution(int precision = 3);      // Afficher la solution

    // Opérations vectorielles
    static void addVectors(const vector<float>& a, const vector<float>& b, vector<float>& result);
    static void subtractVectors(const vector<float>& a, const vector<float>& b, vector<float>& result);
    static void scaleVector(float scalar, const vector<float>& a, vector<float>& result);
    void matrixVectorProduct(const vector<float>& v, vector<float>& result) const;
    static float vectorDot(const vector<float>& a, const vector<float>& b);
    static float vectorNorm(const vector<float>& a);
};

#endif
