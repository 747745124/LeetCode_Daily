#include "header.hpp"
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string res;
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry)
            res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};