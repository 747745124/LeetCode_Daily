#include "header.hpp"
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I' && (i + 1 < s.length()) && s[i + 1] == 'V')
            {
                res += 4;
                i += 1;
                continue;
            }
            if (s[i] == 'I' && (i + 1 < s.length()) && s[i + 1] == 'X')
            {
                res += 9;
                i += 1;
                continue;
            }
            if (s[i] == 'X' && (i + 1 < s.length()) && s[i + 1] == 'L')
            {
                res += 40;
                i += 1;
                continue;
            }
            if (s[i] == 'X' && (i + 1 < s.length()) && s[i + 1] == 'C')
            {
                res += 90;
                i += 1;
                continue;
            }
            if (s[i] == 'C' && (i + 1 < s.length()) && s[i + 1] == 'D')
            {
                res += 400;
                i += 1;
                continue;
            }
            if (s[i] == 'C' && (i + 1 < s.length()) && s[i + 1] == 'M')
            {
                res += 900;
                i += 1;
                continue;
            }
            if (s[i] == 'I')
            {
                res += 1;
                continue;
            }
            if (s[i] == 'V')
            {
                res += 5;
                continue;
            }
            if (s[i] == 'X')
            {
                res += 10;
                continue;
            }
            if (s[i] == 'L')
            {
                res += 50;
                continue;
            }
            if (s[i] == 'C')
            {
                res += 100;
                continue;
            }
            if (s[i] == 'D')
            {
                res += 500;
                continue;
            }
            if (s[i] == 'M')
            {
                res += 1000;
                continue;
            }
        }
    }
};