#include "ldlt_profil_cuthill_mckee.hpp"

// Constructeur : Chargement de la matrice
Profil::Profil(string filename) {
    ifstream file(filename);
    if (file) {
        file >> dim;
        A.resize(dim, vector<double>(dim));
        b.resize(dim);

        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                file >> A[i][j];
            }
        }

        for (int i = 0; i < dim; i++) {
            file >> b[i];
        }

        cout << "Matrice A initiale : " << endl;
        displayMat(A);
        file.close();
    } else {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << filename << endl;
        exit(EXIT_FAILURE);
    }
}

// Réordonnancement de la matrice
void Profil::reorder() {
    ReorderingSSM reorder(A);
    vector<int> order = reorder.ReverseCuthillMckee();
    vector<vector<double>> newA(dim, vector<double>(dim));
    vector<double> newB(dim);

    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            newA[i][j] = A[order[i]][order[j]];
        }
        newB[i] = b[order[i]];
    }

    A = newA;
    b = newB;
}

// Profilage de la matrice
void Profil::profil() {
    pi.resize(dim);
    nDiag.resize(dim);
    ki.resize(dim);

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j <= i; j++) {
            if (A[i][j] != 0) {
                pi[i] = j;
                break;
            }
        }
    }

    nDiag[0] = 0;
    for (int i = 0; i < dim - 1; i++) {
        nDiag[i + 1] = nDiag[i] + ((i + 1) - pi[i + 1]) + 1;
    }

    for (int i = 0; i < dim; i++) {
        ki[i] = (i == 0) ? 0 : nDiag[i - 1] + 1;
    }

    newDim = nDiag[dim - 1] + 1;
    AP.resize(newDim);

    int k = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = pi[i]; j <= i; j++) {
            AP[k++] = A[i][j];
        }
    }
}

// Accès à la matrice profilée
double Profil::mat(const vector<double> &MP, int i, int j) {
    if (i < j) return mat(MP, j, i);
    if (j < pi[i]) return 0;
    if (i == j) return MP[nDiag[i]];
    return MP[ki[i] + j - pi[i]];
}

// Décomposition LDLT
void Profil::decompose() {
    LP.resize(newDim, 0);
    D.resize(dim, 0);

    for (int i = 0; i < dim; i++) {
        LP[nDiag[i]] = 1;
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += mat(LP, i, k) * D[k] * mat(LP, j, k);
            }
            if (i == j)
                D[i] = mat(AP, i, j) - sum;
            else if ((pi[i] <= j) && (j <= i))
                LP[ki[i] + j - pi[i]] = (mat(AP, i, j) - sum) / D[j];
        }
    }
}

// Résolution du système
void Profil::solve() {
    y.resize(dim);
    z.resize(dim);
    x.resize(dim);

    for (int i = 0; i < dim; i++) {
        z[i] = b[i];
        for (int j = 0; j < i; j++) {
            z[i] -= mat(LP, i, j) * z[j];
        }
    }

    for (int i = 0; i < dim; i++) {
        y[i] = z[i] / D[i];
    }

    for (int i = dim - 1; i >= 0; --i) {
        x[i] = y[i];
        for (int j = i + 1; j < dim; ++j) {
            x[i] -= mat(LP, i, j) * x[j];
        }
    }
}

// Affichage des résultats
void Profil::displayMat(const vector<vector<double>> &M) {
    for (const auto &row : M) {
        for (double val : row) {
            cout << setw(10) << fixed << setprecision(2) << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Profil::displayResult() {
    cout << "Solution : " << endl;
    for (int i = 0; i < dim; i++) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(2) << x[i] << endl;
    }
}

// Algorithmes de réordonnancement
vector<int> ReorderingSSM::CuthillMckee() {
    // Simplification pour cette version : algorithme de base à compléter.
    return vector<int>();
}

vector<int> ReorderingSSM::ReverseCuthillMckee() {
    vector<int> order = CuthillMckee();
    reverse(order.begin(), order.end());
    return order;
}
