// Leetcode 2099. Find Subsequence of Length K With the Largest Sum:
// You are given an integer array nums and an integer k.
// You want to find a subsequence of nums of length k that has the largest sum.
// Return any such subsequence as an integer array of length k.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> max_heap;
        vector<pair<int, int>> elements;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            max_heap.push(make_pair(nums[i], i));
        }
        for (int count = 0; count < k; count++)
        {
            auto top = max_heap.top();
            elements.push_back({top.second, top.first});
            max_heap.pop();
        }
        sort(elements.begin(), elements.end());
        for (auto &it : elements)
        {
            res.push_back(it.second);
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {8, -1, 3, 4, -6, 8, 12};
    int k = 3;
    Solution sol;
    vector<int> res = sol.maxSubsequence(nums, k);
    for (auto &it : res)
    {
        cout << it << " ";
    }
    cout << endl;
}