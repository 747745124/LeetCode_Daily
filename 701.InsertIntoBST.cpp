#include "header.hpp"
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        traversal(root, val);
        return root;
    }

    void traversal(TreeNode *cur, const int &val)
    {
        if (!cur->left && cur->val > val)
        {
            auto node = new TreeNode(val);
            cur->left = node;
            return;
        }
        if (!cur->right && cur->val < val)
        {
            auto node = new TreeNode(val);
            cur->right = node;
            return;
        }

        if (cur != nullptr)
        {
            if (cur->left && cur->val > val)
                return traversal(cur->left, val);
            if (cur->right && cur->val < val)
                return traversal(cur->right, val);
        }
    }
};