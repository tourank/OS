#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//contains the private data structures and public functions that implement the
//shell memory

//if VAR exists, string overwrites previous value assigned to VAR 
//if VAR does not exist, then a new entry is added to the shell memory where the variable name is VAR and the contents
//of the variable is STRING
//e.g. set x 10 creates new var x and assigns a value 10
//e.g. set x Marie replaces the value 10 with Marie
//e.g.2 set name Bob creates a new var valled name with string value Bob

//we will have array of structs so when using set, check if struct with corresponding var already exists in that array
int exists(char *str);
typedef struct MEM {

    char *var;
    char *value;
} MEM;

//declare this array of structs and make it public, add to it from interpreter when necessary 
MEM memory_vars[1000];
//check if var exists or not in array

int exists(char *str) {

    int boolean = 1;
    int i = 0;
    for(i=0; i<1000; i++) {

        if(memory_vars[i].var != NULL) {

            boolean = strcmp(memory_vars[i].var, str);
            if (boolean == 0) {
                return i;
            }
        }
    }
    return -1;
}


