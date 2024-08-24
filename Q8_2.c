#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define SIZE 1000000  // Define the size of the array
int main() {
    int *arr = (int*)malloc(SIZE * sizeof(int));
    long long total_sum = 0;
    // Initialize the array with random values
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    // Start measuring time
    double start = omp_get_wtime();
    // Parallel region with reduction clause
    #pragma omp parallel for reduction(+:total_sum)
    for (int i = 0; i < SIZE; i++) {
        total_sum += arr[i];
    }
    // End measuring time
    double end = omp_get_wtime();
    double time_taken = end - start;
    printf("Total Sum (Parallel with reduction): %lld\n", total_sum);
    printf("Time taken (Parallel with reduction): %f seconds\n", time_taken);
    free(arr);
    return 0;
}
