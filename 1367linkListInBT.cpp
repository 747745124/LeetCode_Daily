#include "header.hpp"

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(dfs(head,root)) return true;
        if(root->left && isSubPath(head,root->left)) return true;
        if(root->right && isSubPath(head,root->right)) return true;
        return false;
        
    }

    bool dfs(ListNode* head, TreeNode* root){
        if(head == nullptr) return true;
        if(root == nullptr) return false;
        if(head->val != root->val) return false;
        return dfs(head->next,root->left) || dfs(head->next,root->right);
    }
};


int main(){
    Solution s;
// Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
// Output: true
// Explanation: Nodes in blue form a subpath in the binary Tree. 

    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(8);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);
    root->right->left->right->left = new TreeNode(1);
    root->right->left->right->right = new TreeNode(3);

    cout<<s.isSubPath(head,root);
    return 0;
}