#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return {};

        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if ((i > 0) && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k)
            {
                int t = -nums[j] - nums[k];
                if (t > nums[i]) // t has to be smaller, move k
                    j++;
                else if (t < nums[i]) // t has to be greater
                    k--;
                else // find the Answer
                {
                    // deduplicate

                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, -1, -1, 0};
    vector<vector<int>> res = s.threeSum(nums);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}