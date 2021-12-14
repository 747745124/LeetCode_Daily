#include "header.hpp"
//same as fibonacci
class Solution
{
public:
    int climbStairs(int n)
    {
        uint a = 1;
        uint b = 1;
        for (int i = 0; i < n; i++)
            tie(a, b) = make_tuples(b, a + b);
        return a;
    }
};