#include <stdio.h>

#define MAX 20
int queenPosition[MAX];  // queenPosition[row] = column index
int solutionFound = 0;   // flag to stop after first valid solution

// Function to print one solution board
void printBoard(int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (queenPosition[r] == c)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if placing queen at (row, col) is safe
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queenPosition[i] == col)               // same column
            return 0;
        if ((queenPosition[i] - i) == (col - row)) // major diagonal
            return 0;
        if ((queenPosition[i] + i) == (col + row)) // minor diagonal
            return 0;
    }
    return 1;
}

// Recursive solver that stops after first solution
void solveNQueen(int row, int n) {
    if (solutionFound) return; // stop recursion once a solution is found

    if (row == n) {
        printf("One possible solution for %d–Queen problem:\n\n", n);
        printBoard(n);
        solutionFound = 1;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            queenPosition[row] = col;
            solveNQueen(row + 1, n);
            if (solutionFound) return; // early exit
        }
    }
}

int main() {
    int n = 8; // change as needed
    printf("N–Queen Problem (Backtracking – Single Solution)\n");
    printf("\n\n");

    solveNQueen(0, n);

    if (!solutionFound)
        printf("No solution exists for %d–Queen problem.\n", n);

    return 0;
}
