# EigenSolver - Power Iteration Method

## Description
EigenSolver is a C++ program that implements the power iteration method to find the dominant eigenvalue and corresponding eigenvector of a square matrix. The program uses iterative computation to converge to the largest eigenvalue by performing matrix-vector multiplication and normalizing the result.

## Requirements
- C++ Compiler (C++11 or higher)
- Standard C++ libraries

## Installation
1. Clone the repository:
   ```
   git clone https://github.com/rojo120/CppAdventures.git
   ```

2. Navigate to the `EigenSolver` directory:
   ```
   cd EigenSolver
   ```

3. Compile the program:
   ```
   g++ -o EigenSolver main.cpp iterees.cpp
   ```

## Usage
1. Create a square matrix of size 5x5 and an initial vector to start the iteration.

2. Run the program:
   ```
   ./EigenSolver
   ```

3. The program will display the matrix and compute the largest eigenvalue.

## Example
Example matrix:
```
| 4  | -1 |  0 |  0 |  0 |
| -1 |  4 | -1 |  0 |  0 |
|  0 | -1 |  4 | -1 |  0 |
|  0 |  0 | -1 |  4 | -1 |
|  0 |  0 |  0 | -1 |  3 |
```

Output:
```
Here is the matrix in question:
4    -1    0    0    0
-1    4    -1   0    0
0    -1    4    -1   0
0    0    -1   4    -1
0    0    0    -1   3
The largest eigenvalue is 5.0
```
