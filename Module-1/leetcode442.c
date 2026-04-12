/*
LeetCode 442: Find All Duplicates in an Array
assume element appears only once or twice
*/

// Hashing solution Time complexity = O(n), Space = O(n)

#include <stdio.h>
#define n 8

int main() {
    int nums[n] = {4,3,2,7,8,2,3,1};

    // a new array contains nothing
    int hash[n+1] = {0};
    
    for (int i = 0; i < n; i++) {
        hash[nums[i]]++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", hash[i]);
    }
     printf("\n");

    for (int i = 0; i <= n; i++) {
        if (hash[i] > 1) {
            printf("%d ", i);
        }
    }
    
    printf("\n");

    return 0;

}