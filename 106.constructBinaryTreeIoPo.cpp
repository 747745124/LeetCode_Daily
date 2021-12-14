#include "header.hpp"
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int size = inorder.size();
        return BuildTreeHelper(0, size - 1, 0, size - 1, inorder, postorder);
    }
    // linear search helper functions
    int findPosInOrder(int begin, int end, int target, vector<int> &inorder)
    {
        for (int i = begin; i <= end; i++)
        {
            if (target == inorder[i])
                return i;
        }
        // not found
        return -1;
    }

    // linear search helper functions
    int findPosPostOrder(int begin, int end, int target, vector<int> &postorder)
    {
        for (int i = begin; i <= end; i++)
        {
            if (target == postorder[i])
                return i;
        }
        // not found
        return -1;
    }
    TreeNode *BuildTreeHelper(int i1, int i2, int p1, int p2, vector<int> &inorder, vector<int> &postorder)
    {
        // this means no nodes within the range
        if (i1 > i2)
            return nullptr;
        if (p1 > p2)
            return nullptr;

        // root is the last element in the postOrder array
        TreeNode *root = new TreeNode;
        int rootData = postorder[p2];
        root->val = rootData;
        // find position of the root data in the inOrder array
        int rootPosInOrder = findPosInOrder(i1, i2, rootData, inorder);
        // then the left part is left subtree and the right part is right subtree
        int leftTreeSize = rootPosInOrder - i1;
        // pass in the indices of post order/ the subtree
        /*
    postOrder:(left),(right),root
    inOrder:(left),root,(right)
    */
        root->left = BuildTreeHelper(i1, i1 + leftTreeSize - 1, p1, p1 + leftTreeSize - 1, inorder, postorder);
        root->right = BuildTreeHelper(rootPosInOrder + 1, i2, p1 + leftTreeSize, p2 - 1, inorder, postorder);

        return root;
    }
};