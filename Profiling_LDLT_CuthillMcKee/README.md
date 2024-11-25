# **LDLT Profil Solver with Cuthill-McKee Reordering**

## **Description**
Ce projet implémente une méthode de décomposition **LDLT** avec stockage en profil, combinée avec un réordonnancement basé sur l'algorithme **Reverse Cuthill-McKee**. Cette approche est conçue pour résoudre des systèmes d'équations linéaires de la forme **Ax = b**, en optimisant la structure de la matrice pour réduire les calculs inutiles.

## **Caractéristiques**
- Chargement d'un système linéaire depuis un fichier.
- Réordonnancement de la matrice avec l'algorithme **Reverse Cuthill-McKee**.
- Stockage de la matrice en **profil** pour une meilleure gestion mémoire.
- Décomposition **LDLT** pour résoudre le système.
- Affichage détaillé des matrices et des solutions.

---

## **Structure du projet**
- **`main.cpp`** : Point d'entrée principal pour exécuter le programme.
- **`ldlt_profil_cuthill_mckee.hpp`** : Déclaration des classes et des fonctions principales.
- **`ldlt_profil_cuthill_mckee.cpp`** : Implémentation des algorithmes et des méthodes de résolution.
- **`dim.txt`** : Exemple de fichier contenant un système linéaire.

---

## **Pré-requis**
- **C++11** ou une version ultérieure.
- Un compilateur C++ (e.g., `g++`, `clang`).
- Un fichier contenant la matrice du système et le vecteur second membre (e.g., `dim.txt`).

---

## **Installation et Compilation**
1. Clonez ce dépôt sur votre machine locale :
   ```bash
   git clone https://github.com/rojo120/LDLTProfilSolver.git
   cd LDLTProfilSolver
   ```

2. Compilez le projet avec `g++` :
   ```bash
   g++ -o solver main.cpp ldlt_profil_cuthill_mckee.cpp
   ```

3. Lancez l'exécutable :
   ```bash
   ./solver
   ```

---

## **Format du fichier d'entrée**
Le fichier doit respecter le format suivant :
- La première ligne contient un entier représentant la dimension **n** de la matrice.
- Les **n** lignes suivantes contiennent les coefficients de la matrice **A**.
- La dernière ligne contient les valeurs du vecteur **b**.

### Exemple (`dim.txt`)
```
3
4 1 2
1 5 3
2 3 6
8
3
7
```

---

## **Exécution**
1. Placez le fichier `dim.txt` dans le même répertoire que l'exécutable.
2. Exécutez le programme :
   ```bash
   ./solver
   ```

### Exemple de sortie :
```
Matrice A initiale :
4.00    1.00    2.00
1.00    5.00    3.00
2.00    3.00    6.00

Solution :
x[1] = 1.23
x[2] = 2.34
x[3] = 3.45
```

---

## **Fonctionnalités détaillées**
1. **Réordonnancement** :
   - Utilisation de l'algorithme **Reverse Cuthill-McKee** pour améliorer la structure de la matrice.
2. **Décomposition LDLT** :
   - La matrice est factorisée en une matrice triangulaire inférieure **L**, une matrice diagonale **D**, et la transposée de **L**.
3. **Stockage en profil** :
   - Seuls les éléments nécessaires de la matrice sont stockés, réduisant ainsi l'utilisation de mémoire.

---

## **À venir**
- Implémentation complète de l'algorithme Cuthill-McKee.
- Support pour des systèmes plus complexes.

---

## **Auteur**
- **Rojo**  
Étudiant en M1 Mathématiques, Informatiques et Statistique Appliquée.

