#include "header.hpp"
class Solution {
    int checkRecord(int n) {

        vector<int> dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;

        for(int i = 3; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000007;
        }
        long ans = dp[n];

        for(int i = 0; i < n; i++){
            ans += (long)dp[i] * dp[n-i-1];
            ans %= 1000000007;
        }

        return ans;   
    }

};