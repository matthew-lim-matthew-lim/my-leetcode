# Last updated: 3/22/2026, 9:48:22 PM
1""" 
2Brute force?
3nxn
4i,j=0,1, (n-1)-1,0, (n-1),(n-1)-1, 1,(n-1)
5
6i,j=2,4, (n-1)-4,2, (n-1)-2,(n-1)-4, 4,(n-1)-2 
7
8
9mat[i][j] = mat[]
10
11"""
12class Solution:
13    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
14        n: int = len(mat)
15
16        if mat == target:
17            return True
18
19        for attempt in range(3):
20            for i in range(floor(n/2)):
21                for j in range(ceil(n/2)):
22                    # print(i, j)
23                    # Change sequence no.2
24                    next_val = mat[(n-1)-j][i]
25                    mat[(n-1)-j][i] = mat[i][j]
26                    # Change sequence no.3
27                    curr_val = mat[(n-1)-i][(n-1)-j]
28                    mat[(n-1)-i][(n-1)-j] = next_val
29                    next_val = curr_val
30                    # Change sequence no.4
31                    curr_val = mat[j][(n-1)-i]
32                    mat[j][(n-1)-i] = next_val
33                    next_val = curr_val
34                    # Change sequence no.1
35                    mat[i][j] = next_val
36            
37            # print("This Matrix:")
38            # for row in mat:
39            #     print(row)
40            if mat == target:
41                return True
42        
43        return False
44        
45
46