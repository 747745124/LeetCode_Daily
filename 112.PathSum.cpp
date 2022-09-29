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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;
        return traversal(root, targetSum - root->val);
    }

    bool traversal(TreeNode *cur, int count)
    {
        // end case
        if (!cur->left && !cur->right && count == 0)
            return true; // leafnode and get to target
        if (!cur->left && !cur->right)
            return false; // no suitable pathSum

        if (cur->left)
        {                            // 左
            count -= cur->left->val; // 递归，处理节点;
            if (traversal(cur->left, count))
                return true;
            count += cur->left->val; // 回溯，撤销处理结果
        }

        if (cur->right)
        { // 右
            count -= cur->right->val;
            if (traversal(cur->right, count))
                return true;
            count += cur->right->val;
        }

        return false;
    }
};