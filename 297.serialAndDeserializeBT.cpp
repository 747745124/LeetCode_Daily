#include "header.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        // use inorder
        string result = "";
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node == nullptr)
            {
                result += "null,";
                continue;
            }
            result += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // words splitting
        vector<string> tokens;
        if (data.length() == 0)
            return nullptr;
        stringstream ss(data);
        string word;
        while (!ss.eof())
        {
            getline(ss, word, ',');
            tokens.push_back(word);
        }

        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(stoi(tokens[0]));
        q.push(root);
        int i = 1;
        while (!q.empty() && i < tokens.size())
        {
            auto &node = q.front();
            q.pop();
            if (tokens[i] != "null")
            {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;
            if (tokens[i] != "null")
            {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

int main(int argc, char **argv)
{
    Codec *codec = new Codec();
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    auto result = codec->serialize(root);
    cout << result << endl;
    auto deserialized = codec->deserialize(result);
    cout << deserialized->val << endl;
    return 0;
}

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));