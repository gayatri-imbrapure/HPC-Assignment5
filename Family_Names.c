#include <stdio.h>
#include <omp.h>

int main() {

    char* family_members[] = {"Savita","Monika","Shalini","Gayatri","Manjula"};
    int num_members = 5; 

    // Parallel region where each thread prints a family member's name
    #pragma omp parallel num_threads(num_members)
    {
        // Get the thread number (job id)
        int thread_id = omp_get_thread_num();

        // Each thread prints the family member's name corresponding to its thread id
        printf("Thread %d: %s\n", thread_id, family_members[thread_id]);
    }

    return 0;
}
