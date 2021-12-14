#include "header.hpp"
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        //initialize arrays for algo
        vector<int> dp(n, 1);
        vector<int> child(n, -1);

        int indexMax = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (1 + dp[j] > dp[i])
                    {
                        dp[i] = 1 + dp[j];
                        child[i] = j;
                    }
                }
            }

            if (dp[i] > dp[indexMax])
            {
                indexMax = i;
            }
        }

        vector<int> res;

        while (indexMax != -1)
        {
            res.push_back(nums[indexMax]);
            indexMax = child[indexMax];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> dp{1, 9, 2, 8, 4, 3};
    sol.largestDivisibleSubset(dp);
}