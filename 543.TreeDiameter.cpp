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
    int diameterOfBinaryTree(TreeNode *root)
    {
        longestPath(root);
        return res;
    }
    //path length pass through the root, and at most one-side
    int longestPath(TreeNode *root)
    {
        if (!root)
            return -1;
        int l = longestPath(root->left) + 1;
        int r = longestPath(root->right) + 1;
        res = max(res, l + r);
        return max(l, r);
    }
};
