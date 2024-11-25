#include "ldlt_profil.hpp"

int main(){

    cout<<"************RESOLUTION D'UN GRAND SYSTEME MATRICIELLE************"<< endl;
    //Donnees
    Profil profil("matrix.txt");
    //Traitement
    profil.profil();
    profil.decompose();
    profil.solve();
    //Sortie
    profil.displayResult();
    profil.freeAll();
    
    return (0);
}