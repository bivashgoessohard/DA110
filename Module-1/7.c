/*
7. Write a program in C to count the frequency of each element of an array.
*/

#include <stdio.h>

int main() {
    int n; // number of elements for the array

    // Take inputs from the user
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n]; // Initialize array of elements "n"
    int visited[n]; // To track counted elements

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Input %d elements in the array :\n", n);

    // Take inputs of elements of the array
    for (int i = 0; i < n; i++) {
        printf("Element - %d: ", i);
        scanf("%d", &arr[i]);
    }


    // Count the frequency
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue; // Skip, already counted
        }

        int count = 1; // in inner loop j = i + 1, thus
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d occurs %d times.\n", arr[i], count);
    }
    return 0;
}