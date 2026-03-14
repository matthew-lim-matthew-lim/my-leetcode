# Last updated: 3/14/2026, 1:35:01 PM
1""" 
2This definitely uses the modulo. 
3The first 3 is 0,1,2
4If length is 2.
5
6The adjacent characters cannot be the same. 
7
80: 0,0,0 -> 0
91: 0,0,1 -> 1
102: 0,0,2 -> 2
113: 0,1,0 -> 3
124: 0,1,1 -> 4
135: 0,1,2 -> 5
14
156: 0,2,0
167: 0,2,1
178: 0,2,2
18
199: 
209: 1,0,0
2110: 1,0,1
2211: 1,0,2
23
2412: 1,1,0
2513: 1,1,1
2614: 1,1,2
27
284:
294 % 3 = 1 (this is the last index).
304 / 3 = 1 (this is the first index).
31
3214:
3314 % 3 = 2 (1st index) 
3414 / 3 = 4 
354 % 3 = 1 (2nd index)
364 / 3 = 1 
371 % 3 = 1 (3rd index)
38
39Max number of indicies: 
40
41Or just brute force the computation?
42Start with: ababab
43Then, increment the last character k times.
44
45aba
46abb -> abc
47abd -> aca
48acb
49acc -> acd -> add -> baa -> bab
50
51abc -> abd -> aca
52
53abb -> abc -> 
54
55Increment characters from right to left. 
56Resolve matching adjacencies left to right.
57
58I can do this with backtracking.
59You construct the string letter by letter, guaranteeing order. 
60
61The count of letters is 3 * (2 ** (n - 1)).
62For for first one, pick a: 1
63For second one, pick b: 1
64
65Len = 2
66
67For first one, pick a: 0 * 3: 0
68
69For first one, pick b: 1 * 3: 3
70
71For first one, pick c: 2 * 3: 6
72
73Len = 3
74
75For first one, pick a: 0 * 3 * 2: 0
76a,b,a
77a,b,c
78a,c,a
79a,c,b
80
81For first one, pick b: 1 * 3 * 2: 6
82
83For first one, pick c: 2 * 3 * 2: 12
84
85So basically, if picking the ith character,
86+= (2 ** (n - 1 - i))
87
88If picking the 1st character,
89+= 3 * (2 ** (n - 1))
90
91For the last character, i
92+= i 
93+= (2 ** (n - 1 - i))
94
95"""
96class Solution:
97    def getHappyString(self, n: int, k: int) -> str:
98        if 3 * (2 ** (n-1)) < k:
99            return ""
100
101        if n == 1:
102            return chr(k - 1 + ord('a'))
103
104        def backtrack(count: int, curr: list[str]):
105            # print(count, curr)
106            if len(curr) == n:
107                if count == k - 1:
108                    # print("".join(curr))
109                    return "".join(curr)
110                else:
111                    return ""
112
113            curr_index: int = 0
114            for i, c in enumerate(list([ 'a', 'b', 'c' ])):
115                if curr[-1] == c:
116                    continue
117                res = backtrack(count + curr_index * (2 ** (n - 1 - len(curr))), curr + [c])
118                if res:
119                    return res
120                curr_index += 1
121
122        a = backtrack(0 * (2 ** (n - 1)), ['a'])
123        b = backtrack(1 * (2 ** (n - 1)), ['b'])
124        c = backtrack(2 * (2 ** (n - 1)), ['c'])
125
126        if a and len(a) != 0:
127            return a
128        if b and len(b) != 0:
129            return b
130        if c and len(c) != 0:
131            return c
132
133        return ""