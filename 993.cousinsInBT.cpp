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
    bool isCousins(TreeNode *root, int x, int y)
    {
        pair<TreeNode *, int> X = getDepthAndParent(root, nullptr, x, 0);
        pair<TreeNode *, int> Y = getDepthAndParent(root, nullptr, y, 0);
        return X.first != Y.first && X.second == Y.second;
    }

    pair<TreeNode *, int> getDepthAndParent(TreeNode *root, TreeNode *par, int value, int depth)
    {
        if (root == nullptr)
            return make_pair(nullptr, -1);
        if (root->val == value)
            return make_pair(par, depth);

        auto leftSub = getDepthAndParent(root->left, root, value, depth + 1);
        if (leftSub.first == nullptr)
            return getDepthAndParent(root->right, root, value, depth + 1);
        return leftSub;
    };
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << s.isCousins(root, 5, 4) << endl;
    return 0;
}
