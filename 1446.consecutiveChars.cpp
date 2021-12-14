#include "header.hpp"
class Solution
{
public:
    int maxPower(string s)
    {
        // return the longest substring with consecutiveChars
        int maxPower = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            int thisPower = 0;
            while (s[i] == s[i + 1])
            {
                i++;
                thisPower++;
                maxPower = max(maxPower, thisPower);
            }
        }
        return maxPower + 1;
    }
};

int main()
{
    Solution solution;
    cout << solution.maxPower("leetcode");
}