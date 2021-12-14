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
    int sumOfLeftLeaves(TreeNode *root)
    {
        return helper(root, 0);
    }

private:
    int helper(TreeNode *node, int curSum)
    {
        if (node == nullptr)
            return curSum;
        if (node->left != nullptr && isLeaf(node->left))
            return helper(node->right, curSum + node->left->val);
        else if (node->left && node->right)
            return helper(node->left, curSum) + helper(node->right, curSum);
        else if (node->right)
            return helper(node->right, curSum);
        else if (node->left)
            return helper(node->left, curSum);

        return curSum;
    }

    bool isLeaf(TreeNode *node)
    {
        return (node->left == nullptr) && (node->right == nullptr);
    }
};
int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    cout << s.sumOfLeftLeaves(root);
}