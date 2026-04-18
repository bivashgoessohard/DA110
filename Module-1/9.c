/*
Write a program in C to separate odd and even integers into separate arrays.
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

    // Declare 2 more arrays to save odd and even integers separately
    int odd[n], oddCount = 0;
    int even[n], evenCount = 0;

        // Main logic
    
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0) {
                even[evenCount++] = arr[i];
            } else {
                odd[oddCount++] = arr[i];
            }
        }

        // Print odd elements
    
        printf("The odd elements are:\n");
        for (int i = 0; i < oddCount; i++) {
            printf("%d ", odd[i]);
        }
    
        printf("\n");
    
        // Print even elements
        printf("The even elements are:\n");
        for (int i = 0; i < evenCount; i++) {
            printf("%d ", even[i]);
        }
    
        printf("\n");
    
        return 0;
    }