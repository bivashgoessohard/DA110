#include <stdio.h>
#define n 9

int main() {
    int arr[n] = {2, 2, 2, 3, 3, 5, 1, 1, 1};
    int k = 0;
    int new[n];

    // Print Array
    // <TODO> Will implement later, not important

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if already exists
        for (int j = 0; j < k; j++) {
            if (arr[i] == new[j]) {
                found = 1;
                break;
            }
        }

        // Insert AFTER checking
        if (found == 0) {
            new[k] = arr[i];
            k++;
        }
    }

    // Print unique elements
    printf("====Array of Unique Elements====\n");
    printf("[");
    for (int i = 0; i < k; i++) {
        printf("%d", new[i]);
        if (i < k - 1) {
            printf(", ");
        } else {
            printf("]");
        }
    }
    printf("\n");

    printf("Total number of duplicate elements found in the array is : %d\n", n - k);

    return 0;
}