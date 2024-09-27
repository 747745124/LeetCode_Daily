#include "header.hpp"
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> stk;
        vector<int> result;

        if(root == nullptr)
            return {};
        
        stk.push(root);
        while(!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if(node!=nullptr){

                stk.push(node);
                stk.push(nullptr);

                const auto& childs = node->children;

                for(int i = childs.size() - 1; i >= 0; i--){
                    stk.push(childs[i]);
                }

            }
            else{
                result.push_back(stk.top()->val);
                stk.pop();
            }

        }

        return result;


    }
};