#include "header.hpp"
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        // dp[i][j] is the lcs of substring starting at i for text1,
        // and j for text2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = 0; i <= m; i++)
        {
            dp[i][n] = 0;
        }

        for (int i = 0; i <= n; i++)
        {
            dp[m][i] = 0;
        }

        return lcs(text1, text2, 0, 0, dp);
    }
    int lcs(string text1, string text2, int i, int j, vector<vector<int>> &dp)
    {
        int res = 0;
        if (i >= text1.size() || j >= text2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
            res = lcs(text1, text2, i + 1, j + 1, dp) + 1;
        else
            res = max(lcs(text1, text2, i + 1, j, dp), lcs(text1, text2, i, j + 1, dp));

        return dp[i][j] = res;
    }
};

int main()
{
    Solution s;
    cout << s.longestCommonSubsequence("abcde", "ace") << endl;
    cout << s.longestCommonSubsequence("abc", "abc") << endl;
    cout << s.longestCommonSubsequence("abc", "def") << endl;
    return 0;
}