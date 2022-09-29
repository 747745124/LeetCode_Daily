#include "header.hpp"
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        // iterative inorder algo
        stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *node = stk.top();
            stk.pop();
            if (node != nullptr)
            {

                if (node->right)
                    stk.push(node->right);

                stk.push(node);
                stk.push(nullptr);

                if (node->left)
                    stk.push(node->left);
            }
            else
            {
                k--;
                if (k == 0)
                    return stk.top()->val;
                stk.pop();
            }
        }

        return -1;
    }
};