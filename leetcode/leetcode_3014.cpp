// 3014. Minimum Number of Pushes to Type Word I

// You are given a string word containing distinct lowercase English letters.
// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.
// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int total = 0;
        vector<int>pushes(4, 0);
        vector<int>counter(26, 0);
        for (char ch: word) {
            int num = ch - 97;
            if (counter.at(num) == 0) {
                for(int j = 0; j < 4; j++) {
                    if (pushes[j] < 8) {
                        pushes[j] += 1;
                        counter[num] = j + 1;
                        break;
                    }
                }
            }
            total+= counter[num];
        }
        return total;
    }
};

int main() {
    string word = "awefgfdcjyukgyitkdjrstethrtcyutjyrhsnhfdgjctyj";
    Solution sol;
    cout << sol.minimumPushes(word) << "\n";
    return 0;
}