#include "header.hpp"
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> st;
        return helper(root, k, st);
    }
    bool helper(TreeNode *node, int k, unordered_set<int> &st)
    {
        //if leaf node, and no matching
        if (!node)
            return false;
        //if there's matching in the recorded value
        if (st.count(k - node->val))
            return true;
        //insert into the recorded value
        st.insert(node->val);
        //check left and right leaf nodes
        return helper(node->left, k, st) || helper(node->right, k, st);
    }
};
