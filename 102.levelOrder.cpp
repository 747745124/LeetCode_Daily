#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        return bfs(root);
    }

    vector<vector<int>> bfs(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> ans;
        vector<TreeNode *> cur, next;
        //the nodes to process in current/next step;

        cur.push_back(root);

        while (!cur.empty())
        {
            vector<int> level;

            for (auto node : cur)
            {
                level.push_back(node->val);
                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            }
            ans.push_back(level);

            swap(cur, next);
            next.clear();
        }
        return ans;
    }
};