#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Profil{
    public:
        Profil(string filename);        
        void profil();
        float mat(float *MP, int i, int j);
        void decompose();
        void solve();

        void displayMat(float **M);
        void displayD();
        void displayMP(float *I);
        void displayIndex(int *I);
        void displayResult();

        void freeMat(float **M);
        void freeAll();
    private:
        float **A, *AP, *LP, *D;
        float *b, *x, *z, *y;
        int *pi, *nDiag, *ki, dim, newDim;
};