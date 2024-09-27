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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //replace it with the smallest node from the right subtree

        if(root == nullptr)
            return root;

        if(key < root->val)
            return root->left = deleteNode(root->left,key);

        if(key > root->val)
            return root->left = deleteNode(root->left,key);  

        if(root->left&&root->right){
            auto tmp = findSmallestRightSubtree(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right,tmp->val);
        }else{

            if(root->left!=nullptr)
                root=root->left;
            if(root->right!=nullptr)
                root=root->right;

        }

        return root;
    
    }

    //just go all the way to the left
    TreeNode* findSmallestRightSubtree(TreeNode* root)
    {
        auto node = root;
        while(node!=nullptr) {
            node = node->left;
        }

        return node;
    }
};