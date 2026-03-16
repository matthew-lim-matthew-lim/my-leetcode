# Last updated: 3/17/2026, 12:08:05 AM
1""" 
2It goes down, then up-right. Then repeat. 
3
4Simulation problem. 
5
6
7PAYPALISHIRING
8
9
106,6
114,2,4,2
122,4,2
136
14
15This is 4 rows.
16This works because there are 2 in between the top and bottom.
17So 4 + (4 - 2) = 6 were skipped. 
18
19The next row. Split 6 into 4 and 2. 
20The next row, Split 6 into 2 and 4.
21
22The next row, skip 6.
23
24P     I    N
25A   L S  I G
26Y A   H R
27P     I
28"""
29class Solution:
30    def convert(self, s: str, numRows: int) -> str:
31        if numRows == 1:
32            return s
33
34        res: list[str] = []
35        
36        step_a: int = numRows + (numRows - 2)
37        step_b: int = 0
38
39        n: int = len(s)
40
41        for i in range(min(numRows, n)):
42            # print("res")
43            curr: int = i
44            res.append(s[curr])
45            if i == 0 or i == numRows-1:
46                curr += max(step_a, step_b)
47                while curr < n:
48                    res.append(s[curr])
49                    curr += max(step_a, step_b)
50            else:
51                curr += step_a
52                while curr < n:
53                    res.append(s[curr])
54                    curr += step_b
55                    if curr < n:
56                        res.append(s[curr])
57                    curr += step_a
58            step_a -= 2
59            step_b += 2
60
61        return ''.join(res)
62
63
64
65
66
67
68
69