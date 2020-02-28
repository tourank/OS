#include <stdio.h> //main file that contains main() and parse functions
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"

int parse(char arr[]);
int shellUI() {

    char prompt[100] = {'$', '\0'};
    char userInput[1000];
    int errorCode = 0;
    //infinite loop that remains active until user exits, find a way to 
    //define this exit that isn't an error code. probably a function in C
    //we want the cursor to flash. from this prompt the user will type in 
    //their command and the shell will display the result and the dollar 
    //sign reappears after to prompt the next command until they ask to quit
    while(1) {

        printf("%s ", prompt);
        fgets(userInput, 999, stdin); //limit input to array size
        strtok(userInput, "\n");
        strtok(userInput, "\r");
        errorCode = parse(userInput);
        //if after parsing we have an error, exit
        if (errorCode == -1) {

            exit(99);
        }
        //otherwise we implement the commands
    }
}


int parse(char arr[]) {

    char tmp[200];
    int index = 0;
    char *words[100];
    int i, j;

    for(i = 0; arr[i]==' ' && i<1000; i++);

    while(arr[i] != '\0' && i < 1000) {

        for(j=0; arr[i] != '\0' && arr[i] != ' ' && i < 1000; i++, j++) {

            tmp[j] = arr[i];
        }
        tmp[j] = '\0';
        words[index] = strdup(tmp);
        i++;
        index++;
    } 

    return interpreter(words,index);

}
