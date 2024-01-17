# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
    
        def height(root):
            if not root:
                return 0
            return 1 + max(height(root.left), height(root.right))
            
        def diameter(root):
            if not root:
                return 0
            left_dia = diameter(root.left)
            right_dia = diameter(root.right)
            dia = height(root.left) + height(root.right)
            return max([left_dia, right_dia, dia])
        return diameter(root)
