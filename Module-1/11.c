/*
11. Write a program in C for a 2D array of size 3x3 and print the matrix.
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main() {
    // Dynamically allocate memory for 3x3 matrix
    int (*arr)[COLS] = malloc(ROWS * sizeof(*arr));

    // Check memory allocation
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements
    printf("==== Enter the elements of 3 x 3 matrix ====\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print matrix
    printf("\n==== The Matrix (3 x 3) ====\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free(arr);

    return 0;
}