#include "algorithms.h"

float roundRobin(Queue *queue, int timeSlice) {
    Process currentProcess;
    Process removedProcess;
    Queue *endedProcesses = startQueue();
    int currentTime = 0;
    int queueLength = queue->length;
    int totalTime = getTotalTime(queue);
    int processRemainingTime;
    int i = 0, j = 0, k = 0;
    int sum = 0;

    char ganttDiagram[queueLength][totalTime + 1];
    memset(ganttDiagram, 0, sizeof(ganttDiagram));

    while(queue->length > 0) {
        currentProcess = queue->processes[i];

        processRemainingTime = queue->processes[i].time;
                
        for(j = 0; j < queueLength; j++) {
            if(processRemainingTime <= timeSlice){
                k = processRemainingTime;
            } else {
                k = timeSlice;
            }

            while(k > 0) {
                if(j == currentProcess.pid - 1){
                    strcat(ganttDiagram[j], "#");
                } else {
                    strcat(ganttDiagram[j], "-");
                }
                k--;
            }
        }

        if(processRemainingTime <= timeSlice){
            queue->processes[i].time = 0;
            currentTime += processRemainingTime;
        } else {
            queue->processes[i].time = processRemainingTime - timeSlice;
            currentTime += timeSlice;
        }

        processRemainingTime = queue->processes[i].time;

        if(processRemainingTime == 0){
            removedProcess = removeFromQueue(queue, i);
            removedProcess.endTime = currentTime;

            sum += currentTime - removedProcess.executionTime;

            insert(endedProcesses, removedProcess);

            i--;
        }

        if(i >= queue->length - 1) {
            i = 0;
        } else {
            i++;
        }
    }

    for(i = 0; i < queueLength; i++) {
        printf("P%d -> ", i + 1);
        for(j = 0; j < totalTime; j++) {
            printf("%c", ganttDiagram[i][j]);
        }
        printf("\n");
    } 

    return (float)sum / queueLength;
}

void executeRR() {
    Queue *queue = startQueue();

    int timeSlice;
    printf("\nInforme o Time Slice / Quantum: ");
    scanf("%d", &timeSlice);

    inputProcessQueue(queue);

    float avarageWaitingTime = roundRobin(queue, timeSlice);

    printf("\nTempo médio de espera: %.2f\n\n", avarageWaitingTime);
}