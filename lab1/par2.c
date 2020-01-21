#include <stdio.h>

void printSentence(char* name, int numRepetitions);

int main(int argc, char *argv[]) {

    //via scanf ask for a sentence and feed it into the function
    char *name;
    int numRepetitions = 0;
    
    printf("Please input a sentence: \n");
    scanf("%s", name);
    
    printf("Please Enter Desired Number of Repetitions. \n");
    scanf("%d", &numRepetitions);

    printf("String %s will be repeated %d times.\n", name, numRepetitions);
    printSentence(name, numRepetitions);

    return 0;
}

void printSentence(char* name, int numRepetitions) {


    int i = 0;
    while (i < numRepetitions) {
    
        printf("%s\n", name);
        i++;
    }

}




