#include "header.hpp"
class Solution
{
public:
    int jump2(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int res = 0;
        int current_jump_end = 0;
        int farthest = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == current_jump_end)
            {
                res++;
                current_jump_end = farthest;
            }
        }

        return res;
    };

    int jump(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        vector<int> curr = {0};
        vector<int> next = {};
        bitset<uint32_t(1e5)> mask;
        mask.reset();

        int res = 0;
        while (!curr.empty())
        {

            for (auto &elem : curr)
            {
                for (int i = 1; i <= nums[elem]; i++)
                {
                    if (!mask.test(elem + i))
                    {
                        next.push_back(elem + i);
                        mask.set(elem + i);
                    }
                    if ((elem + i) == (nums.size() - 1))
                        return res + 1;
                }
            }

            res++;
            curr = std::move(next);
            next.clear();
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 2, 1};
    cout << s.jump2(nums) << endl;
    return 0;
}