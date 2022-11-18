#include "header.hpp"
class Solution
{
public:
    bool isPalindrome(string s, int i, int length) const
    {
        int k = 0;
        if ((i + length - 1) >= s.size())
            return false;

        while (k <= length / 2)
        {
            if (s[i + k] != s[i + length - k - 1])
                return false;
            k++;
        }
        return true;
    }
    int maxPalindromes(string s, int k)
    {
        int i = 0;
        int res = 0;
        while (i < s.size())
        {
            bool isK = isPalindrome(s, i, k);
            bool isK_1 = isPalindrome(s, i, k + 1);
            if (isK || isK_1)
            {
                i += isK ? k : k + 1;
                res++;
            }
            else
            {
                i++;
            }
        }

        return res;
        // start from the begining, check the coming k/k+1 is palinfrome
    };
};

int main()
{
    Solution s;
    cout << s.maxPalindromes("fttfjofpnpfydwdwdnns", 2) << endl;
}