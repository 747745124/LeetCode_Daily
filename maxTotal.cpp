#include "header.hpp"
// You are given an integer array rewardValues of length n, representing the values of rewards.

// Initially, your total reward x is 0, and all indices are unmarked. You are allowed to perform the following operation any number of times:

// Choose an unmarked index i from the range [0, n - 1].
// If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x (i.e., x = x + rewardValues[i]), and mark the index i.
// Return an integer denoting the maximum total reward you can collect by performing the operations optimally.

class Solution {
public:
    int maxRewards = 0;
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        for(int i = 0; i < n; i++){
            vector<bool> marked(n, false);
            int rewards = 0;
            for(int j = i; j < n; j++){
                if(rewardValues[j] > rewards){
                    rewards += rewardValues[j];
                    marked[j] = true;
                }
            }
            
            maxRewards = max(maxRewards, rewards);
        }
    }

};

int main(){
    Solution s;
    vector<int> rewardValues = {1,6,4,3,2};
    cout << s.maxTotalReward(rewardValues) << endl;
};