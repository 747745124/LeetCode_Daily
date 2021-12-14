#include "header.hpp"
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon)
    {
        const auto &d = dungeon;
        const int m = dungeon.size();
        const int n = dungeon[0].size();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        // to reach the princess, you have to yield at least 1 hp
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int y = m - 1; y >= 0; y--)
        {
            for (int x = n - 1; x >= 0; x--)
            {

                dp[y][x] = min(1, min(dp[y + 1][x], dp[y][x + 1]) - dp[y][x]);
            }
        }

        return dp[0][0];
    }
};