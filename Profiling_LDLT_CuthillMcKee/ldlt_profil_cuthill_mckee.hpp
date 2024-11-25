#ifndef LDLT_PROFIL_CUTHILL_MCKEE_HPP
#define LDLT_PROFIL_CUTHILL_MCKEE_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class Profil {
public:
    Profil(string filename);
    void reorder();
    void profil();
    double mat(const vector<double> &MP, int i, int j);
    void decompose();
    void solve();

    void displayMat(const vector<vector<double>> &M);
    void displayD();
    void displayResult();
    void displayMP(const vector<double> &I);
    void displayIndex(const vector<int> &I);

    void freeAll();

private:
    vector<vector<double>> A;
    vector<double> AP, LP, D;
    vector<double> b, x, z, y;
    vector<int> pi, nDiag, ki;
    int dim, newDim;
};

class ReorderingSSM {
private:
    vector<vector<double>> _matrix;

public:
    ReorderingSSM(const vector<vector<double>> &m) : _matrix(m) {}

    vector<int> CuthillMckee();
    vector<int> ReverseCuthillMckee();
};

#endif
