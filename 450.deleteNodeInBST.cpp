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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        //found the element to be deleted
        else if (root->left && root->right)
        {
            auto smallest = findMin(root->right);
            root->val = smallest->val;
            root->right = deleteNode(root->right, root->val);
        }
        else
        {
            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
        }
        return root;
    }

private:
    TreeNode *findMin(TreeNode *node)
    {
        while (node->left)
            node = node->left;
        return node;
    }
};