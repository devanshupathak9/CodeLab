// Leetcode 56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the non-overlapping intervals that 
// cover all the intervals in the input.

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        stack<pair<int, int>>interval;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        interval.push(make_pair(intervals[0][0], intervals[0][1]));
        for (int i = 1; i < intervals.size(); i++){

        }

    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto res = sol.merge(intervals);
    for(auto it: res){
        cout << it[0] << it[1] <<"\n";
    }
    cout << endl;
}
