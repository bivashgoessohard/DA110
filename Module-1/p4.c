/*
4. Write a program in C to copy the elements of one array into another array.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int allocation_failed = 0;

    // Take number of input elements from user
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    // Inialize an array of size of 'n'
    int *arr1 = (int *)malloc(n * sizeof(int));

    if (arr1 == NULL) {
        printf("Error: Memory allocation failed!\n");
        allocation_failed = 1; // Set flag to prevent segmentation flag for larger programs hence, not crash
        return 1; // Exit or handle error
    }

    // Initialize another array of size of 'n' where the elements will be copied
    int *arr2 = (int *)malloc(n * sizeof(int));
    
    // Take input from user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &arr1[i]);
    }

    // Print array 1
    printf("====Array 1====\n");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr1[i]);
        if (i < n-1) {
            printf(", ");
        } else {
            printf("]");
        }
    }

    printf("\n");

    // Copy elements of Array 1 into Array 2
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }

    // Print array 2
    printf("The elements of Array 1 has been successfully copied into Array 2.\n");
    printf("====Array 2====\n");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr2[i]);
        if (i < n-1) {
            printf(", ");
        } else {
            printf("]");
        }
    }
    printf("\n");

    // Free Memory
    free(arr1);
    free(arr2);

    return 0;
}