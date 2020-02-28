1. every time we call exec with a file each file is fopened and loaded into ram
2. then malloc a pcb for that program and initialize the pcb's fields
3. the pcb is added to the ready queue
4. after exec call, ram[] cells are assigned NULL for all instructions, PCB removed from queue, free(PCB)

exec goes into interpreter, takes one to three .txt arguments and checks to see if they are not the same files
it opens each program file, calls the function myinit x number of times where x = number of files

myinit(char *file) will then call void addToRAM in ram.c, calls PCB makePCB, void addToReady to add the pcb
to the ready queue

we then call a function called scheduler() which does its work. when the ready queue is empty, exec finishes executing
