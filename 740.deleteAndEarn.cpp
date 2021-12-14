#include "header.hpp"
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int maxElem = *max_element(nums.begin(), nums.end());
        vector<int> house(maxElem, 0);
        for (const auto &num : nums)
        {
            int times = count(nums.begin(), nums.end(), num);
            house[num - 1] = times * num;
        }

        vector<int> dp(maxElem);
        if (maxElem < 2)
            return nums[0];
        dp[0] = house[0];
        dp[1] = max(house[0], house[1]);

        for (int i = 2; i < house.size(); i++)
        {
            dp[i] = max(dp[i - 2] + house[i], dp[i - 1]);
        }

        return dp[maxElem - 1];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    cout << s.deleteAndEarn(nums) << endl;
    return 0;
}