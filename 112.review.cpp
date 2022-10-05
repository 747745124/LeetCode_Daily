#include "header.hpp"
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return traversal(root, targetSum - root->val);
    }

    bool traversal(TreeNode *curr, int val)
    {
        if (val < 0)
            return false;
        if (!curr->left && !curr->right && val == 0)
            return true;
        if (!curr->left && !curr->right && val != 0)
            return false;

        auto res = false;

        if (curr->left && traversal(curr->left, val - curr->left->val))
        {
            res = true;
        }
        if (curr->right && traversal(curr->left, val - curr->right->val))
        {
            res = true;
        }

        return res;
    }
};