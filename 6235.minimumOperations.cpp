#include "header.hpp"
class Solution
{
public:
    int minimumOperations(TreeNode *root)
    {
        vector<TreeNode *> curr, next;
        vector<int> nums;
        curr.push_back(root);
        int res = 0;
        while (curr.size() > 0)
        {
            for (auto node : curr)
            {
                nums.push_back(node->val);
                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            }
            res += exchangeNumber(nums);
            curr = next;
            next.clear();
            nums.clear();
        }
    }

    int exchangeNumber(vector<int> &nums)
    {
        // calculate the least number of swaps to make the array sorted
        // code
        int res = 0;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> m;

        // value,index
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // if it's not in the sorted position,swap them
            if (nums[i] != sorted[i])
            {
                res++;
                // swap 2 indicies(m[sorted[i]] and i)
                int temp = nums[i];
                nums[i] = nums[m[sorted[i]]];
                nums[m[sorted[i]]] = temp;

                // // update position
                m[temp] = m[sorted[i]];
                m[nums[i]] = i;
            }
        }
        return res;
    };
};
