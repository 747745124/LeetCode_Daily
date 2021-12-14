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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {

        return buildHelper(preorder, 0, preorder.size() - 1);
    }
    TreeNode *buildHelper(vector<int> &preorder, int begin, int end)
    {
        if (begin > end)
            return nullptr;

        auto root = new TreeNode(preorder[begin]);
        int rightSubTreeIndex = begin;
        while (preorder[rightSubTreeIndex] <= preorder[begin] && rightSubTreeIndex < preorder.size())
        {
            rightSubTreeIndex++;
        }
        //now the index has point to the first element of the right subtree
        //preoder: root, left, right
        auto leftSubTreeSize = rightSubTreeIndex - begin - 1;
        auto rightSubTreeSize = end - rightSubTreeIndex + 1;

        if (leftSubTreeSize == 0)
            root->left = nullptr;
        else
        {
            root->left = buildHelper(preorder, begin + 1, rightSubTreeIndex - 1);
        }
        if (rightSubTreeSize == 0)
            root->right = nullptr;
        else
        {
            root->right = buildHelper(preorder, rightSubTreeIndex, end);
        }

        return root;
    }
};

int main()
{
    Solution s;
    vector<int> preorder = {4, 5, 14, 20};
    auto root = s.bstFromPreorder(preorder);
    return 0;
}