/*
LeetCode 442: Find All Duplicates in an Array
assume element appears only once or twice
*/

// Brute-force solution Time complexity = O(n²)

#include <stdio.h>
#define n 8

int main() {
    int nums[n] = {4,3,2,7,8,2,3,1};

    // a new array contains nothing
    int duplicate[n];
    int k = 0;


    // for every element in nums check, match with other elements of nums by creating inner for loop
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate == 1) {
            duplicate[k] = nums[i];
            k++;
        }
    }
    

    for (int i = 0; i < k; i++) {
        printf("%d ", duplicate[i]);
    }
    printf("\n");

    return 0;

}