#include "algorithms.h"

float fcfs(Queue *queue) {
    Process currentProcess;
    Queue *endedProcesses = startQueue();
    int totalProcess = queue->length;
    int totalTime = 0;
    int remainingTime = 0;
    float avarageTime = 0;
    int sum = 0;

    while(queue->length > 0) {
        currentProcess = unqueue(queue);
        remainingTime = currentProcess.time;

        currentProcess.startTime = totalTime;
        while(remainingTime > 0) {
            totalTime++;
            remainingTime--;
        }
        
        sum += currentProcess.startTime;
        
        insert(endedProcesses, currentProcess);
    }


    avarageTime = (float)sum / totalProcess;

    ganttDiagram(endedProcesses, totalTime);

    return avarageTime;
}

void executeFcfs() {
    Queue *queue = startQueue();
    inputProcessQueue(queue);
    float avarageWaitingTime = fcfs(queue);
    
    printf("\nTempo médio de espera: %.2f\n\n", avarageWaitingTime);
}