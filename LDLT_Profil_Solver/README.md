# **LDLT Profil Solver**

## **Description**
Ce programme implémente un solveur pour les systèmes linéaires de la forme **Ax = b**, en utilisant :
- **Stockage en profil** pour optimiser l'utilisation de la mémoire en ne stockant que les éléments non nuls et nécessaires de la matrice.
- **Décomposition LDLT** : une méthode factorisant une matrice symétrique en une matrice triangulaire inférieure **L**, une matrice diagonale **D**, et la transposée de **L**.
- Méthode de résolution basée sur ces décompositions.

Ce solveur est conçu pour être efficace sur des matrices creuses symétriques, réduisant à la fois l'espace mémoire et les calculs inutiles.

---

## **Structure du projet**
- **`main.cpp`** : Point d'entrée principal du programme.
- **`ldlt_profil.hpp`** : Déclaration de la classe et des fonctions.
- **`ldlt_profil.cpp`** : Implémentation des algorithmes.
- **`dim.txt`** : Exemple de fichier d'entrée contenant une matrice et un second membre.

---

## **Fonctionnalités**
1. **Chargement des données** depuis un fichier texte (matrice **A** et vecteur **b**).
2. **Stockage en profil** :
   - Optimisation de la mémoire pour gérer uniquement les parties pertinentes de la matrice.
3. **Décomposition LDLT** :
   - Factorisation de la matrice en **L**, **D**, et **L.T**.
4. **Résolution du système** :
   - Résolution des équations triangulaires résultantes.
5. **Affichage** des matrices, des indices et des solutions.

---

## **Format du fichier d'entrée**
Le fichier d'entrée doit respecter le format suivant :
1. La première ligne contient la taille de la matrice **n**.
2. Les **n** lignes suivantes représentent les coefficients de la matrice **A**.
3. Une dernière ligne contient le vecteur **b**.

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
### Compilation
Assurez-vous d'avoir un compilateur compatible avec **C++11** ou supérieur. Pour compiler le projet :
```bash
g++ -o solver main.cpp ldlt_profil.cpp
```

### Lancement
Placez un fichier d'entrée (`dim.txt`) dans le répertoire, puis exécutez le programme :
```bash
./solver
```

---

## **Exemple de sortie**
Avec le fichier `dim.txt` donné en exemple, la sortie pourrait être :
```
Étape 1 : Chargement de la matrice A et du vecteur b
Matrice A :
4.00  1.00  2.00
1.00  5.00  3.00
2.00  3.00  6.00

Étape 2 : Stockage en profil
La matrice A en stockage profil :
M_0: 4.00  
M_1: 1.00  5.00  
M_2: 2.00  3.00  6.00  

Étape 3 : Décomposition LDLT
Matrice L :
1.00  0.00  0.00
0.25  1.00  0.00
0.50  0.20  1.00

Matrice D :
4.00  0.00  0.00
0.00  4.75  0.00
0.00  0.00  4.80

Étape 4 : Résolution
Solution :
x[1] = 1.00
x[2] = 0.80
x[3] = 0.70
```

---

## **Mémoire et nettoyage**
Le programme alloue dynamiquement les matrices et vecteurs nécessaires. Tous les espaces mémoire sont libérés à la fin de l'exécution grâce à la méthode **`freeAll()`**.

---

## **Auteur**
- **Rojo**  
Étudiant en M1 Mathématiques, Informatiques et Statistique Appliquée.

