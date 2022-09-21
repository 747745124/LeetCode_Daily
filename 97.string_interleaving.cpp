#include "header.hpp"
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        // edge case
        if (s1.length() == 0)
            return s2 == s3;
        if (s2.length() == 0)
            return s1 == s3;
        if ((s1.length() + s2.length()) != s3.length())
            return false;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        dp.shrink_to_fit();

        function<bool(int, int, int)> interleave = [&](int i, int j, int k)
        {
            bool res = false;
            // reach the end
            if (k == s3.length())
            {
                dp[i][j] = 1;
                return true;
            }
            if ((s3[k] != s1[i]) && (s3[k] != s2[j]))
            {
                dp[i][j] = 0;
                return false;
            }

            if (dp[i][j] != -1)
                return dp[i][j] == 1;

            if (s3[k] == s1[i] && s3[k] != s2[j])
                return interleave(i + 1, j, k + 1);
            if (s3[k] == s2[j] && s3[k] != s1[i])
                return interleave(i, j + 1, k + 1);

            if (s3[k] == s2[j] && s3[k] == s1[i])
            {
                res = interleave(i + 1, j, k + 1) || interleave(i, j + 1, k + 1);
            }

            dp[i][j] = res ? 1 : 0;
            return res;
        };

        return interleave(0, 0, 0);
    }
};

int main()
{
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    return 0;
}