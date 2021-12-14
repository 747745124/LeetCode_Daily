#include "header.hpp"
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return BuildTree(preorder.size(), preorder, inorder);
    }

    // linear search helper functions
    int findPosInOrder(int begin, int end, int target, vector<int> &inOrder)
    {
        for (int i = begin; i <= end; i++)
        {
            if (target == inOrder[i])
                return i;
        }
        // not found
        return -1;
    }

    // linear search helper functions
    int findPosPostOrder(int begin, int end, int target, vector<int> &preOrder)
    {
        for (int i = begin; i <= end; i++)
        {
            if (target == preOrder[i])
                return i;
        }
        // not found
        return -1;
    }

    TreeNode *BuildTreeHelper(int i1, int i2, int p1, int p2, vector<int> &preOrder, vector<int> &inOrder)
    {
        // this means no nodes within the range
        if (i1 > i2)
            return nullptr;
        if (p1 > p2)
            return nullptr;

        // root is the last element in the postOrder array
        TreeNode *root = new TreeNode;
        int rootData = preOrder[p1];
        root->val = rootData;
        // find position of the root data in the inOrder array
        int rootPosInOrder = findPosInOrder(i1, i2, rootData, inOrder);
        // then the left part is left subtree and the right part is right subtree
        int leftTreeSize = rootPosInOrder - i1;
        // pass in the indices of post order/ the subtree
        /*
        preOrder:root,(left),(right)
        inOrder:(left),root,(right)
        */
        root->left = BuildTreeHelper(i1, i1 + leftTreeSize - 1, p1 + 1, p1 + leftTreeSize - 1 + 1, preOrder, inOrder);
        root->right = BuildTreeHelper(rootPosInOrder + 1, i2, p1 + 1 + leftTreeSize, p2, preOrder, inOrder);

        return root;
    }

    /*
    first step, build tree from postOrder and inOrder Pair
    the key is to determine the length of the (left) subtree
    postOrder:(left),(right),root
    inOrder:(left),root,(right)
    build(node,begin,end)
    root = postOrder.last
    (left) = Inorder.find(root).getLeft
    (right) = Inorder.find(root).getRight
    root.left = left
    root.right = right
    */
    TreeNode *BuildTree(int size, vector<int> &preorder, vector<int> &inorder)
    {
        return BuildTreeHelper(0, size - 1, 0, size - 1, preorder, inorder);
    };
};
