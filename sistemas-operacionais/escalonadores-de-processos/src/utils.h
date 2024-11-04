#include "queue.h"

int getTotalTime(Queue *queue);
void ganttDiagram(Queue *queue, int totalTime);
void orderById(Process *process, int n);
void printGranntDiagram(Process *process, int n, int totalTime);
Process *inputProcessArray(int n);
void inputProcessQueue(Queue *queue);