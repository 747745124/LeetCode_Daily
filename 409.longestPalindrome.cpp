#include "header.hpp"
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_set<char> chs;
        for (int i = 0; i < s.length(); i++)
        {
            chs.insert(s[i]);
        }

        bool plusOne = false;
        int res = 0;
        for (const auto &ch : chs)
        {
            int num = count(s.begin(), s.end(), ch);
            if (num == 1)
                plusOne = true;
            if (num % 2 == 1)
            {
                plusOne = true;
                num -= 1;
            }
            res += num;
        }
        return (plusOne) ? (res + 1) : res;
    }
};

int main()
{
    Solution s;
    string str = "abccccdd";
    cout << s.longestPalindrome(str) << endl;
    return 0;
}