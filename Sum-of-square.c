#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads, sum = 0;
    // Parallel region to print squares and sum them
    #pragma omp parallel
    {
        // Get the thread number (thread ID)
        int thread_id = omp_get_thread_num();
        int square = thread_id * thread_id;

        // Each thread prints its ID and the square of its ID
        printf("Thread %d: Square = %d\n", thread_id, square);

        // Use a critical section to safely update the sum
        #pragma omp critical
        {
            sum += square;
        }
    }
    // Print the total sum of squares
    printf("Sum of squares of thread IDs = %d\n", sum);

    return 0;
}
