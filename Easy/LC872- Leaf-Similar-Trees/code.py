# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:

        # function start
        def inorder(root, bst):
            if not root:
                return
            if not root.left and not root.right:
                bst.append(root.val)
            dfs(root.left, bst)
            dfs(root.right, bst)
        # function end

        bst1, bst2 = [], []
        dfs(root1, bst1)
        dfs(root2, bst2)

        if len(bst1) != len(bst2):
            return False
        for i in range(len(bst1)):
            if bst1[i] != bst2[i]:
                return False
        return True
        
