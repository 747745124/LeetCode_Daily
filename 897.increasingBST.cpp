#include "header.hpp"
class Solution
{
public:
    TreeNode *curr; // dummy head, point to the current node;

    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *res = new TreeNode(0);
        curr = res;
        inorder(root);

        return res->right;
    }

    void inorder(TreeNode *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        // cutoff
        node->left = nullptr;
        // point to the current node
        curr->right = node;
        // move to the current node
        curr = node;
        inorder(node->right);
    }
};