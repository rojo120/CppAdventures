#include "ldlt_profil_cuthill_mckee.hpp"

int main() {
    Profil solver("dim.txt");

    cout << "Réordonnancement..." << endl;
    solver.reorder();

    cout << "Profilage..." << endl;
    solver.profil();

    cout << "Décomposition LDLT..." << endl;
    solver.decompose();

    cout << "Résolution du système..." << endl;
    solver.solve();

    solver.displayResult();
    return 0;
}
