#include "header.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int res = 0;
    int maxAncestorDiff(TreeNode *root)
    {

        // calculate the min max value along the path
        // using preorder to ensure
        helper(root, INT32_MAX, 0);
        return res;
    }

    void helper(TreeNode *node, int min_val, int max_val)
    {
        if (node == nullptr)
            return;

        min_val = min(min_val, node->val);
        max_val = max(max_val, node->val);
        res = max(abs(max_val - min_val), res);

        helper(node->left, min_val, max_val);
        helper(node->right, min_val, max_val);
        return;
    }
};