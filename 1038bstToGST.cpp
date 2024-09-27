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
    TreeNode* bstToGst(TreeNode* root) {
        // Store the inorder traversal in an array.
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);

        // Reverse the array to get descending order.
        reverse(inorderTraversal.begin(), inorderTraversal.end());

        // Modify the values in the tree.
        replaceValues(root, inorderTraversal);

        return root;
    }

private:
    // Perform any traversal of your choice to store node values.
    void inorder(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    // Function to modify the values in the tree.
    void replaceValues(TreeNode* root, vector<int>& inorderTraversal) {
        if (root == nullptr) {
            return;
        }
        replaceValues(root->left, inorderTraversal);
        replaceValues(root->right, inorderTraversal);

        int nodeSum = 0;
        // Replace node with values greater than the current value.
        for (auto i : inorderTraversal) {
            if (i > root->val) {
                nodeSum += i;
            } else {
                break;
            }
        }

        root->val += nodeSum;
    }
};

int main(){
    Solution s;
    auto root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    auto result = s.bstToGst(root);
    cout << result->val << endl;
    cout << result->left->val << endl;
    cout << result->right->val << endl;
    cout << result->left->left->val << endl;
    cout << result->left->right->val << endl;
    cout << result->left->right->right->val << endl;
    cout << result->right->left->val << endl;
    cout << result->right->right->val << endl;
    cout << result->right->right->right->val << endl;
}