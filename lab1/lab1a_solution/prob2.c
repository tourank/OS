#include <stdio.h>
#include <stdlib.h>

void printNameWithRepetition(char *name, int numRepetitions) {
    for (int i = 0; i < numRepetitions; ++i) {
        printf("%s\n", name);
    }
}


int main(int argc, char *argv[]) {
    char *name = (char *) malloc(sizeof(char) * 100);
    int numRepetitions = 0;
    
    printf("Please Enter Your Name.\n");
    scanf("%s", name);

    printf("Please Enter Desired Number of Repetitions.\n");
    scanf("%d", &numRepetitions);
    
    printf("string %s will be repeated %d times.\n", name, numRepetitions);
    printNameWithRepetition(name, numRepetitions);

    free(name);

    return 0;
}
