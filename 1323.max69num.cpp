#include "header.hpp"
class Solution
{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (auto &ch : s)
        {
            if (ch == '6')
            {
                ch = '9';
                break;
            }
        }

        return stoi(s);
    }
};