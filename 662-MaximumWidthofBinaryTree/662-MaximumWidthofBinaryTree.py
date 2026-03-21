# Last updated: 3/21/2026, 9:55:56 PM
1""" 
21,0
3
43,0 2,1
5
65,0 3,1 N,2 9,3
7
81,0
9
103,0 2,1
11
125,0 N,1 N,2 9,3
13
146,0 N,1 N,2 N,3 N,4 N,5 7,6 N,7
15
16At each level, double it. 
17If left, dont add. If right, add 1.
18
19Keep track of the min and max at each level.
20"""
21# Definition for a binary tree node.
22# class TreeNode:
23#     def __init__(self, val=0, left=None, right=None):
24#         self.val = val
25#         self.left = left
26#         self.right = right
27from dataclasses import dataclass
28
29@dataclass
30class LevelInfo:
31    minimum: int = float('inf')
32    maximum: int = float('-inf')
33
34class Solution:
35    def traverse(self, root: TreeNode, depth: int, x_distance: int):
36        if not root:
37            return
38
39        self.level_heights[depth].minimum = min(
40            self.level_heights[depth].minimum,
41            x_distance
42        )
43
44        self.level_heights[depth].maximum = max(
45            self.level_heights[depth].maximum,
46            x_distance
47        )
48        
49        self.traverse(root.left, depth + 1, x_distance * 2)
50        self.traverse(root.right, depth + 1, x_distance * 2 + 1)
51
52    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
53        if not root:
54            return 0
55        self.level_heights: dict[int, int] = defaultdict(LevelInfo)
56
57        self.traverse(root, 0, 0)
58
59        res: int = 0
60
61        for info in self.level_heights.values():
62            if info.minimum <= info.maximum:
63                res = max(res, info.maximum - info.minimum)
64
65        return res + 1
66