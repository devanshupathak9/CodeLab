// 3310. Remove Methods From Project
// You are maintaining a project that has n methods numbered from 0 to n - 1.
// You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.
// There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
// A group of methods can only be removed if no method outside the group invokes any methods within it.
// Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

//  Example 1:
// Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
// Output: [0,1,2,3]
// Explanation:
// Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T> 
void print_vector(vector<T> &value) {
    for(auto val: value) cout << val << " ";
    cout << "\n";
}

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> graph(n);
        for (int i = 0; i < invocations.size(); i++) {
            int ai = invocations[i][0];
            int bi = invocations[i][1];
            graph[ai].push_back(bi);
        }

        queue<int>q;
        vector<bool> suspicious(n, false);
        suspicious[k] = true;
        q.push(k);
        while (q.size()) {
            int ai = q.front(); q.pop();
            for(int bi: graph[ai]) {
                if (!suspicious[bi]) {
                    suspicious[bi] = true;
                    q.push(bi);
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < invocations.size(); i++) {
            int ai = invocations[i][0];
            int bi = invocations[i][1];
            if (!suspicious[ai] && suspicious[bi]) {
                for (int i = 0; i < n; i++) res.push_back(i);
                return res;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) res.push_back(i);
        }
        return res;
    }
};

int main() {
    int n = 4;
    int k = 1;
    vector<vector<int>> invocations = {{1, 2}, {0, 1}, {3, 2}};
    Solution sol;
    vector<int> res = sol.remainingMethods(n, k, invocations);
    print_vector(res);
    return 0;
}