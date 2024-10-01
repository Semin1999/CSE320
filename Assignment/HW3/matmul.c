#include <stdio.h>

#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 2

// void matrix_multiply(int A[ROWS_A][COLS_A], int B[ROWS_B][COLS_B], int
// 			C[ROWS_A][COLS_B]) {
//     for (int i = 0; i < ROWS_A; i++) {
//         for (int j = 0; j < COLS_B; j++) {
//             (Implement your code)// Initialize the result matrix el
//             for (int k = 0; k < COLS_A; k++) {
//                 (Implement your code) // Perform matrix multiplicat
//             }
//         }
//     }
// }

int main() {
    int matA[ROWS_A][COLS_A] = {
        {1, 2, 3},
        {2, 3, 4},
   };

    int matB[ROWS_B][COLS_B] = {
        {1, 2},
        {2, 3},
        {3, 4},
    };

    int matOut[ROWS_A][COLS_B];

    // Multiply matrices matA and matB
    for(int i = 0; i < ROWS_A; i++){
        int mulNum = 0;
        for(int j = 0; j < COLS_A; j++){
            mulNum += matA[i][j] * matB[j][i];
            printf("mulNum[%d][%d]: %d ,", i,j, mulNum);
        }
        printf("mulNum: %d", mulNum);
    }

    // Print the result of the matrix multiplication
    //(Implement your code)

    return 0;
}
