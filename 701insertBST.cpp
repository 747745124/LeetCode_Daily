#include "header.hpp"
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto node = root;
        while(node != nullptr&&(node->right||node->left)) {
            if(val > node->val && node->right)
                node = node->right;
            if(val < node->val && node->left)
                node = node->left;
        }

        if(val > node->val)
            node->right = new TreeNode(val);
        else if(val < node->val)
            node->left = new TreeNode(val);

        return root;
    }
};