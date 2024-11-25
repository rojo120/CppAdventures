# Gradient Descent Solver

## Description
The Gradient Descent Solver is a C++ implementation that uses the gradient descent algorithm to solve systems of linear equations. The project reads matrix data from a file, applies the gradient descent method, and computes the solution for the system.

## Features
- Load a system of linear equations from a file
- Solve the system using gradient descent
- Display the matrix and the solution
- Support for customizable precision when displaying results

## Requirements
- C++11 or later
- C++ compiler (e.g., g++, clang++)
- A matrix file (e.g., `dim.txt`) with system data

## Installation
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/rojo120/CppAdventures.git
   ```

2. Navigate to the `Gradient_Descent_Solver` directory:
   ```bash
   cd Gradient_Descent_Solver
   ```

3. Compile the code:
   ```bash
   g++ -o GradientDescentSolver main.cpp GradientDescentSolver.cpp
   ```

4. Run the program:
   ```bash
   ./GradientDescentSolver
   ```

## Usage
1. Prepare a file with your matrix data (e.g., `dim.txt`). The file should follow the structure:
   - The first line contains the size of the matrix `n`.
   - The next `n` lines contain the coefficients of the matrix `A`, followed by the values of the vector `b`.

2. Run the program, which will load the matrix, perform gradient descent, and display the results.

## Example `dim.txt`:
```
3
2 1 1 5
1 2 1 5
1 1 2 5
```

