#include <stdio.h>
#include <omp.h>

#define SERIES_LENGTH 10  // Define the length of the series
int main() {
    // Parallel region with two threads
    #pragma omp parallel num_threads(2)
    {
        int thread_id = omp_get_thread_num();  // Get the thread ID

        if (thread_id == 0) {
            // Thread 0 prints the series of 2
            printf("Series of 2 (Thread %d):\n", thread_id);
            for (int i = 1; i <= SERIES_LENGTH; i++) {
                printf("%d ", 2 * i);
            }
            printf("\n");
        } else if (thread_id == 1) {
            // Thread 1 prints the series of 4
            printf("Series of 4 (Thread %d):\n", thread_id);
            for (int i = 1; i <= SERIES_LENGTH; i++) {
                printf("%d ", 4 * i);
            }
            printf("\n");
        }
    }

    return 0;
}
