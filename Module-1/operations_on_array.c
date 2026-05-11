/*
Basic Array Operations:
1. Input Array
2. Print Array
3. Insert Element
4. Delete Element
*/

#include <stdio.h>
#include <stdlib.h>


// ================= INPUT ARRAY =================

void input_array(int *arr, size_t size) {

    for (size_t i = 0; i < size; i++) {

        printf("Enter element %zu: ", i + 1);
        scanf("%d", &arr[i]);
    }
}


// ================= PRINT ARRAY =================

void print_array(const int *arr, size_t size) {

    printf("[");

    for (size_t i = 0; i < size; i++) {

        printf("%d", arr[i]);

        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}


// ================= INSERT FUNCTION =================

int* insert_element(int *arr,
                    size_t *size,
                    size_t position,
                    int element) {

    // Validate position
    if (position < 1 || position > (*size + 1)) {

        fprintf(stderr, "Invalid insert position!\n");
        return arr;
    }

    // Reallocate memory
    int *tmp = realloc(arr, (*size + 1) * sizeof(int));

    if (tmp == NULL) {

        fprintf(stderr, "Memory allocation failed!\n");
        return arr;
    }

    arr = tmp;

    // Shift elements right
    for (size_t i = *size; i > position - 1; i--) {

        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[position - 1] = element;

    // Update size
    (*size)++;

    return arr;
}


// ================= DELETE FUNCTION =================

int* delete_element(int *arr,
                    size_t *size,
                    size_t position) {

    // Check empty array
    if (*size == 0) {

        fprintf(stderr, "Array is empty!\n");
        return arr;
    }

    // Validate position
    if (position < 1 || position > *size) {

        fprintf(stderr, "Invalid delete position!\n");
        return arr;
    }

    // Shift elements left
    for (size_t i = position - 1; i < *size - 1; i++) {

        arr[i] = arr[i + 1];
    }

    // Decrease logical size
    (*size)--;

    // If array becomes empty
    if (*size == 0) {

        free(arr);
        return NULL;
    }

    // Shrink memory
    int *tmp = realloc(arr, (*size) * sizeof(int));

    if (tmp == NULL) {

        fprintf(stderr, "Memory reallocation failed!\n");
        return arr;
    }

    arr = tmp;

    return arr;
}


// ================= MAIN FUNCTION =================

int main(void) {

    size_t n;

    // Input size
    printf("Enter size of array: ");

    if (scanf("%zu", &n) != 1) {

        printf("Invalid input!\n");
        return 1;
    }

    // Allocate memory
    int *arr = malloc(n * sizeof(int));

    if (arr == NULL) {

        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements
    input_array(arr, n);

    printf("\nOriginal Array: ");
    print_array(arr, n);


    // ===== INSERT OPERATION =====

    int element;
    size_t position;

    printf("\nEnter element to insert: ");
    scanf("%d", &element);

    printf("Enter insert position: ");
    scanf("%zu", &position);

    arr = insert_element(arr, &n, position, element);

    printf("\nArray after insertion: ");
    print_array(arr, n);


    // ===== DELETE OPERATION =====

    printf("\nEnter delete position: ");
    scanf("%zu", &position);

    arr = delete_element(arr, &n, position);

    printf("\nArray after deletion: ");

    if (arr != NULL) {
        print_array(arr, n);
    } else {
        printf("[]\n");
    }

    // Free memory
    free(arr);

    return 0;
}