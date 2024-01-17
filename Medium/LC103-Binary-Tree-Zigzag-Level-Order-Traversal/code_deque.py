# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans = []
        q = deque()
        q.append(root)
        ltor = 1
        while len(q)>0:
            sz = len(q)
            level = []
            while sz:
                if ltor:
                    node = q.popleft()
                else:
                    node = q.pop()
                level.append(node.val)
                if ltor:
                    if node.left:
                        q.append(node.left)
                    if node.right:
                        q.append(node.right)
                else:
                    if node.right:
                        q.appendleft(node.right)
                    if node.left:
                        q.appendleft(node.left)
                sz -= 1
            ltor = not ltor
            ans.append(level)
        return ans
