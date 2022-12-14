#include "header.hpp"
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxres = 0;
        int curr = 0, prev = 0, seenZero = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                seenZero = 1;
                prev = curr;
                curr = 0;
            }
            else
            {
                curr++;
            }

            maxres = max({maxres, curr + prev + seenZero});
        }

        return maxres;
    }
};