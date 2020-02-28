#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shellmemory.h"
#include "shell.h"
#include "kernel.h"
//contains interpreter() function. each command the function accepts has a 
//corresponding function that implements the command's functionality 
//function should have the same name as the command

void help();
void quit();
void set(char *var, char *string);
void print(char *var);
static int run(char *stirng);

void exec(char *file1, char *file2, char *file3) {

    if (strcmp(file1, file2) == 0 || strcmp(file1, file3) == 0 || strcmp(file2, file3) == 0) {

        printf("Error; can't execute same file more than once\n");
        exit(0);
    }
    else {

        myInit(file1);
        if(file2 != NULL) {
            myInit(file2);
        }
        if(file3 != NULL) {
            myInit(file3);
        }
    }

}
int interpreter(char *words[], int wordCount) {


    //must distinguish between whether a user is asking to execute a script or a command
    //if the user is asking to execute a script
    if (strcmp(words[0], "help") == 0) {

        if(wordCount > 1) {
            return -1;
        } 
        else {
            help();
            return 0;
        }
    }
    if (strcmp(words[0], "quit") == 0) {

        if(wordCount>1) {

            printf("Unknown command\n");
            return -1;
        }
        else {

            quit();
            return 0;
        }
    }
    if (strcmp(words[0], "set") == 0) {

        set(words[1], words[2]);
        return 0;
    }

    if (strcmp(words[0], "print") == 0) {

        print(words[1]);
        return 0;
    }
    if (strcmp(words[0], "run") == 0) {

        run(words[1]);
    }

    if (strcmp(words[0], "exec")) {

        exec(words[1], words[2], words[3]);
    }
    return -1;
}
   
void help() {

    printf("help\n");
    printf("quit\n");
    printf("set\n");
    printf("print\n");
    printf("run\n");

}

void quit() {

    printf("Bye\n");
    exit(0);

}
void set(char* var, char *string) {

    int index = exists(var);
    int i = 0;
    if (index == -1) {

        while(memory_vars[i].var != NULL) {

            i++;
        }
        memory_vars[i].var = var;
        memory_vars[i].value = string;

    }
    else {

        memory_vars[index].value = string;
    }

}
void print(char *var) {

    int result = exists(var);
    if (result == -1) {
    
        printf("Variable does not exist\n.");
    }
    else {
    
        printf("%s\n", memory_vars[result].value);
    }
}

//assumes text file exists. sends each line of it one at a time to the interpreter and it treats 
//each line as a command 
//at the end of the script, the file is closed, cmd prompt displayed again
//as the script executes the cmd prompt is not displayed 
static int run(char *fileName) {

    //printf("%s\n",fileName);
    int errCode = 0;
    char line[1000];
    //printf("%c\n", *words[1]);
    FILE *p = fopen(fileName, "rt");
    if (p == NULL) {
        printf("Script not found\n");
        return -1; //file not found
    }
    while(fgets(line, sizeof(line), p)) {
        strtok(line, "\n");
        strtok(line, "\r");
        errCode = parse(line);
    }
    fclose(p);
    return errCode;
}

//set command checks if var exists. if yes we overrwrite, else assign a new value in shell memory where var name is VAR and contents are STRING
//set x 10 creates new var x and assigns it a value 10

