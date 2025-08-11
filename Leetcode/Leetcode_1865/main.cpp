// 1865. Finding Pairs With a Certain Sum
// You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:
// Add a positive integer to an element of a given index in the array nums2.
// Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs
{
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> countmap;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int it : nums2) {
            countmap[it]++;
        }
    }
    void add(int index, int val) {
        this->countmap[this->nums2[index]]--;
        this->nums2[index] += val;
        this->countmap[this->nums2[index]]++;
    }
    int count(int tot) {
        int count = 0;
        for (int it : this->nums1) {
            if (tot - it > 0 && this->countmap.find(tot - it) != this->countmap.end()) {
                count += this->countmap[tot - it];
            }
        }
        return count;
    }
};
int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 2, 4, 5, 6, 8, 9};
    FindSumPairs obj(nums1, nums2);
    obj.add(1, 1);
    cout << obj.count(6);
    cout << endl;
}