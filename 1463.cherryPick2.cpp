#include "header.hpp"
class Solution
{
    using triArr = vector<vector<vector<int>>>;
    int r = 0;
    int c = 0;

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        this->r = grid.size();
        this->c = grid[0].size();
        triArr dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return helper(0, 0, c - 1, grid, dp);
    }

    // used for recursion
    int helper(int y, int x1, int x2, vector<vector<int>> &grid, triArr &dp)
    {
        if (x1 < 0 || x1 >= c || x2 < 0 || x2 >= c || y >= r || y < 0)
        {
            return 0;
        }

        int ans = dp[y][x1][x2];

        if (ans != -1)
            return ans;

        bool isSame = x1 == x2;
        int cur = grid[y][x1] + (isSame ? 0 : grid[y][x2]);
        for (int d1 = -1; d1 <= 1; d1++)
        {
            for (int d2 = -1; d2 <= 1; d2++)
            {
                ans = max(ans, cur + helper(y + 1, x1 + d1, x2 + d2, grid, dp));
            }
        }

        dp[y][x1][x2] = ans;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1},
    };
    cout << s.cherryPickup(grid) << endl;
}