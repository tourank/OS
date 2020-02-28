#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pcb.h"
#include "shell.h"
#include "ram.h"
#include "ready_queue.h"
#include "cpu.h"

void addToReady(struct PCB *pcb);
void myInit(char *file);
void scheduler();

int main() {

    int x = shellUI();
    return 0;
}


void myInit(char *file) {

    int *start = 0;
    int *end = 0;
    FILE *fp;
    fp = fopen(file, "r");
    //calls add to ram
    addToRAM(fp, start, end);
    //initializes a pcb with start and end that were updated in addToRAM
    struct PCB *pcb = makePCB(*start, *end);
    addToReady(pcb);
}

void addToReady(struct PCB *pcb) {

    if (queue->head == NULL && queue->tail == NULL) {

        queue->head = pcb;
        queue->tail = pcb;
    }
    else {
        queue->tail->next = pcb;
        queue->tail = pcb;
    }
    
}
void addLast(struct PCB *pcb) {

    queue->tail->next = pcb;
    queue->tail = pcb;
}

void roundRobin() {

    if(queue->head != NULL) {
        struct PCB *tmp = queue->head->next;
        addLast(queue->head);
        queue->head = tmp;
        tmp = NULL;
    }
    else {
        printf("Queue is empty!\n");
    }
}
void removePCB() {
    
    if(queue->head != NULL) {
        struct PCB *tmp = queue->head->next;
        free(queue->head);
        queue->head = tmp;
        tmp = NULL;
    }
}

void scheduler() {

    const int quantum = 2;
    //cpu has IP (like PCB PC field), IR, quanta
    //IR stores the instruction that will be sent to the interpreter for execution
    //after quanta finishes, update PC of PCB
    run(quantum);  
}

