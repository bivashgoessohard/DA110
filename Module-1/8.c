/*
8. Write a program in C to find the maximum and minimum elements in an array.
*/

#include <stdio.h>

int main() {
    int n;

    // Take input of number of elements of array from the user
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];
    
    // Take inputs of elements of the array
    for (int i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    int max = arr[0]; // for storing maximum value
    int min = arr[0]; // for storing minimum value


    // Calculate maximum element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate minimum element
    for (int i = 1; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }

    printf("Maximum element is %d.\n", max);
    printf("Minimum element is %d.\n", min);

    return 0;
}