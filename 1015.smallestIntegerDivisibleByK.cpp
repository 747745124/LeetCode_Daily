#include "header.hpp"
class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        int remainder = 1;
        int length_N = 1;
        /*
        problem: check if there's no loop
        if N is seen
        */
        unordered_set<int> seen;

        /*
        1. check if N exists
        2. find out length(N)
        Remainder = N mod K
        N mod K = Remainder mod K
        (N*10+1) mod K = ((N mod K)*10 + 1 )mod K

        caveats: (a*b)mod p = (a mod p * b mod p) mod p

        so we can use the remainder instead of using N
        */
        while (remainder % k != 0)
        {
            remainder = (remainder * 10 + 1) % k;
            // if has seen
            if (seen.find(remainder) != seen.end())
                return -1;
            seen.insert(remainder);
            length_N++;
        }

        return length_N;
    }
};

int main()
{
    Solution sol;
    sol.smallestRepunitDivByK(3);
    return 0;
}