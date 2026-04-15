/*
Write a program in C to print all unique elements in an array.
*/


#include <stdio.h>

int main() {
    int n;

    // Input number of elements
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Input %d elements in the array:\n", n);
    for(int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Find and print unique elements
    printf("\nThe unique elements found in the array are:\n");

    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        if(count == 1) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}