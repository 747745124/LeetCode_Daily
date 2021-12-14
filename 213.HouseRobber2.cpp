#include "header.hpp"
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dpFromZero;
        vector<int> dpFromOne;

        dpFromZero.push_back(nums[0]);
        dpFromZero.push_back(max(nums[0], nums[1]));

        dpFromOne.push_back(nums[1]);
        dpFromOne.push_back(max(nums[1], nums[2]));

        for (int i = 2; i < nums.size() - 1; i++)
        {
            dpFromZero.push_back(max(dpFromZero[i - 2] + nums[i], dpFromZero[i - 1]));
        }

        for (int i = 2; i < nums.size() - 1; i++)
        {
            dpFromOne.push_back(max(dpFromOne[i - 2] + nums[i + 1], dpFromOne[i - 1]));
        }

        return max(dpFromZero.back(), dpFromOne.back());
    }
};

int main()
{
    Solution solution;
    vector<int> m{1, 2, 1, 1};
    cout << solution.rob(m);
}