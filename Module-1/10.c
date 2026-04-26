#include <stdio.h>
#include <stdlib.h>

// Delete element function (returns 1 if success, 0 if invalid)
int delete_element(int position, int *arr, int size) {
    if (position < 1 || position > size) {
        return 0; // invalid position
    }

    // Main logic: Shift elements to the left
    for (int i = position; i < size; i++) {
        arr[i - 1] = arr[i];
    }

    return 1; // success
}

int main() {
    int n;

    // Take number of elements
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Allocate memory
    int *arr = malloc(n * sizeof *arr);
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input elements
    for (int i = 0; i < n; i++) {
        printf("Enter element %d (index %d): ", i + 1, i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input!\n");
            free(arr);
            return 1;
        }
    }

    // Print original array
    printf("====Original Array====\n");
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    int position;

    // Input position
    printf("Enter the position of the element to be deleted: ");
    if (scanf("%d", &position) != 1) {
        printf("Invalid input!\n");
        free(arr);
        return 1;
    }

    // Delete element
    if (!delete_element(position, arr, n)) {
        printf("Invalid position!\n");
        free(arr);
        return 1;
    }

    // Print modified array (size reduced by 1)
    printf("====Array (Modified)====\n");
    printf("[");
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free memory
    free(arr);

    return 0;
}