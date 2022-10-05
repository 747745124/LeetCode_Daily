#include "header.hpp"
class Solution
{
public:
    unordered_map<int, int> memo;

    int recursiveWithMemo(int index, string &str)
    {
        // Have we already seen this substring?
        if (memo.count(index))
        {
            return memo[index];
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length())
        {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0')
        {
            return 0;
        }

        if (index == str.length() - 1)
        {
            return 1;
        }

        int ans = recursiveWithMemo(index + 1, str);
        if (stoi(str.substr(index, 2)) <= 26)
        {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo[index] = ans;

        return ans;
    }

    int numDecodings(string s)
    {
        return recursiveWithMemo(0, s);
    }
};

class Solution2
{
public:
    int numDecodings(string s)
    {
        vector<int> zeros;
        for (int i = 0; i < s.size(); i++)
        {
            if (!zeros.empty() && s[i] == '0' && zeros.back() == (i - 1)) // consecutive 0s
                return 0;
            if (s[i] == '0')
                zeros.push_back(i);
        }

        if (!zeros.empty() && zeros[0] == 0)
            return 0; // initial zero

        // preprocess string
        for (const auto &zero_pos : zeros)
        {
            auto temp = s[zero_pos - 1];
            if ((temp - '0') >= 3)
                return 0;

            s.erase(zero_pos - 1, 2);    // 1201234 -> 1 1234
            s.insert(zero_pos - 1, " "); // 1+
        }

        // now that s is in standard form, we can process using dp now
        unordered_map<string, int> dp;
        vector<string> words = split(s, ' ');
        int res = 0;
        for (const auto &word : words)
        {
            res += helper(dp, word);
        }

        return res - words.size();
    }

    int helper(unordered_map<string, int> &dp, string s)
    {
        if (dp.count(s) != 0)
            return dp[s];

        int res = 0;

        if (s.size() <= 2)
        {
            if (s.size() == 1)
                res = 0;
            if (s.size() == 2 && stoi(s) > 26)
                res = 0;
            if (s.size() == 2 && stoi(s) <= 26)
                res = 1;

            dp[s] = res;
            return res;
        }

        for (int i = 2; i < s.size(); i++)
        {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            if (s2.size() == 1)
                res = helper(dp, s1);
            if (s2.size() == 2 && stoi(s) > 26)
                res = helper(dp, s1);
            if (s2.size() == 2 && stoi(s) < 26)
                res = helper(dp, s1) + 1;

            res += helper(dp, s1) + helper(dp, s2);
        }

        dp[s] = res;
        return res;
    };

    std::vector<std::string> split(const std::string &s, char delim)
    {
        std::stringstream ss(s);
        std::string item;
        std::vector<std::string> elems;
        while (std::getline(ss, item, delim))
        {
            elems.push_back(item);
            // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
        }
        return elems;
    }
};

int main()
{
    Solution solution;
    cout << solution.numDecodings("1201234");
}