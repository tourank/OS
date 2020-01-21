#include <stdio.h>

void printName(int n);

int main() {
 
    printName(5);
    return 0;
}

void printName(int n) {

    int i = 0;
    printf("Please enter an integer: ");
    scanf("%d", &n);
    while(i < n) {
    
        printf("Touran \n");
        i++;
    }
    //return 0;

}
