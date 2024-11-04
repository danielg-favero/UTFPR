#include "algorithms.h"

float sjf(Process *process, int n) {
    int i, j;
    Process aux;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (process[i].time > process[j].time) {
                aux = process[i];
                process[i] = process[j];
                process[j] = aux;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            process[i].startTime = 0;
        }
        else {
            process[i].startTime = process[i - 1].startTime + process[i - 1].time;
        }
    }

    for (i = 0; i < n; i++) {
        process[i].endTime = process[i].startTime + process[i].time;
    }

    int totalTime = 0;
    for (i = 0; i < n; i++) {
        totalTime += process[i].startTime;
    }
    
    return (float)totalTime / n;
}

void executeSjf() {
    int n;
    int i;
    printf("\nInforme a quantidade de processos: ");
    scanf("%d", &n);

    Process *process = inputProcessArray(n);
    int totalTime = 0;

    for(i = 0; i < n; i++){
        totalTime += process[i].time;
    }

    float avarageWaitingTime = sjf(process, n);

    printf("\nTempo medio de espera: %.2f\n", avarageWaitingTime);

    printGranntDiagram(process, n, totalTime);
}