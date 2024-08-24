#include <stdio.h>
#include <omp.h>
#define SIZE 1000
int main() {
    int arr[SIZE];
    int total_sum = 0;

    // Initialize the array with values from 1 to SIZE
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    // Parallel region to calculate the sum with synchronization
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        #pragma omp critical
        {
            total_sum += arr[i];  // Safe, but can cause performance degradation
        }
    }

    printf("Total Sum (Synchronized with critical): %d\n", total_sum);

    return 0;
}
