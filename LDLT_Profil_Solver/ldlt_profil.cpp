#include "ldlt_profil.hpp"

//Chargement
Profil::Profil(string filename){
    ifstream file(filename);
    if (file){
        file >> dim;
        cout << "Etant donnee la matrice A:"<< endl;
        A = new float *[dim];
        for (int a = 0; a < dim; a++){
            A[a] = new float[dim + 1];
        }
        for (int i = 0; i < dim; i++){
            for (int j = 0; j < dim; j++){
                file >> A[i][j];
            }
        }

        b = new float[dim];
        for (int i = 0; i < dim; i++){   
            file >> b[i];
        }
        displayMat(A);
        file.close();
    }
}
//Traitement
void Profil::profil(){
    pi = new int[dim];
    nDiag = new int [dim];
    ki = new int[dim];
    //pi: indice des colonnes des premiers non nul
    for (int i = 0; i < dim; i++){
        for (int j = 0; j <= i; j++){
            if (A[i][j] != 0){
                pi[i] = j;
                break;
            }
        }
    }
    //nDiag: indices sur le diagonale
    nDiag[0] = 0;
    for (int i = 0; i < dim - 1; i++){
        nDiag[i + 1] = nDiag[i] + ((i+1) - pi[i+1]) + 1;
    }
    //ki: numero des premier non nul de la ligne i
    for (int i = 0; i < dim; i++){
        if (i == 0) ki[i] = 0;
        else ki[i] = nDiag[i - 1] + 1;
    }

    //Valeur des la matrice A en stockage profil de dimension 1(AP)
    cout<<"la matrice A en stockage profil de dimension 1(AP)"<<endl;
    newDim = nDiag[dim - 1] + 1;
    AP = new float [newDim];
    int k = 0;
    for (int i = 0; i < dim; i++){
        for (int j = pi[i]; j <= i; j++){
            AP[k] = A[i][j];
            cout <<"M_"<<k<<": "<<AP[k]<<"  ";
            if (i != j)
                k ++;
        }
        cout<< endl;
        k ++;
    }
    cout<< endl;
    freeMat(A);
}
float Profil::mat(float *MP, int i, int j) {
    if(i < j) return mat(MP, j , i);
    if(j < pi[i]) return 0 ;
    if(i == j) return MP[nDiag[i]];
    return MP[ki[i] + j - pi[i]] ; 
}

//Resolution
void Profil::decompose(){
    cout<<"Decomposition de AP en L*D*L.T:"<<endl;

    LP = new float[newDim];
    D = new float[dim];
    for(int i = 0; i < newDim; i++){
        if (i < dim) D[i] = 0;
        LP[i] = 0;
    }
    
    for(int i = 0; i < dim; i++){
        LP[nDiag[i]] = 1;
        for(int j = 0; j <= i; j++){
            float sum = 0;
            for(int k = 0; k < j; k++){
                sum += mat(LP, i, k) * D[k] * mat(LP, j, k);
            }
            if(i == j) D[i] = mat(AP, i, j) - sum;
            else{
                if ((pi[i] <= j)&&(j <= i)) LP[ki[i] + j - pi[i]] = (1/D[j]) * (mat(AP, i, j) - sum);
            }
        }
    }
    cout << "Matrice L:" << endl;
    displayMP(LP);
    cout << "Matrice D:" << endl;
    displayD();
    delete[] AP;
}
void Profil::solve(){
    cout <<"Resolution..."<<endl;
    y = new float[dim];
    z = new float[dim];
    x = new float[dim];

    // Résolution de L * z = b et de D * y = z
    for (int i = 0; i < dim; i++) {
        z[i] = b[i];
        for (int j = 0; j < i; j++) {
            z[i] -= mat(LP, i, j) * z[j];
        }
        z[i] /= mat(LP, i, i);
        y[i] = z[i] / D[i];
    }
    
    // Résolution de L^T * x = y
    for (int i = dim - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < dim; ++j) {
             x[i] -= mat(LP, i, j) * x[j];
        }
        x[i] /= mat(LP, i, i);
    }
}

//Affichage
void Profil::displayMat(float **M){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            cout <<fixed<<setprecision(2)<<M[i][j] <<"  ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void Profil::displayIndex(int *I){
    for (int i = 0; i < dim; i++){
        cout <<I[i]<<"  ";
    }
    cout <<endl;
}
void Profil::displayMP(float *I){
    int j = 0;
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            if ((pi[i] <= j)&&(j <= i))
                cout <<fixed<<setprecision(2)<<I[i]<<"  ";
            else 
                cout <<fixed<<setprecision(2)<<0.00<<"  ";
        }
        cout << "\n";
    }
    cout <<endl;
}

void Profil::displayD(){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            if (i == j)
                cout <<fixed<<setprecision(2)<<D[i]<<"  ";
            else 
                cout <<fixed<<setprecision(2)<<0<<"  ";
        }
        cout << "\n";
    }
    cout << "\n"; 
}
void Profil::displayResult()
{
    cout << "Solution:" << endl;
    for (int i = 0; i<dim; i++){
        cout<<"x["<<i + 1<<"] = "<<fixed<<setprecision(2)<<x[i]<<endl;
    }
}
void Profil::freeMat(float **M){
    for(int i = 0; i < dim; i++){
        delete[] M[i];
    }
    delete[] M;
}
void Profil::freeAll(){
    delete[] b;
    delete[] LP;
    delete[] D;
    delete[] x;
    delete[] y;
    delete[] z;
    delete[] nDiag;
    delete[] pi;
    delete[] ki;
}
