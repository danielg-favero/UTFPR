#include "utils.h"

float priorityFunction(Process *process, int n);
void executePriority();

float roundRobin(Queue *queue, int timeSlice);
void executeRR();

float sjf(Process *process, int n);
void executeSjf();

float fcfs(Queue *queue);
void executeFcfs();