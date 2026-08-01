// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
print_vector(vector<T> &value) {
    for(auto val: value) {
        cout << val << " ";
    }
    cout << "\n";
}

class Solution {
private:
    vector<string> digitToLetters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
public:
    void backtrack(string digits, int pos, vector<char> current) {
        if (pos >= digits.size()) {
            string str;
            for(char ch: current) str += ch;
            result.push_back(str); return;
        }
        int index = digits[pos] - '0';
        for (char ch : digitToLetters[index]) {
            current.push_back(ch);
            backtrack(digits, pos + 1, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<char> current = {};  
        backtrack(digits, 0, current);
        return result;
    }
};

int main()
{
    Solution Sol;
    vector<string> res = Sol.letterCombinations("243");
    print_vector(res);
    return 0;
}