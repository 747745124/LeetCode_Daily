#include "header.hpp"
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return (countNodes(root->left) + countNodes(root->right) + 1);
    }
};