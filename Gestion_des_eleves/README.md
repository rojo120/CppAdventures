# Gestion des Élèves

Ce projet est une application console permettant de gérer une liste d'étudiants. Les fonctionnalités incluent l'ajout, la suppression, l'affichage et la persistance des données dans un fichier.

## Structure du Projet

### 1. **Fichiers**
- `main.cpp` : Contient la fonction principale et la gestion du menu.
- `gestion_des_eleves.hpp` : Fichier d'en-tête contenant les définitions des classes `Etudiant`, `LesEtudiants` et `Menu`.
- `gestion_des_eleves.cpp` : Implémentation des classes définies dans le fichier d'en-tête.
- `liste.txt` : Fichier de données contenant la liste des étudiants sauvegardée.

### 2. **Classes**
#### `Etudiant`
- Représente un étudiant avec les attributs :
  - `nom` : Le nom de l'étudiant.
  - `note` : La note de l'étudiant.
  - `pnext` : Pointeur vers le prochain étudiant dans la liste.

#### `LesEtudiants`
- Gère une liste chaînée d'étudiants avec les méthodes :
  - `AjouterEtudiant` : Ajoute un étudiant à la liste.
  - `supprimerEtudiant` : Supprime un étudiant par son nom.
  - `afficherListe` : Affiche tous les étudiants.
  - `chargerListe` : Charge la liste des étudiants depuis un fichier.
  - `enregistrerListe` : Enregistre la liste des étudiants dans un fichier.

#### `Menu`
- Fournit une interface utilisateur pour interagir avec la liste d'étudiants :
  - Afficher la liste.
  - Ajouter un étudiant.
  - Supprimer un étudiant.
  - Quitter et sauvegarder.

---

## Instructions

### Compilation
Utilisez un compilateur C++ pour compiler les fichiers :
```bash
g++ main.cpp gestion_des_eleves.cpp -o gestion_eleves
