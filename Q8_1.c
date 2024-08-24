#include <stdio.h>
#include <stdlib.h>
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
    clock_t start = clock();
    // Calculate the sum of all elements in the array
    for (int i = 0; i < SIZE; i++) {
        total_sum += arr[i];
    }
    // End measuring time
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total Sum (Sequential): %lld\n", total_sum);
    printf("Time taken (Sequential): %f seconds\n", time_taken);

    free(arr);
    return 0;
}
