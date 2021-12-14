#include "header.hpp"
class Solution
{
public:
    string longestPalindrome(string s)
    {

        //get length of longest palindrome centered at i
        auto getLen = [&](int i, int j)
        {
            while (i >= 0 && j < s.size() && s[i] == s[j])
            {
                i--;
                j++;
            }
            return j - i - 1;
        };

        int start = 0;
        int end = s.size() - 1;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int len = max(getLen(i, i), getLen(i, i + 1));
            if (len > maxLen)
            {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
};