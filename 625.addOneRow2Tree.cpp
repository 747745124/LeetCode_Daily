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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (root == nullptr)
            return nullptr;

        if (depth == 1) // edge case
        {
            TreeNode *new_root = new TreeNode(val, root, nullptr);
            return new_root;
        }
        // do traverse first
        vector<TreeNode *> curr, next;
        curr.push_back(root);
        depth--;

        while (--depth)
        {
            for (const auto &node : curr)
            {

                if (node->left != nullptr)
                    next.push_back(node->left);
                if (node->right != nullptr)
                    next.push_back(node->right);
            }
            curr = next;
            next.clear();
        }

        for (auto &node : curr)
        {
            if (node == nullptr)
                continue;

            TreeNode *temp = new TreeNode(val, node->left, nullptr);
            node->left = temp;

            temp = new TreeNode(val, nullptr, node->right);
            node->right = temp;
        }

        return root;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);

    auto res = s.addOneRow(root, 1, 1);
    return 0;
}