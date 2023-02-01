#include "header.hpp"
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        // if they have gcd, they must be in the form of str*k times
        // str*p times
        if (str1 + str2 != str2 + str1)
            return "";

        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};