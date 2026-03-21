# Last updated: 3/21/2026, 10:27:18 PM
1""" 
2BFS then sort.
3"""
4from dataclasses import dataclass
5
6@dataclass
7class QueueEntry:
8    y: int
9    x: int
10    dist: int
11    val: int
12
13class Solution:
14    def highestRankedKItems(self, grid: List[List[int]], pricing: List[int], start: List[int], k: int) -> List[List[int]]:
15        n: int = len(grid)
16        m: int = len(grid[0])
17
18        q: deque[QueueEntry] = deque()
19
20        q.append(
21            QueueEntry(
22                y=start[0],
23                x=start[1],
24                dist=0,
25                val=grid[start[0]][start[1]]
26            )
27        )
28
29        grid[start[0]][start[1]] = 0
30
31        res: list[QueueEntry] = []
32
33        while q:
34            curr: QueueEntry = q.popleft()
35
36            if curr.val >= pricing[0] and curr.val <= pricing[1]:
37                res.append(curr)
38
39            if curr.y-1 >= 0 and grid[curr.y-1][curr.x] != 0:
40                q.append(
41                    QueueEntry(
42                        y=curr.y-1,
43                        x=curr.x,
44                        dist=curr.dist+1,
45                        val=grid[curr.y-1][curr.x]
46                    )
47                )
48                grid[curr.y-1][curr.x] = 0
49
50            if curr.y+1 < n and grid[curr.y+1][curr.x] != 0:
51                q.append(
52                    QueueEntry(
53                        y=curr.y+1,
54                        x=curr.x,
55                        dist=curr.dist+1,
56                        val=grid[curr.y+1][curr.x]
57                    )
58                )
59                grid[curr.y+1][curr.x] = 0
60
61            if curr.x-1 >= 0 and grid[curr.y][curr.x-1] != 0:
62                q.append(
63                    QueueEntry(
64                        y=curr.y,
65                        x=curr.x-1,
66                        dist=curr.dist+1,
67                        val=grid[curr.y][curr.x-1]
68                    )
69                )
70                grid[curr.y][curr.x-1] = 0
71
72            if curr.x+1 < m and grid[curr.y][curr.x+1] != 0:
73                q.append(
74                    QueueEntry(
75                        y=curr.y,
76                        x=curr.x+1,
77                        dist=curr.dist+1,
78                        val=grid[curr.y][curr.x+1]
79                    )
80                )
81                grid[curr.y][curr.x+1] = 0
82
83        res.sort(key=lambda t: (
84            t.dist,
85            t.val,
86            t.y,
87            t.x
88        ))
89
90        return [[items.y, items.x] for items in res[:k]]
91
92