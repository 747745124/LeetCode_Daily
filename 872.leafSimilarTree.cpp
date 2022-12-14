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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {

        stack<TreeNode *> stk1, stk2;
        vector<int> v1, v2;
        stk1.push(root1);
        stk2.push(root2);
        while (stk1.empty())
        {
            auto node = stk1.top();
            stk1.pop();

            if (node != nullptr)
            {
                stk1.push(node);
                stk1.push(nullptr);
                if (node->left)
                    stk1.push(node->left);
                if (node->right)
                    stk1.push(node->right);
            }
            else if (node == nullptr)
            {
                node = stk1.top();
                stk1.pop();
                if (node->left == nullptr && node->right == nullptr)
                    v1.push_back(node->val);
            }
        }

        while (stk2.empty())
        {
            auto node = stk2.top();
            stk2.pop();

            if (node != nullptr)
            {
                stk2.push(node);
                stk2.push(nullptr);
                if (node->left)
                    stk2.push(node->left);
                if (node->right)
                    stk2.push(node->right);
            }
            else if (node == nullptr)
            {
                node = stk2.top();
                stk2.pop();
                if (node->left == nullptr && node->right == nullptr)
                    v2.push_back(node->val);
            }
        }

        return v1 == v2;
    }
};

int main()
{
    Solution s;
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(2);

    cout << s.leafSimilar(root1, root2) << endl;
    return 0;
}