#include "header.hpp"
class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long tmp = n;
        //there is problem with overflow
        long long tmp2 = 2 * tmp;
        return int64_t(sqrt(tmp2 + 0.25) - 0.5);
    }
};