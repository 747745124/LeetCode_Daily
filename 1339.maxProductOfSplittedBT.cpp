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
    long long sum = 0;
    long long res = 0;
    int maxProduct(TreeNode *root)
    { // intuition, calculate the sum, and then for each node, calcuate its subtree sum
        dfs(root);
        postorder(root);
        return res % 1000000007;
    };

    int postorder(TreeNode *root)
    {
        int subtree = 0;
        if (root == nullptr)
            return 0;
        subtree += postorder(root->left);
        subtree += postorder(root->right);
        subtree += root->val;

        long long this_res = ((sum - (subtree)) * (subtree));
        res = max(res, this_res);

        return subtree;
    };

    void dfs(TreeNode *node)
    {
        if (node == nullptr)
            return;
        sum += node->val;
        dfs(node->left);
        dfs(node->right);
    };
};