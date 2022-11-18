#include "header.hpp"
class Solution
{
public:
    int subarrayLCM(vector<int> &nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (k % nums[i] != 0)
                continue;
            int lcm = nums[i];
            for (int j = i; j < nums.size(); j++)
            {
                if (k % nums[j] != 0)
                    break;
                lcm = lcm * nums[j] / gcd(lcm, nums[j]);
                if (lcm == k)
                    count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 4, 12, 6, 3};
    cout << s.subarrayLCM(nums, 12) << endl;
}