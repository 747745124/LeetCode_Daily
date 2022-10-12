#include "header.hpp"

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), std::greater<int>());
        if (nums.size() < 3)
            return 0;

        int num0 = 0;
        int num1 = 1;
        int num2 = 2;

        while (num2 < nums.size())
        {
            if (nums[num0] < (nums[num1] + nums[num2]))
                return nums[num0] + nums[num1] + nums[num2];

            else
            {
                num0++;
                num1++;
                num2++;
            }
        }

        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 1, 2};
    cout << s.largestPerimeter(nums) << endl;
    return 0;
}