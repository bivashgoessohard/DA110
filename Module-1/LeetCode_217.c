/*
217. Contains Duplicate
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

#include <stdio.h>
#include <stdlib.h>
#define n 3

int main() {
    int nums[n] = {1, 2, 3};

    int hash[n+1] = {0};

    for (int i = 0; i < n; i++) {

        if (abs(hash[nums[i]]) == 1){
            printf("true\n");
            break;
            return 0;
        } else {
            hash[nums[i]] = 1;
        }
    }
    printf("false\n");
    return 0;
}


/*

// Better solution


#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}


*/