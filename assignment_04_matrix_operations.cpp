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
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

void printMatrix(const int matrix[MAX][MAX], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(5) << matrix[r][c];
        }
        cout << endl;
    }
    cout << endl;
}

void getMatrixInput(int matrix[MAX][MAX], int rows, int cols, const string& name = "Matrix") {
    cout << "\nEnter elements for " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "Enter element [" << r << "][" << c << "]: ";
            cin >> matrix[r][c];
        }
    }
}

void transposeMatrix(const int src[MAX][MAX], int dest[MAX][MAX], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            dest[c][r] = src[r][c];
        }
    }
}

void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            result[r][c] = A[r][c] + B[r][c];
        }
    }
}

void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int m, n;
    cout << "=== PART A: TRANSPOSE A MATRIX ===" << endl;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    if (m <= 0 || m > MAX || n <= 0 || n > MAX) {
        cout << "Error: Dimensions must be between 1 and " << MAX << "." << endl;
        return 0;
    }

    int matrixA[MAX][MAX];
    getMatrixInput(matrixA, m, n, "Original Matrix");

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrixA, m, n);

    int transposed[MAX][MAX];
    transposeMatrix(matrixA, transposed, m, n);
    cout << "Transposed Matrix:" << endl;
    printMatrix(transposed, n, m);

    cout << "=============================================\n" << endl;

    cout << "=== PART B: ADD TWO MATRICES ===" << endl;
    cout << "Using same matrix size (" << m << "x" << n << ") for addition..." << endl;
    int matrixB[MAX][MAX];
    getMatrixInput(matrixB, m, n, "Second Matrix");

    int added[MAX][MAX];
    addMatrices(matrixA, matrixB, added, m, n);
    cout << "\nMatrix A + Matrix B:" << endl;
    printMatrix(added, m, n);

    cout << "=============================================\n" << endl;

    cout << "=== PART C: MULTIPLY TWO MATRICES ===" << endl;
    int p;
    cout << "For A (" << m << "x" << n << ") x B (" << n << "xP), enter number of columns for Matrix B (P): ";
    cin >> p;

    if (p <= 0 || p > MAX) {
        cout << "Error: Column dimension must be between 1 and " << MAX << "." << endl;
        return 0;
    }

    int matrixC[MAX][MAX];
    getMatrixInput(matrixC, n, p, "Matrix B");

    int multiplied[MAX][MAX];
    multiplyMatrices(matrixA, matrixC, multiplied, m, n, p);
    cout << "\nMatrix A * Matrix B:" << endl;
    printMatrix(multiplied, m, p);

    return 0;
}
