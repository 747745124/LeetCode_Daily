#include "header.hpp"
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
        // dp[i][j] means the minimum falling path starts from grid[i][j]
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        for (int i = 0; i < n; i++)
        {
            solve(matrix, dp, 0, i);
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
    // calculate the minimum falling path at grid[i][j]
    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j)
    {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix.size())
            return INT32_MAX;

        if (dp[i][j] != INT32_MAX)
            return dp[i][j];

        int minSum = matrix[i][j] + min({solve(matrix, dp, i + 1, j), solve(matrix, dp, i + 1, j - 1), solve(matrix, dp, i + 1, j + 1)});
        return dp[i][j] = minSum;
    }
};

int main()
{
    Solution solution;
    cout << solution.minFallingPathSum({{2, 1, 3}, {6, 5, 4}, {7, 8, 9}});
}