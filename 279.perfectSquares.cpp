#include "header.hpp"
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int target = 1; target <= n; ++target)
        {
            for (int j = 1; j <= target; j++)
            {
                int square = j * j;
                if (target - square < 0)
                    break;
                dp[target] = min(dp[target], 1 + dp[target - square]);
            }
        }
        return dp[n];
    }
};
int main()
{
}