#include "Gradient.hpp"

int main() {
    try {
        cout << "Gradient Descent Solver" << endl;

        GradientDescentSolver solver("dim.txt");
        solver.showMatrix();
        solver.solve();
        solver.showSolution();
    } catch (const exception& e) {
        cerr << "Erreur: " << e.what() << endl;
    }

    return 0;
}
