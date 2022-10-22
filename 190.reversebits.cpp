#include "header.hpp"
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        bitset<32> res = n;
        string s = res.to_string();
        reverse(s.begin(), s.end());
        res = bitset<32>(s);

        return res.to_ulong();
    }
};