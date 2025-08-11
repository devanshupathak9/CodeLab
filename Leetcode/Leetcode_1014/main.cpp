// 1014. Best Sightseeing Pair
// You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
// The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
// Return the maximum score of a pair of sightseeing spots.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int res = -100000;
        int max_value = 0;
        int max_diff_value = -100000;
        vector<int> sum_value;
        for (int i = 0; i < values.size(); i++) {
            max_value = max(max_value, values[i] + i);
            sum_value.push_back(max_value);
        }
        for (int i = values.size() - 1; i > 0; i--) {
            max_diff_value = max(max_diff_value, values[i] - i);
            res = max(res, sum_value[i - 1] + max_diff_value);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> values = {8, 1, 5, 2, 6};
    cout << sol.maxScoreSightseeingPair(values) << endl;
}