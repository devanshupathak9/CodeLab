// 53. Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum, 
// and return its sum.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size(), value, total = 0;
            int max_subarray = -100000;
            for(int i = 0; i < n; i++){
                value = nums.at(i);
                total = total + value;
                if (value > total)
                    total = value;
                max_subarray = max(max_subarray, total);
            }
            return max_subarray;
        }
    };

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    auto res = sol.maxSubArray(nums);
    cout << res << endl;
}
