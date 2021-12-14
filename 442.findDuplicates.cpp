#include "header.hpp"
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            //set the value of nums[i] to the index of nums[i] to negative
            //if is negative, it means it is already visited, so it's duplicate
            //nums[i] in [1,n], minus 1 to [0,n-1]
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0)
                ans.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = s.findDuplicates(nums);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}