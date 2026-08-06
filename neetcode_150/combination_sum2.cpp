// Combination Sum II
// You are given an array of integers candidates, which may contain duplicates, and a target integer target. Your task is to return a list of all unique combinations of candidates where the chosen numbers sum to target.
// Each element from candidates may be chosen at most once within a combination. The solution set must not contain duplicate combinations.
// You may return the combinations in any order and the order of the numbers in each combination can be in any order.

// Example 1:

// Input: candidates = [9,2,2,4,6,1,5], target = 8

// Output: [
//   [1,2,5],
//   [2,2,4],
//   [2,6]
// ]

// Combination Sum
// You are given an array of distinct integers nums and a target integer target. Your task is to return a list of all unique combinations of nums where the chosen numbers sum to target.
// The same number may be chosen from nums an unlimited number of times. Two combinations are the same if the frequency of each of the chosen numbers is the same, otherwise they are different.
// You may return the combinations in any order and the order of the numbers in each combination can be in any order.

// Example 1:
// Input:
// nums = [2,5,6,9]
// target = 9

// Output: [[2,2,5],[9]]
// Explanation:
// 2 + 2 + 5 = 9. We use 2 twice, and 5 once.
// 9 = 9. We use 9 once.

// Example 2:
// Input:
// nums = [3,4,5]
// target = 16
// Output: [[3,3,3,3,4],[3,3,5,5],[4,4,4,4],[3,4,4,5]]

// All elements of nums are distinct.
// 1 <= nums.length <= 20
// 2 <= nums[i] <= 30
// 2 <= target <= 30

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_vector(vector<T>&value) {
    for (auto it: value) cout << it << " ";
    cout << "\n";
}

class Solution {
private: 
    vector<vector<int>> result;
public:
    void findSubsets(vector<int>& nums, int target, int start, vector<int> &temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            if (target - nums[i] >= 0 ) {
                temp.push_back(nums[i]);
                findSubsets(nums, target - nums[i], i + 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        findSubsets(candidates, target, 0, temp);
        return result;
    }
};


int main() {
    vector<int> nums = {9, 2, 2, 4, 6, 1, 5};
    int target = 8;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum2(nums, target);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i]);
    }
    return 0;
}