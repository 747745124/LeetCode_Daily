#include "header.hpp"
class Solution
{
public:
    string makeGood(string s)
    {
        deque<char> deq;
        for (const auto &ch : s)
        {
            if (!deq.empty() && tolower(deq.back(), locale()) == tolower(ch, locale()) && deq.back() != ch)
            {
                deq.pop_back();
                continue;
            }

            deq.push_back(ch);
        }

        string res = "";

        for (const auto &ch : deq)
        {
            res += ch;
        }

        return res;
    }
};