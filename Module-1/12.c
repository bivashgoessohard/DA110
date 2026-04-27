/*
12. Write a program in C for adding two matrices of the same size.
*/

#include <stdio.h>
#include <stdlib.h>


// Matrix addition function
void matrix_addition(int rows, int cols,
                     int matrix1[rows][cols],
                     int matrix2[rows][cols],
                     int result[rows][cols]) {

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}


int main() {
    int rows, cols, n;

    // Take input of matrix size
    printf("Enter the size of the square matrix (Less than 5): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n >= 5) {
        printf("Invalid input!\n");
        return 1;
    }

    rows = cols = n;

    // Dynamically allocate memory for 2 matrices
    int (*arr1)[cols] = malloc(rows * sizeof(*arr1));
    int (*arr2)[cols] = malloc(rows * sizeof(*arr2));
    int (*sum)[cols]  = malloc(rows * sizeof(*sum)); // for resulting matrix


    // Validate memory allocation
    if (arr1 == NULL || arr2 == NULL || sum == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Take inputs of the elements of the first matrix
    printf("Enter the elements of the matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("===> Enter element [%d] [%d]: ", i + 1, j + 1);
            if (scanf("%d", &arr1[i][j]) != 1) {
                printf("Invalid input!\n");
                return 1;
            }
        }
    }

    // Take inputs of the elements of the second matrix
    printf("Enter the elements of the matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("===> Enter element [%d] [%d]: ", i + 1, j + 1);
            if (scanf("%d", &arr2[i][j]) != 1) {
                printf("Invalid input!\n");
                return 1;
            }
        }
    }

    // Show the first matrix
    printf("==== Matrix 1 ====\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }

    // Show the second matrix
    printf("==== Matrix 2 ====\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }


    // Call matrix addition function
    matrix_addition(rows, cols, arr1, arr2, sum);

    // Print resultant matrix
    printf("The addition of 2 matrices is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
    // Free memory
    free(arr1);
    free(arr2);
    free(sum);

    return 0;
}