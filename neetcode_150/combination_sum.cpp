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
            if (target - nums[i] >= 0) {
                temp.push_back(nums[i]);
                findSubsets(nums, target - nums[i], i, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        findSubsets(nums, target, 0, temp);
        return result;
    }
};


int main() {
    vector<int> nums = {3, 4, 5};
    int target = 16;
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i]);
    }
    return 0;
}