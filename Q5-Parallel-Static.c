#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h> 
#define N 100  

void matrix_multiply_static(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for schedule(static)
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

    // Perform matrix multiplication with static scheduling
    double start = omp_get_wtime();
    matrix_multiply_static(A, B, C);
    double end = omp_get_wtime();

    double time_taken = end - start;
    printf("Static Scheduling Execution Time: %f seconds\n", time_taken);

    // Print the result matrix
    printf("Result Matrix (Static Scheduling):\n");
    print_matrix(C);

    return 0;
}
