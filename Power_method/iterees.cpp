#include "iterees.hpp"

// Constructeur de la classe EigenSolver
EigenSolver::EigenSolver(double matrix[n][n], double initial_x[n]) : lambda_old(0), lambda_new(1), eps(1e-6) {

    // Initialisation de la matrice A et du vecteur x avec les valeurs fournies en paramètres
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = matrix[i][j];
        }
        x[i] = initial_x[i];
    }
}

// Fonction pour normaliser un vecteur
double EigenSolver::normalizeVector(double vector[]) {
    double norm = 0;
    for (int i = 0; i < n; i++) {
        norm += vector[i] * vector[i];
    }
    return sqrt(norm);
}

// Fonction pour calculer le produit scalaire de deux vecteurs
double EigenSolver::calculateDotProduct(double vector1[], double vector2[]) {
    double dotProduct = 0;
    for (int i = 0; i < n; i++) {
        dotProduct += vector1[i] * vector2[i];
    }
    return dotProduct;
}

// Fonction pour résoudre la valeur propre dominante
void EigenSolver::solveEigenvalue() {
    // Boucle jusqu'à ce que la différence entre les anciennes et nouvelles valeurs propres soit inférieure à l'epsilon
    cout<<"Here is the matrix in question:"<<endl;
    displayMat();
    while (abs(lambda_new - lambda_old) > eps) {
        lambda_old = lambda_new;

        double y[n];
        // Calcul du produit matrice-vecteur
        for (int i = 0; i < n; i++) {
            y[i] = 0;
            for (int j = 0; j < n; j++) {
                y[i] += A[i][j] * x[j];
            }
        }

        // Normalisation du vecteur y
        for (int i = 0; i < n; i++) {
            x[i] = y[i] / normalizeVector(y);
        }

        // Calcul de la nouvelle valeur propre
        lambda_new = calculateDotProduct(y, x); // Le problème est ici. Calculer le produit scalaire après la normalisation.
    }
    std::cout << "The largest eigenvalue is " << lambda_new<< std::endl;
}


void EigenSolver::displayMat() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}