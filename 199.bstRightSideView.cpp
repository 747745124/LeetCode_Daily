#include "header.hpp"
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        // level order
        vector<TreeNode *> curr, next;
        vector<int> res;

        if (root == nullptr)
            return {};

        res.push_back(root->val);
        curr.push_back(root);
        while (!curr.empty())
        {
            for (const auto &node : curr)
            {
                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            }

            if (!next.empty())
                res.push_back(next.back()->val);

            curr = std::move(next);
            next.clear();
        }

        return res;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> res = s.rightSideView(root);
    for (const auto &i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}
