/*
14. Write a program in C to calculate the determinant of a 3 x 3 matrix.
*/

#include <stdio.h>
#include <stdlib.h>

int calculate_determinant(size_t n, int a[n][n]) {
    int determinant = ((a[0][0] * (a[1][1] * a[2][2] - a[2][1] * a[1][2])) + (a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2])) - (a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1])));
    return determinant;
}

// Read matrix function
int read_matrix (size_t n, int arr[n][n]) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("Enter element - [%zu][%zu]: ", i + 1, j + 1);
            if (scanf("%d", &arr[i][j]) != 1) {
                fprintf(stderr, "Invalid input!\n");
                return 0;
            }
        }
    }
    return 1;
}

// Print matrix function
void print_matrix(size_t n, int arr[n][n]) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    size_t n = 3;


    // Dynamically allocate memory
    int (*arr)[n] = malloc(n * sizeof *arr);

    // Memory allocation validation
    if (!arr) {
        fprintf(stderr, "Memory allocation failed!\n");
        free(arr);
        return EXIT_FAILURE;
    }

    // Call read matrix function
    printf("Input the matrix:\n");
    read_matrix(n, arr);

    // Show matrix
    puts("==== Matrix =====");
    print_matrix(n, arr);

    // Call determinant function
    int determinant = calculate_determinant(n, arr);

    printf("The determinant of the matrix is: %d\n", determinant);

    free(arr);
    
    return EXIT_SUCCESS;

}
