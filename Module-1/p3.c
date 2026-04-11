/*
3. Write a program in C to find the sum of all elements of the array. 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, sum = 0, allocation_failed = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare an array of n elements
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Error: Memory allocation failed.");
        allocation_failed = 1; // set flag to handle error
        return 1;
    }

    // Take input
    for (int i = 0; i < n; i++) {
        printf("Enter element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Print array
    printf("====The array is====\n");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) {
            printf(", ");
        } else {
            printf("]");
        }
    }
    printf("\n");

    // Calculate sum of the elements
    for (int i = 0; i < n; i++) {
        sum = sum + arr[i];
    }

    printf("The sum of the elements of the array is: %d\n", sum);

    free(arr);

    return 0;
}