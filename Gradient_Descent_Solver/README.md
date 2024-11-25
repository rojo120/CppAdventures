# Gradient Descent Solver

## Description
Le **Gradient Descent Solver** est une implémentation en C++ de l'algorithme de descente de gradient pour résoudre des systèmes d'équations linéaires. Ce projet lit les données d'une matrice à partir d'un fichier, applique la méthode de descente de gradient et calcule la solution du système.

## Fonctionnalités
- Charger un système d'équations linéaires depuis un fichier
- Résoudre le système à l'aide de la méthode de descente de gradient
- Afficher la matrice et la solution
- Précision personnalisable pour l'affichage des résultats

## Prérequis
- C++11 ou version ultérieure
- Un compilateur C++ (par exemple : g++, clang++)
- Un fichier de matrice (par exemple, `dim.txt`) contenant les données du système

## Installation
1. Clonez ce dépôt sur votre machine locale :
   ```bash
   git clone https://github.com/rojo120/CppAdventures.git
   ```

2. Accédez au répertoire `Gradient_Descent_Solver` :
   ```bash
   cd Gradient_Descent_Solver
   ```

3. Compilez le code :
   ```bash
   g++ -o GradientDescentSolver main.cpp GradientDescentSolver.cpp
   ```

4. Exécutez le programme :
   ```bash
   ./GradientDescentSolver
   ```

## Utilisation
1. Préparez un fichier contenant les données de votre matrice (par exemple, `dim.txt`). La structure du fichier doit être la suivante :
   - La première ligne contient la taille de la matrice `n`.
   - Les `n` lignes suivantes contiennent les coefficients de la matrice `A`, suivis des valeurs du vecteur `b`.

2. Exécutez le programme, qui chargera la matrice, appliquera la méthode de descente de gradient et affichera les résultats.

## Exemple de fichier `dim.txt` :
```
3
2 1 1 5
1 2 1 5
1 1 2 5
```
