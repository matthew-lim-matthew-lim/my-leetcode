# Last updated: 3/18/2026, 10:44:27 PM
1""" 
2Do it with regions (prefix sum).
3
4Subtract the inner region from the outer region.
5
6So prefix[y][x] - prefix[y-1][x-1].
7"""
8class Solution:
9    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
10        n: int = len(grid)
11        m: int = len(grid[0])
12
13        prefix: list[list[int]] = [[0 for i in range(m)] for j in range(n)]
14
15        prefix[0][0] = grid[0][0]
16
17        for i in range(1, n):
18            prefix[i][0] = prefix[i-1][0] + grid[i][0]
19
20        for i in range(1, m):
21            prefix[0][i] = prefix[0][i-1] + grid[0][i]
22
23        for i in range(1, n):
24            for j in range(1, m):
25                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + grid[i][j] - prefix[i-1][j-1]
26        
27        res: int = 0
28
29        # for i in range(n):
30        #     print(prefix[i])
31
32        for i in range(n):
33            for j in range(m):
34                if prefix[i][j] <= k:
35                    res += 1
36        
37        return res