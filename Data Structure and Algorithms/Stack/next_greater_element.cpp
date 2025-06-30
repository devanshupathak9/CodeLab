#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> next_greater_element(vector<int> &nums)
    {
        stack<int> s;
        vector<int> result;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i]){
                s.pop();
            }
            if (s.empty())
                result.push_back(-1);
            else
                result.push_back(s.top());
            s.push(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    vector<int> arr = {2, 1, 3, 4, 1, 2, 7, 3, 4};
    Solution sol;
    auto res = sol.next_greater_element(arr);
    for (auto &it : res)
    {
        cout << it << " ";
    }
    cout << endl;
}