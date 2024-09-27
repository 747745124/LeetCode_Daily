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
    vector<int> rightSideView(TreeNode* root) {
        if(nullptr == root)
            return {};

        vector<int> res;
        vector<TreeNode*> curr,next;
        curr.push_back(root);

        while(!curr.empty()){
            for(const auto& node : curr){
                if(node->left!=nullptr)
                    next.push_back(node->left);
                if(node->right!=nullptr)
                    next.push_back(node->right);
            };

            res.push_back(curr.back()->val);
            curr=next;
            next.clear();
        };

        return res;

    }
};