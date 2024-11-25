#include "gestion_des_eleves.hpp"
#include<iostream>
using namespace std;

int main() {
    cout << "\n~~~~~~~~~~GESTION DE LISTE DES ELEVES~~~~~~~~~~\n" << endl;
    LesEtudiants lesEtudiants;
    lesEtudiants.chargerListe("liste.txt");
    Menu menu(lesEtudiants);
    menu.executer();
    return 0;
}