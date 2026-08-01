// 3016. Minimum Number of Pushes to Type Word II
// You are given a string word containing lowercase English letters.

// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.
// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int>umap;
        for(char ch: word) {
            umap[ch - 97] += 1;
        }
        int total = 0;
        vector<int> counter(26, 0);
        vector<int> pushes = {0, 0, 0,0 };
        priority_queue<pair<int, int>> max_pq;

        for (int i = 0; i < 26; i++) {
            max_pq.push(make_pair(umap[i], i));
        }
        while (max_pq.size()) {
            pair<int, int> top = max_pq.top(); 
            max_pq.pop();
            if (counter[top.second] == 0) {
                for (int i = 0; i < 4; i++) {
                    if (pushes[i] < 8) {
                        pushes[i] += 1;
                        counter[top.second] = i + 1;
                        break;
                    }
                }
                total += top.first*(counter[top.second]);
            }
        }
        return total;
    }
};


int main() {
    string word = "aabbccddeeffgghhiiiiii";
    Solution Sol;
    int ans = Sol.minimumPushes(word);
    cout << ans << "\n";
    return 0;
}