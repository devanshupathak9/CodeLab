// 215. Kth Largest Element in an Array
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> max_heap;
        for (int it : nums)
            max_heap.push(it);
        for (int i = 0; i < k - 1; i++)
            max_heap.pop(); 
        return max_heap.top();
    }
};

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 54, 23, 45, 76, 75, 5, 6};
    int k = 4;
    Solution sol;
    cout << sol.findKthLargest(nums, k) << endl;
}