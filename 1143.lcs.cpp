#include "header.hpp"
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        //initialize dp matrix with all zeros, a extra col and row for border
        vector<vector<int> > dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        //start from the last possible match position
        for (int i = text1.length() - 1; i >= 0; i--)
        {
            for (int j = text2.length() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    //if match, go diagonally back and plus one
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                { //if not match, go next position
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

int main()
{
    string str1 = "abcde";
    string str2 = "ace";
    Solution sol;
    cout << sol.longestCommonSubsequence(str1, str2);
    return 0;
}