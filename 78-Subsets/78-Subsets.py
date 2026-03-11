# Last updated: 3/11/2026, 5:48:34 PM
1""" 
2For each number, either include or exclude it. 
3"""
4class Solution:
5    def subsets(self, nums: List[int]) -> List[List[int]]:
6        res: list[list[int]] = []
7        n = len(nums)
8
9        def backtrack(s: list[int], currNums: list[int]):
10            if len(currNums) == 0:
11                res.append(s)
12                return
13
14            backtrack(s + [currNums[0]], currNums[1:])
15            backtrack(s, currNums[1:])
16
17        backtrack([], nums)
18
19        return res
20
21
22
23