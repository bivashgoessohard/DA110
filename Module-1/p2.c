/* 
2. Write a program in C to read n number of values in an array and display them in
reverse order.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, allocation_failed = 0;

    // Take input of number of elements of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Declare an array of size of 'n'
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Error: Memory allocation failed.");
        allocation_failed = 1; // set flag to handle error
        return 1;
    }

    // Take input
    printf("Enter %d number of digits: \n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Print arr
    printf("=====The array is=====\n");
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

    // Print array in reverse order
    printf("=====The array in reverse order=====\n");
    printf("[");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) {
            printf(", ");
        } else {
            printf("]");
        }
    }
    printf("\n");

    free(arr);

    return 0;

}