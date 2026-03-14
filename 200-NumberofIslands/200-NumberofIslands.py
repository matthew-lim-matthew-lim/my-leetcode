# Last updated: 3/14/2026, 2:47:34 PM
1""" 
2You can iterate through top left to bottom right, 
3and then bottom right to top left.
4
5Or you can use union find. 
6
7For example, when going from top left to bottom right, 
8assign the adjacent below and adjacent right squares the 
9same group as the current square.
10
11Or you BFS from each island square. 
12"""
13
14class Solution:
15    def numIslands(self, grid: List[List[str]]) -> int:
16        n: int = len(grid)
17        m: int = len(grid[0])
18
19        q: deque[tuple[int, int]] = deque()
20
21        group_count: int = 0
22
23        for i in range(n):
24            for j in range(m):
25                if grid[i][j] == "1":
26                    group_count += 1
27                    q.append((i, j))
28
29                    while q:
30                        y, x = q.popleft()
31                        if y + 1 < n and grid[y+1][x] == "1":
32                            grid[y+1][x] = str(group_count + 1)
33                            q.append((y+1, x))
34                        if y - 1 >= 0 and grid[y-1][x] == "1":
35                            grid[y-1][x] = str(group_count + 1)
36                            q.append((y-1, x))
37                        if x + 1 < m and grid[y][x+1] == "1":
38                            grid[y][x+1] = str(group_count + 1)
39                            q.append((y, x+1))
40                        if x - 1 >= 0 and grid[y][x-1] == "1":
41                            grid[y][x-1] = str(group_count + 1)
42                            q.append((y, x-1))
43
44
45        # for i in range(n):
46        #     print(grid[i])
47
48        return group_count
49
50        