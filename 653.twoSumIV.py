class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def preorderTraversal(self, root):
        if not root:
            return []
        stack, res = [], []

        stack.append(root)

        while stack:
            cur = stack.pop()
            res.append(cur.val)
            if cur.right:
                stack.append(cur.right)
            if cur.left:
                stack.append(cur.left)

        return res

    def findTarget(self, root, k):
        # root = self.preorderTraversal(root)
        if len(root) < 2:
            return False
        for i in range(0, len(root)):
            if (k-i) in root and root.index(k-i) != i:
                return True

        return False


if __name__ == '__main__':
    root = [2, 3]
    k = 6
    sol = Solution()
    print(sol.findTarget(root, k))
