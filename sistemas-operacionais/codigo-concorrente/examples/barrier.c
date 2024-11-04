#include <omp.h>
#include <stdio.h>

int main() {
    #pragma omp parallel num_threads (4)
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d executou antes do BARRIER\n", thread_id);

        // Espera todas as threads executarem o código acima para entrar na barreira
        #pragma omp barrier 
        {
            printf("Thread %d executou depois do BARRIER\n", thread_id);
        }
    }

    return 0;
}