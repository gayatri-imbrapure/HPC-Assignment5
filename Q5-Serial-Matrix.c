#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 

void matrix_multiply_serial(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void print_matrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices A and B with random values
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Perform matrix multiplication
    clock_t start = clock();
    matrix_multiply_serial(A, B, C);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Serial Execution Time: %f seconds\n", time_taken);

    // Print the result matrix
    printf("Result Matrix (Serial):\n");
    print_matrix(C);

    return 0;
}
