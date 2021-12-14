#include "header.hpp"
class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int> > res;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> presences;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (presences[-nums[i] - nums[j]] > 0)
                {
                    res.insert({nums[i], nums[j], -nums[i] - nums[j]});
                }
                presences[nums[j]] = j;
            }
        }

        return vector<vector<int> >(res.begin(), res.end());
    }

    vector<vector<int> > threeSumVer2(vector<int> &nums)
    {
        vector<vector<int> > res;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> presences;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (presences[-nums[i] - nums[j]] > 0)
                {
                    vector<int> temp{nums[i], nums[j], -nums[i] - nums[j]};
                    sort(temp.begin(), temp.end());
                    if (std::find(res.begin(), res.end(), temp) == res.end())
                        res.push_back(temp);
                }
                presences[nums[j]] = j;
            }
        }

        return res;
    }
};

int main()
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution sol;
    cout << sol.threeSum(nums).size() << endl;
    return 0;
}