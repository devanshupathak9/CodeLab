// 3718. Smallest Missing Multiple of K
// Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
// A multiple of k is any positive integer divisible by k.

// Example 1:
// Input: nums = [8,2,3,4,6], k = 
// Output: 10
// Explanation:
// The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

#include <stdio.h>

int missingMultiple(int* nums, int numsSize, int k) {
    char seen[10000] = {0};
    for (int i = 0; i < numsSize; i++) {
        int num = *(nums + i);
        seen[num] = 1;
    }
    int x = 0;
    while (1) {
        x = x + k;
        if (seen[x] == 0) return x;
    }
    return -1;
}

int main() {
    int nums[] = {27, 3, 56, 6, 76, 9, 12, 15, 19};
    int numsSize = sizeof(nums)/sizeof(int);
    int k = 3;
    int ans = missingMultiple(nums, numsSize, k);
    printf("%d\n", ans);
}