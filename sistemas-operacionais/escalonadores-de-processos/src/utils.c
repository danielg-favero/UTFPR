#include "utils.h"

int getTotalTime(Queue *queue) {
    int i;
    int totalTime = 0;

    for(i = 0; i < queue->length; i++){
        totalTime += queue->processes[i].time;
    }

    return totalTime;
}

void ganttDiagram(Queue *queue, int totalTime) {
    int i, j = 0;

    for (i = 0; i < queue->length; i++) {
        printf("P%d -> ", queue->processes[i].pid);
        for (j = 0; j < queue->processes[i].startTime; j++) {
            printf("-");
        }
        for (j=0; j < queue->processes[i].time; j++) {
            printf("#");
        }
        for (j = queue->processes[i].startTime + queue->processes[i].time; j < totalTime; j++) {
            printf("-");
        }
        printf("\n");
    }
}

void orderById(Process *process, int n) {
    int i, j;
    Process aux;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (process[i].pid > process[j].pid) {
                aux = process[i];
                process[i] = process[j];
                process[j] = aux;
            }
        }
    }
}

void printGranntDiagram(Process *process, int n, int totalTime) {
    orderById(process, n);
    int i, k = 0;
    for (i = 0; i < n; i++) {
        printf("P%d -> ", process[i].pid);
        for (k = 0; k < process[i].startTime; k++) {
            printf("-");
        }
        for (k=0; k < process[i].time; k++) {
            printf("#");
        }
        for (k = process[i].startTime + process[i].time; k < totalTime; k++) {
            printf("-");
        }
        printf("\n");
    }
}

void inputProcessQueue(Queue *queue) {
    int n;
    int i;

    printf("\nInforme a quantidade de processos: ");
    scanf("%d", &n);

    printf("\nInsira os processos na fila:\n");
    for(i = 0; i < n; i++){
        Process process;
        int pid;
        int time;
        int priority;

        printf("%d) PID: ", i + 1); 
        scanf("%d", &pid);  

        printf("%d) Time: ", i + 1);   
        scanf("%d", &time);  

        printf("%d) Priority: ", i + 1);   
        scanf("%d", &priority);  

        process.pid = pid;
        process.time = time;
        process.executionTime = time;
        process.priority = priority;
        process.startTime = 0;
        process.endTime = 0;

        printf("\n");
        insert(queue, process);
    }
}

Process *inputProcessArray(int n) {
    int i;
    
    Process *process = (Process *)malloc(n * sizeof(Process));

    printf("\nInsira os processos na fila:\n");
    for(i = 0; i < n; i++){
        int pid;
        int time;
        int priority;

        printf("%d) PID: ", i + 1); 
        scanf("%d", &pid);  

        printf("%d) Time: ", i + 1);   
        scanf("%d", &time);  

        printf("%d) Priority: ", i + 1);   
        scanf("%d", &priority);  

        process[i].pid = pid;
        process[i].time = time;
        process[i].executionTime = time;
        process[i].priority = priority;
        process[i].startTime = 0;
        process[i].endTime = 0;

        printf("\n");
    }

    return process;
}