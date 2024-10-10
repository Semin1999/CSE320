#include <stdio.h>

#define ROWS_A 9
#define COLS_A 8
#define ROWS_B 8
#define COLS_B 9

void matrix_multiply(int A[ROWS_A][COLS_A], int B[ROWS_B][COLS_B], int C[ROWS_A][COLS_B]) {
    // Iterate over each row of matrix A
    for(int i = 0; i < ROWS_A; i++){
        // Variable to store the result for each element
        int mulNum = 0;

        // Iterate over each column of matrix B
        for(int j = 0; j < COLS_B; j++){
            // Initialize mulNum to zero for each new element in the result matrix
            mulNum = 0;
            // Multiply corresponding elements and accumulate the sum
            for(int k = 0; k < COLS_A; k++){
                // Access array elements using pointer arithmetic
                mulNum += *(*(A + i) + k) * *(*(B + k) + j); // same as: mulNum += A[i][k] * B[k][j];
            }
            // Store the computed value in the result matrix C
            *(*(C + i) + j) = mulNum; // same as: C[i][j] = mulNum;
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
    matrix_multiply(matA, matB, matOut);

    // Print the result of the matrix multiplication
    for(int i = 0; i < ROWS_A; i++){
        // print start of rows with '['
        printf("[ ");
        for(int j = 0; j < COLS_B; j++)
        {   
            // if it is last element of this row, then finish with ']'
            if(j == (COLS_B - 1)){
                printf("%d ]\n", *(*(matOut + i) +j)); //same with: matOut[i][j])
            }
            // if it is not last element of this row, then just finish with ','
            else{
                printf("%d, ", *(*(matOut + i) +j));
            }
        }
    }

    return 0;
}
