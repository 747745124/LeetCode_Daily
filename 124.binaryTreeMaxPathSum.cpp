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
    int maxSum = INT32_MIN;
    int maxPathSum(TreeNode *root)
    {
        postOrder(root);
    }

    int postOrder(TreeNode *node)
    {
        int subtree = 0;
        if (node == nullptr)
            return 0;
        int left_gain = postOrder(node->left);
        int right_gain = postOrder(node->right);
        left_gain = (left_gain > 0) ? left_gain : 0;
        right_gain = (right_gain > 0) ? right_gain : 0;

        maxSum = max(maxSum, left_gain + right_gain + node->val);
        subtree = max(left_gain + node->val, right_gain + node->val);
        return subtree;
    }
};