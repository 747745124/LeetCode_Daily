#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {

        vector<int> seq = {};
        dfs(nums, seq, 0);

        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &currSeq, int curr_index)
    {

        if (curr_index == nums.size())
        {
            if (currSeq.size() >= 2)
            {
                res.push_back(currSeq);
            }
            return;
        }

        if (currSeq.size() == 0 || currSeq.back() <= nums[curr_index])
        {
            currSeq.push_back(nums[curr_index]);
            dfs(nums, currSeq, curr_index + 1);
            currSeq.pop_back();
        }

        dfs(nums, currSeq, curr_index + 1);
    };
};