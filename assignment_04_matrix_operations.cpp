// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
  
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}
void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int transposed[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int rows, int cols, int sum[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB, int product[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}
void clearMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }
}
void partA() {
    int rows, cols;
    cout << "Enter number of rows (max " << MAX_SIZE << "): ";
    cin >> rows;
    cout << "Enter number of columns (max " << MAX_SIZE << "): ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        cout << "Error: Rows and columns must be between 1 and " << MAX_SIZE << "." << endl;
        return;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];

    readMatrix(matrix, rows, cols);
    transposeMatrix(matrix, rows, cols, transposed);

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrix, rows, cols);
    cout << "\nTransposed Matrix:\n";
    printMatrix(transposed, cols, rows);
}
void partB() {
    int rows, cols;
    cout << "Enter number of rows (max " << MAX_SIZE << "): ";
    cin >> rows;
    cout << "Enter number of columns (max " << MAX_SIZE << "): ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        cout << "Error: Rows and columns must be between 1 and " << MAX_SIZE << "." << endl;
        return;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int sum[MAX_SIZE][MAX_SIZE];

    cout << "\nMatrix A:\n";
    readMatrix(matrixA, rows, cols);
    cout << "\nMatrix B:\n";
    readMatrix(matrixB, rows, cols);

    addMatrices(matrixA, matrixB, rows, cols, sum);

    cout << "\nSum of Matrices:\n";
    printMatrix(sum, rows, cols);
}
void partC() {
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter number of rows for Matrix A (max " << MAX_SIZE << "): ";
    cin >> rowsA;
    cout << "Enter number of columns for Matrix A (max " << MAX_SIZE << "): ";
    cin >> colsA;

    if (rowsA <= 0 || rowsA > MAX_SIZE || colsA <= 0 || colsA > MAX_SIZE) {
        cout << "Error: Rows and columns must be between 1 and " << MAX_SIZE << "." << endl;
        return;
    }

    cout << "Enter number of rows for Matrix B (must equal columns of A): ";
    cin >> rowsB;
    cout << "Enter number of columns for Matrix B (max " << MAX_SIZE << "): ";
    cin >> colsB;

    if (rowsB != colsA || rowsB <= 0 || rowsB > MAX_SIZE || colsB <= 0 || colsB > MAX_SIZE) {
        cout << "Error: Rows of B must equal columns of A and be between 1 and " << MAX_SIZE << "." << endl;
        return;
    }

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int product[MAX_SIZE][MAX_SIZE];

    cout << "\nMatrix A:\n";
    readMatrix(matrixA, rowsA, colsA);
    cout << "\nMatrix B:\n";
    readMatrix(matrixB, rowsB, colsB);

    multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB, product);

    cout << "\nProduct of Matrices:\n";
    printMatrix(product, rowsA, colsB);
}
int main() {
    cout << "Matrix Operations Program\n";
    cout << "-------------------------\n";
    cout << "Part A: Transpose a Matrix\n";
    partA();
    cout << "\nPart B: Add Two Matrices\n";
    partB();
    cout << "\nPart C: Multiply Two Matrices\n";
    partC();
    return 0;
}