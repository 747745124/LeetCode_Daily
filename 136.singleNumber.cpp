#include "header.hpp"
// after xor, same number becomes the original one
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (const auto &num : nums)
        {
            res = res ^ num;
        }
        return res;
    }
};