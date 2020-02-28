#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pcb.h"

char *ram[1000]; //array of char pointers

//add a function to clear all the cells in the ram after execution

void addToRAM(FILE *fp, int *start, int *end) {

    //add contents of file (each word) into a slot in the ram array
    //update start and end here
    //while loop where each line gets read into ram in fgets

    char buffer[333];
    while(ram[*start] != NULL) {
        *start++;
    }
    *end = *start;
    while(fgets(buffer, sizeof(buffer), fp) != NULL && *end < 1000) {

        ram[*end] = strdup(buffer);
        *end++;
    } 
}

void clearRAM(struct PCB *pcb) {

    int i = pcb->start; 
    while(i < pcb->end) {
        ram[i] = NULL;
    }
}

char *getRAM(int index) {

    return ram[index];
}
