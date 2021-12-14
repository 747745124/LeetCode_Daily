#include "header.hpp"
class Solution
{
public:
    // no division allowed, we generate a forward and backward multiplication array
    vector<int> productExceptSelf(vector<int> &nums)
    {
        //generate vector of prefix product
        vector<int> fwd(nums.size(), 1);
        //generate vector of suffix product
        vector<int> bwd(nums.size(), 1);
        //res = pre[i]*suf[i]
        vector<int> res;

        for (int i = 0; i < nums.size() - 1; i++)
        {

            fwd[i + 1] = nums[i] * fwd[i];
        }

        for (int i = nums.size() - 1; i > 0; i--)
        {

            bwd[i - 1] = bwd[i] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(bwd[i] * fwd[i]);
        }

        return res;
    }
};