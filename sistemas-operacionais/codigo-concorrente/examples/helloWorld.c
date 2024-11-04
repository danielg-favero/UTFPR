/*
    Compilar Código: gcc -o helloWorld -fopenmp helloWorld.c 
*/

#include <omp.h>
#include <stdio.h>

int main(){
    int i;

    #pragma omp parallel for
    for(i = 0; i < 16; i++){
        int thread_id = omp_get_thread_num();
        printf("Olá, mundo da thread %d\n", thread_id);
        
        if(thread_id == 0) printf("Existem %d threads\n", omp_get_num_threads());
    }

    return 0;
}