#include "header.hpp"

class Solution
{
public:
    constexpr int combo(int x)
    {
        return x * (x - 1) / 2;
    }

    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;

        int res = 0;
        vector<int> diff(nums.size() - 1, 0);
        // prefix diff
        for (int i = 0; i < nums.size() - 1; i++)
        {
            diff[i] = nums[i + 1] - nums[i];
        }

        for (int i = 0; i < diff.size() - 1; i++)
        {
            int count = 1;
            while (i + 1 < diff.size() && diff[i + 1] == diff[i])
            {
                count++;
                i++;
            }
            res += combo(count);
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 4, 6, 7, 8, 9};
    cout << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}