#include "header.hpp"
class BSTIterator
{
private:
    // TreeNode *curr = nullptr;
    stack<TreeNode *> stk;

public:
    BSTIterator(TreeNode *root)
    {
        pushAllLeftNodes(root);
        // curr = new TreeNode(root->val - 1);
    }

    void pushAllLeftNodes(TreeNode *curr)
    {
        // TreeNode *curr = node;
        while (curr != nullptr)
        {
            stk.push(curr);
            curr = curr->left;
        }
    }

    int next()
    {
        TreeNode *top = stk.top();
        stk.pop();
        if (top->right != nullptr)
            pushAllLeftNodes(top->right);
        return top->val;
    }

    bool hasNext()
    {
        return (!stk.empty());
    }
};
