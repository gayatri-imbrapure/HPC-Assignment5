#include <stdio.h>
#include <omp.h>

int main() {
    int n = 20;  // Number of natural numbers
    int total_sum = 0;  // To hold the final sum
    #pragma omp parallel
    {
        int partial_sum = 0;  // Each thread's private copy of the partial sum
        int thread_id = omp_get_thread_num();  // Get the thread ID
        int num_threads = omp_get_num_threads();  // Get the number of threads
        int chunk_size = (n + num_threads - 1) / num_threads;  // Calculate chunk size
        // Compute partial sum for each thread
        for (int i = thread_id * chunk_size + 1; i <= (thread_id + 1) * chunk_size && i <= n; ++i) {
            partial_sum += i;
        }
        // Print partial sum of each thread
        printf("Thread %d: Partial Sum = %d\n", thread_id, partial_sum);
        // Use lastprivate to ensure the last thread's partial sum is used
        #pragma omp critical
        {
            total_sum += partial_sum;
        }
    }
    printf("Total Sum of the first %d natural numbers = %d\n", n, total_sum);

    return 0;
}
