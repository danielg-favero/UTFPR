#include "queue.h"

void printQueue(Queue *queue) {
    int i;

    printf("\nTotal de processos: %d\n", queue->length);
    printf("\nPID\tTime\tPriority\n");
    for(i = 0; i < queue->length; i++){
        printf("%d\t%d\t%d\n", queue->processes[i].pid, queue->processes[i].time, queue->processes[i].priority);
    }
}

Queue *startQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->processes = (Process *) malloc(MAX_SIZE_PROCESSES * sizeof(Process));
    queue->length = 0;

    return queue;
}

int insert(Queue *queue, Process process) {
    if(queue->length + 1 > MAX_SIZE_PROCESSES) return 0;

    queue->processes[queue->length] = process;
    queue->length++;

    return 1;
}

Process unqueue(Queue *queue) {
    int i;
    Process unqueuedProcess = queue->processes[0];

    for(i = 0; i < queue->length - 1; i++){
        queue->processes[i] = queue->processes[i + 1];
    }

    queue->length--;


    return unqueuedProcess;
}

Process removeFromQueue(Queue *queue, int index) {
    int i;
    Process unqueuedProcess = queue->processes[index];

    for(i = index; i < queue->length - 1; i++){
        queue->processes[i] = queue->processes[i + 1];
    }

    queue->length--;

    return unqueuedProcess;
}