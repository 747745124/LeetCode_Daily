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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        //post order traversal, if the node is in the delete list
        //then add 2 children into the list

        vector<TreeNode*> res;
        postOrder(root, to_delete);

    }

    void postOrder(TreeNode* root,vector<int> & to_delete){
        
        if(root!=nullptr)
        {

        }

    }
};