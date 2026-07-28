// 3517. Smallest Palindromic Rearrangement I
// You are given a palindromic string s.
// Return the lexicographically smallest palindromic permutation of s.

// Example 1:
// Input: s = "z"
// Output: "z"
// Explanation:

// A string of only one character is already the lexicographically smallest palindrome.

// Example 2:
// Input: s = "babab"
// Output: "abbba"
// Explanation:
// Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

// Example 3:
// Input: s = "daccad"
// Output: "acddca"
// Explanation:
// Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string getString(char ch, int c) {
        string s = "";
        for(int i = 0; i < c; i++) s += ch;
        return s;
    }
    string smallestPalindrome(string s) {
        int oddchar = -1;
        string res = "";
        vector<int>counter(26, 0);
        for (char ch: s) counter[ch - 'a']++;
        for(int i = 0; i < 26; i++) 
        {
            int count = counter[i];
            if (count == 0) continue;
            char ch = static_cast<char>(i + 97);
            if (count&1) {
                oddchar = i;
            }
            res += getString(ch, count/2);
        }
        string reversed = res;
        reverse(reversed.begin(), reversed.end());
        if (oddchar != -1) res.append(getString(static_cast<char>(oddchar + 97), 1));
        res.append(reversed);
        return res;
    }
};

int main() {
    string s = "";
    Solution sol;
    string res = ol.smallestPalindrome(s);
    cout << res << "\n";
    return 0;
}