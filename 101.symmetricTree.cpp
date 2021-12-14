
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return bfs(root);
    }

    bool bfs(TreeNode *root)
    {

        vector<TreeNode *> cur, next;
        //the nodes to process in current/next step;

        cur.push_back(root);
        if (root->left)
            next.push_back(root->left);
        else
        {
            TreeNode *tmpPtr = new TreeNode(101);
            next.push_back(tmpPtr);
        }
        if (root->right)
            next.push_back(root->right);
        else
        {
            TreeNode *tmpPtr = new TreeNode(101);
            next.push_back(tmpPtr);
        }
        swap(cur, next);
        next.clear();

        while (!cur.empty())
        {
            vector<int> level;
            for (auto node : cur)
            {
                level.push_back(node->val);
                if (node->left)
                    next.push_back(node->left);
                else
                {
                    TreeNode *tmpPtr = new TreeNode(101);
                    next.push_back(tmpPtr);
                }
                if (node->right)
                    next.push_back(node->right);
                else
                {
                    TreeNode *tmpPtr = new TreeNode(101);
                    next.push_back(tmpPtr);
                }
            }

            bool flag = true;
            for (auto &val : level)
            {
                if (val != 101)
                    flag = false;
            }
            if (flag)
                return true;

            for (int i = 0; i < level.size() / 2; i++)
            {
                if (level[i] != level[level.size() - 1 - i])
                    return false;
            }
            swap(cur, next);
            next.clear();
        }
        return true;
    }
};

class Solution2
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 首先排除空节点的情况
        if (left == NULL && right != NULL)
            return false;
        else if (left != NULL && right == NULL)
            return false;
        else if (left == NULL && right == NULL)
            return true;
        // 排除了空节点，再排除数值不相同的情况
        else if (left->val != right->val)
            return false;

        // 此时就是：左右节点都不为空，且数值相同的情况
        // 此时才做递归，做下一层的判断
        bool outside = compare(left->left, right->right); // 左子树：左、 右子树：右
        bool inside = compare(left->right, right->left);  // 左子树：右、 右子树：左
        bool isSame = outside && inside;                  // 左子树：中、 右子树：中 （逻辑处理）
        return isSame;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return compare(root->left, root->right);
    }
};