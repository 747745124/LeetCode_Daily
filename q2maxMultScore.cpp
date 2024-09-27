#include "header.hpp"
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<vector<int64_t>> dp(5, vector<int64_t>(n+1, INT64_MIN));
        //dp[i][j] represents the maximum score we can get from the first j elements of b, with i elements of a
        for(int i = 0; i <= 4; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;

        for(int i = 1; i <= 4; i++) {
            for(int j = 1; j <= n; j++) {
                //either we don't take the jth element of b, or we take it
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + a[i-1]*b[j-1]);
            }
        }

        return dp[4][n];
    }
};

int main(){
    Solution s;
    vector<int> a = {3,2,5,6};
    vector<int> b = {2,-6,4,-5,-3,2,-7};
    cout << s.maxScore(a, b) << endl;
    return 0;
}