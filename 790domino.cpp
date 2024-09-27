#include "header.hpp"
class Solution {
public:
    int numTilings(int n) {
        if(n==1)
            return 1;

        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[0] = {1,0};
        dp[1] = {2,1};
        for(int i=2;i<n;i++){
            dp[i][0] = dp[i-1][0] + dp[i-2][0] + 2*dp[i-1][1];
            dp[i][1] = dp[i-2][0] + dp[i-1][1];
        }

        return dp[n-1][0];
    }
};