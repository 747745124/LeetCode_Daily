#include "header.hpp"
class Solution
{
public:
    int result = 0;
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        // define a helper function, getting the
        // largest and smallest ancestor along the path
        helper(root, root->val, root->val);
    }
    void helper(TreeNode *node, int max_val, int min_val)
    {
        if (node == nullptr)
            return;
        // update the result
        this->result = max(result, abs(max_val - node->val));
        this->result = max(result, abs(min_val - node->val));
        // update the max and min ancestor
        if (node->val > max_val)
            max_val = node->val;
        if (node->val < min_val)
            min_val = node->val;
        // recursion
        helper(node->left, max_val, min_val);
        helper(node->right, max_val, min_val);
    };
};