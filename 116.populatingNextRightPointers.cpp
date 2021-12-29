#include "header.hpp"

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    // level order traversal variant
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        vector<Node *> curr, next;
        curr.push_back(root);
        while (!curr.empty())
        {
            for (int i = 0; i < curr.size(); i++)
            {
                auto node = curr[i];

                if (i < curr.size() - 1)
                    node->next = curr[i + 1];

                if (node->left)
                    next.push_back(node->left);
                if (node->right)
                    next.push_back(node->right);
            }

            curr = next;
            next.clear();
        }

        return root;
    }
};

int main()
{
    Solution sol;
    auto n = new Node(1);
    n->left = new Node(2);
    n->right = new Node(3);
    n->left->left = new Node(4);
    n->left->right = new Node(5);
    n->right->left = new Node(6);
    n->right->right = new Node(7);
    sol.connect(n);
    return 0;
}