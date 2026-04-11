/* 
1. Write a program in C to store elements in an array and print them.
*/

#include <stdio.h>
#define n 10

int main(){
    int arr[n];

    // Take input
    printf("Enter 10 number of digits: \n");
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

    return 0;

}