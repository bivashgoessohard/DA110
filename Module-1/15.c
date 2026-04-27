/*
15. Write a program in C to accept a matrix and determine whether it is a sparse
matrix.
*/

#include <stdio.h>
#include <stdlib.h>


// Read matrix
int read_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf(">> Enter element - [%zu][%zu]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
    }
    return 1;
}

// Print matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Determine wheather sparse 
int if_sparse(int rows, int cols, int matrix[rows][cols]) {
    int element_count = rows * cols;
    int is_even = 0;

    if (element_count % 2 == 0) {
        is_even = 1;
    }

    int zero_count = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zero_count++;
            }
        }
    }
    if (is_even) {
        if (zero_count >= ((element_count / 2) + 1)) {
            return 1;
        } else {
            return 0;
        }
    }
    else {
        if (zero_count > (element_count / 2)) {
            return 1;
        } else {
            return 0;
        }
    }
}

// Main function
int main(void) {
    size_t rows, cols;

    // Take inputs of the number of rows and columns
    printf("Enter the number of Rows: ");
    if (scanf("%zu", &rows) != 1 || rows < 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    printf("Enter the number of Columns: ");
    if (scanf("%zu", &cols) != 1 || cols < 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    // Allocate memory
    int (*arr)[cols] = malloc(rows * sizeof *arr);

    // Validate memory
    if (!arr) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Read matrix funtion
    if (!read_matrix(rows, cols, arr)) {
        fprintf(stderr, "Invalid input!\n");
        free(arr);
        return EXIT_FAILURE;
    }

    // Print matrix
    printf("=== Matrix (%zu x %zu) ===\n", rows, cols);
    print_matrix(rows, cols, arr);

    // Call sparse function
    if (if_sparse(rows, cols, arr)) {
        puts("The given matrix is sparse matrix!");
    } else {
        puts(">>> Result: The given matrix is NOT sparse matrix!");
    }

    free(arr);

    return EXIT_SUCCESS;

}

