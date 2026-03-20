# Last updated: 3/20/2026, 11:07:40 PM
1""" 
2Brute force works?
3"""
4class Solution:
5    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
6        n: int = len(grid)
7        m: int = len(grid[0])
8
9        res: list[list[int]] = []
10
11        for i in range(n - k + 1):
12            curr_res: list[int] = []
13            for j in range(m - k + 1):
14                curr: list[int] = []
15                for y in range(i, i + k):
16                    for x in range(j, j + k):
17                        curr.append(grid[y][x])
18                curr.sort()
19
20                this_min: int = float('inf')
21
22                unduplicated_set: list[int] = list(dict.fromkeys(curr))
23                for x in range(1, len(unduplicated_set)):
24                    this_min = min(this_min, abs(unduplicated_set[x] - unduplicated_set[x - 1]))
25                
26                if this_min == float('inf'):
27                    curr_res.append(0)
28                else:
29                    curr_res.append(this_min)
30            res.append(curr_res)
31
32        return res
33
34