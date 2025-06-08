# Last updated: 6/8/2025, 11:54:22 PM
""" 
BFS works.
"""

from collections import deque

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = set()

        q = deque()
        maxSize = 0

        n = len(grid)
        m = len(grid[0])

        for i in range(0, n):
            for j in range(0, m):
                if not f"{i},{j}" in visited:
                    visited.add(f"{i},{j}")

                    

                    if grid[i][j] == 1:
                        q.append([i, j])
                        currSize = 0
                        while len(q) > 0:
                            y, x = q.popleft()
                            currSize += 1
                            maxSize = max(maxSize, currSize)

                            if not f"{y + 1},{x}" in visited and y + 1 < n and grid[y + 1][x] == 1:
                                q.append([y + 1, x])
                                visited.add(f"{y + 1},{x}")
                            if not f"{y - 1},{x}" in visited and y - 1 >= 0 and grid[y - 1][x] == 1:
                                q.append([y - 1, x])
                                visited.add(f"{y - 1},{x}")
                            if not f"{y},{x + 1}" in visited and x + 1 < m and grid[y][x + 1] == 1:
                                q.append([y, x + 1])
                                visited.add(f"{y},{x + 1}")
                            if not f"{y},{x - 1}" in visited and x - 1 >= 0 and grid[y][x - 1] == 1:
                                q.append([y, x - 1])
                                visited.add(f"{y},{x - 1}")

        return maxSize
        