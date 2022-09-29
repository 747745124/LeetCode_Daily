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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return {};
        traversal(root, targetSum - root->val, {});
        return res;
    }

    bool traversal(TreeNode *cur, int count, vector<int> path)
    {
        bool flag = false;
        path.push_back(cur->val);
        // end case
        if (!cur->left && !cur->right && count == 0)
        {
            res.push_back(path);
            return true; // leafnode and get to target
        }

        if (!cur->left && !cur->right)
            return false; // no suitable pathSum

        if (cur->left)
        {                            // 左
            count -= cur->left->val; // 递归，处理节点;
            traversal(cur->left, count, path);
            count += cur->left->val; // 回溯，撤销处理结果
        }

        if (cur->right)
        { // 右
            count -= cur->right->val;
            traversal(cur->right, count, path);
            count += cur->right->val;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    auto res = s.pathSum(root, 22);
    for (auto &v : res)
    {
        for (auto &i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}