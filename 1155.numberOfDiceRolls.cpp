#include "header.hpp"
class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> cache(n + 1, vector<int>(target + 1, -1));

        return helper(n, k, target, cache);
    }

    int helper(int n, int k, int target, vector<vector<int>> cache)
    {
        if (target < 0 || n < 0)
            return 0;
        if (cache[n][target] != -1)
            return cache[n][target];

        if (target == 0 && n > 0) // arrive early
            return cache[n][target] = 0;
        if (n == 0 && target > 0)
            return cache[n][target] = 0;

        if (target == 0 && n == 0)
            return cache[n][target] = 1;

        uint64_t res = 0;
        for (int i = 1; i <= k; i++)
        {
            res = (res % 1000000007 + helper(n - 1, k, target - i, cache) % 1000000007);
        }
        cache[n][target] = res;
        return (res % (1000000007));
    };
};

int main()
{

    Solution s;
    cout << s.numRollsToTarget(2, 6, 7) << endl;

    return 0;
}