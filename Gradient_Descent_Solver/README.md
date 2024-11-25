# EigenSolver - Méthode de Puissance Itérative

## Description
EigenSolver est un programme en C++ qui implémente la méthode de puissance itérative pour trouver la valeur propre dominante et le vecteur propre correspondant d'une matrice carrée. Le programme effectue des calculs itératifs en multipliant une matrice par un vecteur et en normalisant le résultat pour converger vers la plus grande valeur propre.

## Prérequis
- Compilateur C++ (C++11 ou supérieur)
- Bibliothèques standard C++

## Installation
1. Clonez le dépôt :
   ```
   git clone https://github.com/rojo120/CppAdventures.git
   ```

2. Accédez au dossier `EigenSolver` :
   ```
   cd EigenSolver
   ```

3. Compilez le programme :
   ```
   g++ -o EigenSolver main.cpp iterees.cpp
   ```

## Utilisation
1. Créez une matrice carrée de taille 5x5 et un vecteur initial pour démarrer l'itération.

2. Exécutez le programme :
   ```
   ./EigenSolver
   ```

3. Le programme affichera la matrice et calculera la plus grande valeur propre.

## Exemple
Exemple de matrice :
```
| 4  | -1 |  0 |  0 |  0 |
| -1 |  4 | -1 |  0 |  0 |
|  0 | -1 |  4 | -1 |  0 |
|  0 |  0 | -1 |  4 | -1 |
|  0 |  0 |  0 | -1 |  3 |
```

Résultat :
```
Voici la matrice en question :
4    -1    0    0    0
-1    4    -1   0    0
0    -1    4    -1   0
0    0    -1   4    -1
0    0    0    -1   3
La plus grande valeur propre est 5.0
```
