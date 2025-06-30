#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_value = 0;
        int pair_sum;
        vector<int>array;
        for(int i=0; i<values.size(); i++){
            pair_sum = values.at(i) + i;
            if (pair_sum > max_value){
                max_value = pair_sum;
                array.push_back(max_value);
            }
            else{array.push_back(max_value);}
        }
        int max_score = 0;
        for (int i=values.size()-1; i>0; i--){
            pair_sum = values.at(i) - i;
            if (pair_sum + array.at(i-1)>max_score){
                max_score = pair_sum + array.at(i-1);
            }
        }
        return max_score;
    }
};
int main(){
    Solution Sol;
    vector<int> vec1 = {8,1,5,2,6};
    vector<int> vec2 = {1,2};
    cout << Sol.maxScoreSightseeingPair(vec1) << endl;
    cout << Sol.maxScoreSightseeingPair(vec2) << endl;
}