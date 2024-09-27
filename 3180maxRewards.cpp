#include "header.hpp"
class Solution {
public:
    using arr_2 = vector<vector<int> >;
    arr_2 dp;
    int maxTotalReward(vector<int>& rewardValues) {
        //deduplicate the reward values
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique( rewardValues.begin(), rewardValues.end()), rewardValues.end());

        //dp[pos][sum] is the max total reward for a given state (defined by position, and current sum)
        dp = arr_2(2001,vector<int>(4000,-1));

        return helper(0,0,rewardValues);
    };

    int helper(int pos, int sum, const vector<int>& rewardValues) {

        if(dp[pos][sum]!=-1)
            return dp[pos][sum];
        if(pos == rewardValues.size()||sum > rewardValues.back())
            return sum;
        
        
        int res = sum;
        
        //if pick the current value
        if(rewardValues[pos] > sum)
        {   
            res = max(res, helper(pos+1,sum+rewardValues[pos],rewardValues));
        }

        //if not pick the current value
        res = max(res, helper(pos+1,sum,rewardValues));
        
        dp[pos][sum] = res;
        return res;
    }
};