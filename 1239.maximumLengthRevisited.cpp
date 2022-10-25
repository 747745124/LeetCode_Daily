#include "header.hpp"
class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        // valid string (in bit representation), strings that doesn't contain duplicate characters
        vector<int> a;
        for (const string &x : arr)
        {
            // bit representations of each string
            int mask = 0;
            for (const auto ch : x)
            {
                // bit representation
                mask |= 1 << (ch - 'a');
            }

            // if the char used != the length of string, it contains duplicate characters.
            // ignore the string
            if (__builtin_popcount(mask) != x.length())
                continue;

            a.push_back(mask);
        }

        int res = 0;

        function<void(int, int)> dfs = [&](int n, int mask)
        {
            res = max(__builtin_popcount(mask), res);
            for (int i = n; i < a.size(); i++)
            {
                if (__builtin_popcount(mask & a[i]) == 0) // there is no overlapping
                    dfs(i + 1, mask | a[i]);
            }
        };
        // go to combine with next element
        dfs(0, 0);
        return res;
    }
};