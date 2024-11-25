#include<iostream>
#include<fstream>
using namespace std;
#include "gestion_des_eleves.hpp"
#include <limits>

Etudiant::Etudiant(string n, float g, Etudiant* pn) {
    nom = n;
    note = g;
    pnext = pn;
}

string Etudiant::getNom() {
    return nom;
}

float Etudiant::getNote() {
    return note;
}

void Etudiant::setNom(string n) {
    nom = n;
}

void Etudiant::setNote(float g) {
    note = g;
}

Etudiant* Etudiant::getNext() {
    return pnext;
}

void Etudiant::setNext(Etudiant* pn) {
    pnext = pn;
}

LesEtudiants::LesEtudiants() {
    phead = nullptr;
}

LesEtudiants::~LesEtudiants() {
    while (phead != nullptr) {
        Etudiant* p = phead;
        phead = phead->getNext();
        delete p;
    }
}

void LesEtudiants::AjouterEtudiant(string n, float gr) {
    Etudiant* newEtu = new (nothrow) Etudiant(n, gr, nullptr);
    if (!newEtu) {
        return;
    }
    if (!phead) {
        phead = newEtu;
    } else {
        Etudiant* ptemp = phead;
        while (ptemp->getNext() != nullptr) {
            ptemp = ptemp->getNext();
        }
        ptemp->setNext(newEtu);
    }
}

void LesEtudiants::supprimerEtudiant(string n) {
    Etudiant* p = phead;
    Etudiant* pp = nullptr;
    while (p != nullptr && p->getNom() != n) {
        pp = p;
        p = p->getNext();
    }
    if (p != nullptr) {
        if (pp != nullptr) {
            pp->setNext(p->getNext());
        } else {
            phead = p->getNext();
        }
        delete p;
    }
}

void LesEtudiants::afficherListe() {
    Etudiant* p = phead;
    while (p != nullptr) {
        cout << "Nom: " << p->getNom() << ", Note: " << p->getNote() << endl;
        p = p->getNext();
    }
}

void LesEtudiants::chargerListe(string nomFichier) {
    ifstream fichier(nomFichier);
    if (fichier) {
        string nom;
        float note;
        while (fichier >> nom >> note) {
            AjouterEtudiant(nom, note);
        }
        fichier.close();
    }
}

void LesEtudiants::enregistrerListe(string nomFichier) {
    ofstream fichier(nomFichier);
    if (fichier) {
        Etudiant* p = phead;
        while (p != nullptr) {
            fichier << p->getNom() << " " << p->getNote() << endl;
            p = p->getNext();
        }
        fichier.close();
    }
}

Menu::Menu(LesEtudiants& le) : lesEtudiants(le) {}

void Menu::afficher() {
    cout <<"\n";
    cout << "\t1. Afficher la liste des etudiants" << endl;
    cout << "\t2. Inserer un etudiant" << endl;
    cout << "\t3. Supprimer un etudiant" << endl;
    cout << "\t4. Quitter" << endl;
}

void Menu::executer() {
    int choix;
    while (true) {
        afficher();
        cout << "\nEntrez votre choix: ";
        cin >> choix;
        if (choix == 4) {
            quitter();
            cout << "\tMerci d'avoir utilisé ce programme.\n\tÀ bientôt!" << endl;
            break;
        }
        switch (choix) {
            case 1:
                lesEtudiants.afficherListe();
                break;
            case 2:
                ajouterEtudiant();
                break;
            case 3:
                supprimerEtudiant();
                break;
            default:
                cout << "Choix invalide." << endl;
                break;
        }
    }
}

void Menu::ajouterEtudiant() {
    string nom;
    float note;
    cout << "Nom de l'etudiant: ";
    cin >> nom;
    cout << "Note de l'etudiant: ";
    while (!(cin >> note) || note < 0 || note > 20) {
        cout << "Entrez une note valide entre 0 et 20: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    lesEtudiants.AjouterEtudiant(nom, note);
}

void Menu::supprimerEtudiant() {
    string nom;
    cout << "Nom de l'etudiant a supprimer: ";
    cin >> nom;
    lesEtudiants.supprimerEtudiant(nom);
}

void Menu::quitter() {
    lesEtudiants.enregistrerListe("liste.txt");
}


