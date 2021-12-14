#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        using namespace std;
        bool isReverse = false;
        if (root == nullptr)
            return;
        vector<vector<int>> res;
        // //the nodes to process in current/next step;
        vector<TreeNode *> curr, next;

        curr.push_back(root);

        while (!curr.empty())
        {
            vector<int> tmp;
            if (!isReverse)
                for (int i = 0; i < curr.size(); i++)
                {
                    auto node = curr[i];
                    tmp.push_back(node->val);
                    if (node->left)
                        next.push_back(node->left);
                    if (node->right)
                        next.push_back(node->right);
                    isReverse = true;
                }
            else
                for (int i = 0; i < curr.size(); i++)
                {
                    auto node = curr[i];
                    tmp.push_back(curr[curr.size() - i - 1]->val);
                    if (node->left)
                        next.push_back(node->left);
                    if (node->right)
                        next.push_back(node->right);
                    isReverse = false;
                }
            res.push_back(tmp);
            swap(curr, next);
            next.clear();
        }

        return res;
    }
};