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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;

        if(root == nullptr)
            return {};
        
        stk.push(root);
        while(!stk.empty()) {

            auto top = stk.top();
            stk.pop();

            if(top!=nullptr){
                stk.push(top);
                stk.push(nullptr);

                if(nullptr!=top->right)
                    stk.push(top->right);
                
                if(nullptr!=top->left)
                    stk.push(top->left);
            }
            else{
                auto node = stk.top();
                stk.pop();
                result.push_back(node->val);
            }
        }

        return result;
    }
};