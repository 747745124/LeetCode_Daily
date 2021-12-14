#include "header.hpp"
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums2.size();
        vector<int> res;
        for (const auto &num : nums1)
        {
            bool flag = false;
            auto idx = find(nums2.begin(), nums2.end(), num) - nums2.begin();
            for (int i = idx + 1; i < len; i++)
            {
                if (nums2[i] > num)
                {
                    res.push_back(nums2[i]);
                    flag = true;
                    break;
                }
            }

            if (!flag)
                res.push_back(-1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> res = s.nextGreaterElement(nums1, nums2);
    for (auto &num : res)
        cout << num << " ";
    cout << endl;
    return 0;
}