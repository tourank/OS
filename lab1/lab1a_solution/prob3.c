#include <stdio.h>
#include <stdlib.h>

/** 
 * if l == m, multiply matrix x array, and store the output in the first column of matrix 
 * 
 * return 0 if no error, and 1 otherwise.
 * */
int multiply(int **matrix, size_t n, size_t m, int *array, size_t l) {
    if (m != l) {
        fprintf(stderr, "Error! >_<\n");
        return 1;
    }
    
    for(size_t j = 0; j < m; ++j) {
        for(size_t i = 0; i < n; ++i) {
            matrix[i][j] *= array[j];
        }
    }
    
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 1; j < m; ++j) {
            matrix[i][0] += matrix[i][j];
        }
    }

    return 0;
}

void cleanup(int **matrix, int n, int *array) {
    for (size_t i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    free(array);
}

int main(int argc, char *argv[]) {
    int **matrix;
    size_t n = 3, m = 2;
    matrix = (int **) malloc(sizeof(int *) * n);
    for (size_t i = 0; i < n; ++i) {
        matrix[i] = (int *) malloc(sizeof(int) * m);
    }

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[1][0] = 3;
    matrix[1][1] = 4;
    matrix[2][0] = 5;
    matrix[2][1] = 6;

    size_t l = m; // change value of l to 3 for example to get an error :)
    int *array = (int *) malloc(sizeof(int) * l); 
    array[0] = 1;
    array[1] = -1;

    int isError = multiply(matrix, n, m, array, l);

    if (isError) {
        // do not forget to free your allocated memory
        cleanup(matrix, n, array);
        return isError;
    }

    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < m; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // do not forget to free your allocated memory
    cleanup(matrix, n, array);

    return 0;
}
