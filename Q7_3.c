#include <stdio.h>
#include <omp.h>
#include <time.h>

#define SIZE 1000

int main() {
    int arr[SIZE];
    int total_sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // Initialize the array with values from 1 to SIZE
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    // Unsynchronized version
    total_sum = 0;
    start = clock();
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        total_sum += arr[i];  // Unsafe
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total Sum (Unsynchronized): %d, Time: %f seconds\n", total_sum, cpu_time_used);

    // Synchronized with critical
    total_sum = 0;
    start = clock();
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        #pragma omp critical
        {
            total_sum += arr[i];  // Safe, but can cause performance degradation
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total Sum (Synchronized with critical): %d, Time: %f seconds\n", total_sum, cpu_time_used);

    // Synchronized with atomic
    total_sum = 0;
    start = clock();
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        #pragma omp atomic
        total_sum += arr[i];  // Safe and more efficient than critical
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total Sum (Synchronized with atomic): %d, Time: %f seconds\n", total_sum, cpu_time_used);

    return 0;
}
