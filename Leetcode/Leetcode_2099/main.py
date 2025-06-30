"""
2099. Find Subsequence of Length K With the Largest Sum
You are given an integer array nums and an integer k.
You want to find a subsequence of nums of length k that has the largest sum.
Return any such subsequence as an integer array of length k.
A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.
"""

from typing import List
from heapq import heapify, heappop


class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        arr = []
        max_heap = [(-1 * nums[i], i) for i in range(len(nums))]
        heapify(max_heap)
        for i in range(k):
            top = heappop(nums)
            arr.append((top[1], -1 * top[0]))
        res = sorted(arr)
        return [val for _, val in res]

if __name__ == "__main__":
    sol = Solution()
    result = sol.maxSubsequence([2, 9, -1, 5, 2, 7], 3)
    print(result)
