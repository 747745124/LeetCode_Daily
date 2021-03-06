#include "header.hpp"
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode *root, long mn, long mx)
    {
        if (!root)
            return true;
        if (root->val <= mn || root->val >= mx)
            return false;
        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
};
