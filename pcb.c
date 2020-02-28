#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct PCB {

    //PC is int that refers to the cell number of ram[] containing the instruction to execute
    int PC, start, end;
    struct PCB *next;

};

struct PCB* makePCB(int start, int end) {

    //create an instance of a new PCB
    struct PCB *pcb = (struct PCB*)malloc(sizeof(struct PCB));
    pcb->start = start;
    pcb->end = end;
    pcb->PC = start;
    //PC only updated after quanta is finished
    //only updated after a task switch
    pcb->next = NULL;
    return pcb;
}
