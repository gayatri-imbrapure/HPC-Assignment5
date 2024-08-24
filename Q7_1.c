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

    // Parallel region to calculate the sum
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        total_sum += arr[i];  // This is unsafe and can lead to race conditions
    }

    printf("Total Sum (Unsynchronized): %d\n", total_sum);

    return 0;
}
