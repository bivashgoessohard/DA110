/*
13. Write a program in C to print or display the lower triangular of a given matrix.
*/

#include <stdio.h>
#include <stdlib.h>


// Lower triangular form function
void lower_triangular_matrix(int rows, int cols, int arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < j) {
                arr[i][j] = 0;
            }
        }
    }
}



int main() {
    int size, rows, cols;

    // Take input of the size of the square matrix and validate input
    printf("Enter the size of the square matrix: ");
    if (scanf("%d", &size) != 1 || size < 2) {
        printf("Invalid input!\n");
        return 1;
    }

    rows = cols = size;

    // Dynamically allocate memory
    int (*arr)[cols] = malloc(rows * sizeof(*arr));

    // Check for memory
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Take input elements of the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("==> Input element - [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("Invalid input!\n");
                free(arr);
                return 1;
            }
        }
    }

    // Print the matrix
    printf("==== Matrix (%d x %d) ====\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    // Call the lower triangular matrix function
    lower_triangular_matrix(rows, cols, arr);

    // Print the lower triangular form of the same matrix
    printf("==== Matrix (Lower Triangular Form) ====\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}