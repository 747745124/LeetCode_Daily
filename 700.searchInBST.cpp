#include "header.hpp"
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;
        return traversal(root, val);
    }
    TreeNode *traversal(TreeNode *cur, const int &val)
    {
        if (cur->val == val)
            return cur;

        while (cur != nullptr)
        {
            if (cur->left && cur->val > val)
                return traversal(cur->left, val);
            if (cur->right && cur->val < val)
                return traversal(cur->right, val);

            return nullptr;
        }

        return nullptr;
    }
};