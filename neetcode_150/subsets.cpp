// Subsets
// Given an array nums of unique integers, return all possible subsets of nums.
// The solution set must not contain duplicate subsets. You may return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [7]
// Output: [[],[7]]

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
    void generateSubsets(int start, vector<int>& nums, vector<int>& temp) {
        result.push_back(temp);
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            generateSubsets(i+1, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        generateSubsets(0, nums, temp);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> res = sol.subsets(nums);
    for (int i = 0; i < res.size(); i++) {
        print_vector(res[i]);
    }
    return 0;
}