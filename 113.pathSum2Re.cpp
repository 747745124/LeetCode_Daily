#include "header.hpp"
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        solve(root, targetSum, path, res);
        return res;
    }

    void solve(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& res) {
        if(!root) return;

        path.push_back(root->val);

        if(!root->left && !root->right && root->val == targetSum) {
            res.push_back(path);
        }

        solve(root->left, targetSum - root->val, path, res);
        solve(root->right, targetSum - root->val, path, res);

        path.pop_back();
    }
};
