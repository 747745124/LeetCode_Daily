#include "header.hpp"
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
            return false;

        while (n != 0)
        {
            if (n == 1)
                return true;
            if (n % 4 != 0)
                return false;
            n = n << 2;
        }

        return false;
    }
};