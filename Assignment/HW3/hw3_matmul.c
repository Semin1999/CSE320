#include <stdio.h>

#define ROWS_A 9
#define COLS_A 8
#define ROWS_B 8
#define COLS_B 9

void matrix_multiply(int A[ROWS_A][COLS_A], int B[ROWS_B][COLS_B], int
			C[ROWS_A][COLS_B]) {
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            (Implement your code)// Initialize the result matrix el
            for (int k = 0; k < COLS_A; k++) {
                (Implement your code) // Perform matrix multiplicat
            }
        }
    }
}

int main() {
    int matA[ROWS_A][COLS_A] = {
        {1, 2, 3, 4, 5, 6, 7, 8},
        {2, 3, 4, 5, 6, 7, 8, 9},
        {3, 4, 5, 6, 7, 8, 9, 1},
        {4, 5, 6, 7, 8, 9, 1, 2},
        {5, 6, 7, 8, 9, 1, 2, 3},
        {6, 7, 8, 9, 1, 2, 3, 4},
        {7, 8, 9, 1, 2, 3, 4, 5},
        {8, 9, 1, 2, 3, 4, 5, 6},
        {9, 1, 2, 3, 4, 5, 6, 7},
   };

    int matB[ROWS_B][COLS_B] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {2, 3, 4, 5, 6, 7, 8, 9, 1},
        {3, 4, 5, 6, 7, 8, 9, 1, 2},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {5, 6, 7, 8, 9, 1, 2, 3, 4},
        {6, 7, 8, 9, 1, 2, 3, 4, 5},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {8, 9, 1, 2, 3, 4, 5, 6, 7},
    };

    int matOut[ROWS_A][COLS_B];

    // Multiply matrices matA and matB
    (Implement your code)

    // Print the result of the matrix multiplication
    (Implement your code)

    return 0;
}
