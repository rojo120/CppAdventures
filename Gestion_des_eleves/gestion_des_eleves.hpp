class Etudiant {
    private:
        string nom;
        float note;
        Etudiant* pnext;
    public:
        Etudiant(string n, float g, Etudiant* pn);
        string getNom();
        float getNote();
        void setNom(string n);
        void setNote(float g);
        Etudiant* getNext();
        void setNext(Etudiant* pn);
};

class LesEtudiants {
    private:
        Etudiant* phead;
    public:
        LesEtudiants();
        ~LesEtudiants();
        void AjouterEtudiant(string n, float gr);
        void supprimerEtudiant(string n);
        void afficherListe();
        void chargerListe(string nomFichier);
        void enregistrerListe(string nomFichier);
};

class Menu {
    private:
        LesEtudiants& lesEtudiants;
    public:
        Menu(LesEtudiants& le);
        void afficher();
        void executer();
        void ajouterEtudiant();
        void supprimerEtudiant();
        void quitter();
};
