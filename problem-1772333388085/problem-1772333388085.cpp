// Last updated: 3/1/2026, 1:49:48 PM
1/*
2Dynamic programming? 
3Minimum cost to split each integer x into x ones. 
4
5Input: n = 5
65, 2, 3, 5, 6, 6
72, 1, 1, 2, 1, 1
83, 1, 2, 3, 2, 2
92, 1, 1, 2, 1, 1
10Minimum total cost = 10.
11
125, 1, 4, 5, 4, 4
134 -> 6
14Minimum total cost = 10.
15
16Input: n = 4
174, 1, 3, 4, 3, 3
183 -> 3
19Minimum total cost: 3.
20
21Input: n = 6.
226, 1, 5, 6, 5, 5
235 -> 10
24Minimum total cost: 15
25
26Is this just nC2?
27*/
28class Solution {
29public:
30    int choose(int n) {
31        return (n * (n - 1)) / 2;
32    }
33    
34    int minCost(int n) {
35        return n == 1 ? 0 : choose(n);
36    }
37};