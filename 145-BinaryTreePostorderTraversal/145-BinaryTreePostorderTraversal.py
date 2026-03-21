# Last updated: 3/21/2026, 7:12:08 PM
1# Definition for a binary tree node.
2# class TreeNode:
3#     def __init__(self, val=0, left=None, right=None):
4#         self.val = val
5#         self.left = left
6#         self.right = right
7class Solution:
8    res: list[int] = []
9
10    def traverse(self, root: TreeNode) -> None:
11        if not root:
12            return
13        self.traverse(root.left)
14        self.traverse(root.right)
15        self.res.append(root.val)
16
17    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
18        self.res = []
19        if not root:
20            return self.res
21
22        self.traverse(root)
23
24        return self.res