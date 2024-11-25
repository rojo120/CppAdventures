#include "Gradient.hpp"

// Constructeurs
GradientDescentSolver::GradientDescentSolver() : n(0), solved(false) {}

GradientDescentSolver::GradientDescentSolver(const string& filePath) : n(0), solved(false) {
    load(filePath);
}

// Chargement des données
void GradientDescentSolver::load(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        throw runtime_error("Erreur : Impossible d'ouvrir le fichier.");
    }

    file >> n;
    if (n <= 0) {
        throw invalid_argument("Erreur : La taille de la matrice doit être positive.");
    }

    A.resize(n, vector<float>(n));
    b.resize(n);
    x.resize(n, 0); // Initialisation à 0
    r.resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(file >> A[i][j])) {
                throw runtime_error("Erreur : Fichier mal formé ou données insuffisantes.");
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!(file >> b[i])) {
            throw runtime_error("Erreur : Fichier mal formé ou données insuffisantes.");
        }
    }
}

// Afficher la matrice augmentée
void GradientDescentSolver::showMatrix(int precision) const {
    cout << "Matrice augmentée (A|b):" << endl;
    cout << fixed << setprecision(precision);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << A[i][j];
        }
        cout << " | " << setw(8) << b[i] << endl;
    }
}

// Résoudre le système
void GradientDescentSolver::solve() {
    if (solved) return;

    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        x[i] = static_cast<float>(rand() % 10);
    }

    const float epsilon = 1e-6;
    vector<float> tempVector(n);
    matrixVectorProduct(x, tempVector);
    subtractVectors(b, tempVector, r);

    int maxIterations = 1000;
    for (int iteration = 0; iteration < maxIterations; ++iteration) {
        if (vectorNorm(r) <= epsilon) break;

        cout << "Iteration " << iteration << ": Résidu = " << vectorNorm(r) << endl;

        matrixVectorProduct(r, tempVector);
        float step = vectorDot(r, r) / vectorDot(tempVector, r);

        scaleVector(step, r, tempVector);
        subtractVectors(x, tempVector, x);
        matrixVectorProduct(x, tempVector);
        subtractVectors(b, tempVector, r);
    }

    solved = true;
}

// Afficher la solution
void GradientDescentSolver::showSolution(int precision) {
    if (!solved) solve();

    cout << "Solution du système:" << endl;
    cout << fixed << setprecision(precision);
    for (int i = 0; i < n; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

// Opérations vectorielles
void GradientDescentSolver::addVectors(const vector<float>& a, const vector<float>& b, vector<float>& result) {
    for (int i = 0; i < a.size(); ++i) {
        result[i] = a[i] + b[i];
    }
}

void GradientDescentSolver::subtractVectors(const vector<float>& a, const vector<float>& b, vector<float>& result) {
    for (int i = 0; i < a.size(); ++i) {
        result[i] = a[i] - b[i];
    }
}

void GradientDescentSolver::scaleVector(float scalar, const vector<float>& a, vector<float>& result) {
    for (int i = 0; i < a.size(); ++i) {
        result[i] = scalar * a[i];
    }
}

void GradientDescentSolver::matrixVectorProduct(const vector<float>& v, vector<float>& result) const {
    for (int i = 0; i < n; ++i) {
        result[i] = 0;
        for (int j = 0; j < n; ++j) {
            result[i] += A[i][j] * v[j];
        }
    }
}

float GradientDescentSolver::vectorDot(const vector<float>& a, const vector<float>& b) {
    float result = 0;
    for (int i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

float GradientDescentSolver::vectorNorm(const vector<float>& a) {
    return sqrt(vectorDot(a, a));
}
