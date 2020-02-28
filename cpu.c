#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pcb.h"
#include "ram.h"
#include "cpu.h"
#include "ready_queue.h"
#include "interpreter.h"
#include "shell.h"
#include "kernel.h"

//contains the following fields:
//instruction pointer, instruction register, quanta

struct CPU *cpu = NULL;
void run(int quanta) {

    char *cell;
    int index, errCode, endOfFile;
    endOfFile = queue->head->end;
    cpu->quanta = quanta;
    cpu->IP = queue->head->PC;
    while(quanta > 0 && cpu->IP < endOfFile) {
        
        //get the instruction at the ram cell IP
        cell = getRAM(cpu->IP);
        //copy the instruction into the IR
        strcpy(cpu->IR, cell);
        //parse the IR input
        errCode = parse(cpu->IR);
        cpu->IP++;
        cpu->quanta--;
        if(quanta == 0 && cpu->IP < endOfFile) {
            //update PCB PC with IP
            queue->head->PC = cpu->IP;
            roundRobin(); //automatically takes current head and places it at tail of queue
        }
        else if (cpu->IP >= endOfFile) {
            //function that assigns null to all ram cells 
            clearRAM(queue->head);
            //funciton that removes the pcb and frees it from queue
            removePCB();
        }
    }

}
