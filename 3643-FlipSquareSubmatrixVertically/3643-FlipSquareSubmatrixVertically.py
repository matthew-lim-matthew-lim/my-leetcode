# Last updated: 3/21/2026, 12:47:10 PM
1""" 
2Iterate from top row of the matrix to the middle.
3"""
4class Solution:
5    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
6        n: int = len(grid)
7        m: int = len(grid[0])
8    
9        for i in range(k // 2):
10            for j in range(k):
11                curr: int = grid[x+i][y+j]
12                grid[x+i][y+j] = grid[x+k-i-1][y+j]
13                grid[x+k-i-1][y+j] = curr
14
15        return grid