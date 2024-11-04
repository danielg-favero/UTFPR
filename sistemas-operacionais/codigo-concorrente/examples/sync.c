#include <omp.h>
#include <stdio.h>

#define STEPS 1000000

int main() {
    double a[STEPS];
    int i;

    for(i = 0; i < STEPS; i++) a[i] = i;

    double sum = 0;

    #pragma omp parallel for shared (sum) private (i)
    for(i = 0; i < STEPS; i++){
        #pragma omp atomic (sum)
        sum = sum + a[i];
    }

    printf("soma = %lf\n", sum);

    return 0;
}