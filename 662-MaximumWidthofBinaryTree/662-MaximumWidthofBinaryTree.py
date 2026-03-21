# Last updated: 3/21/2026, 9:58:39 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        first_index = {}
        self.max_width = 0

        def dfs(node, level, index):
            if node is None:
                return
            
            if level not in first_index:
                first_index[level] = index
            
            self.max_width = max(self.max_width, index - first_index[level] + 1)

            dfs(node.left, level + 1, 2*index)
            dfs(node.right, level + 1, 2*index + 1)
        
        dfs(root, 0, 1)
        return self.max_width