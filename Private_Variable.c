#include <stdio.h>
#include <omp.h>

int main() {
    int Aryabhatta = 10;  // Initialize the variable

    #pragma omp parallel private(Aryabhatta)
    {
        // Each thread has its own copy of Aryabhatta
        int thread_id = omp_get_thread_num();  // Get the thread ID
        Aryabhatta = 10;  // Set Aryabhatta for the current thread (though it's the same for all)

        // Perform multiplication
        int result = thread_id * Aryabhatta;

        // Print the result
        printf("Thread %d: %d * %d = %d\n", thread_id, thread_id, Aryabhatta, result);
    }

    return 0;
}
