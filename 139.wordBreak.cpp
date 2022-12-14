#include "header.hpp"
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        vector<int> dp(n, -1);

        return isValid(s, wordDict, dp, 0);
    }

    bool isValid(string s, vector<string> &wordDict, vector<int> &dp, int index)
    {

        if (index == s.length())
            return true;
        if (index > s.length())
            return false;
        if (dp[index] != -1)
            return dp[index] == 1;

        bool flag = false;
        for (auto &word : wordDict)
        {
            if (s.substr(index, word.length()).find(word) == 0)
                flag = flag || isValid(s, wordDict, dp, index + word.length());
        }

        return dp[index] = flag;
    }
};

int main()
{
    Solution s;
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    cout << s.wordBreak("catsandog", wordDict) << endl;
    return 0;
}