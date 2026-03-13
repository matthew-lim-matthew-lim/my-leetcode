# Last updated: 3/13/2026, 9:41:38 PM
1""" 
2Prerequisites [[1, 0]] means that '0' is a prerequisite of '1'. 
3
4Always do the courses that have 0 incoming edges.
5Use BFS. 
6
7Use a normal directed adjlist, and an unordered_map to keep track 
8of the number of incoming edges for each vertex.
9"""
10class Solution:
11    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
12        adjList: list[list[int]] = [ [] for i in range(numCourses) ]
13        incomingCount: list[int] = [ 0 for i in range(numCourses) ]
14
15        for prereq in prerequisites:
16            adjList[prereq[1]].append(prereq[0])
17            incomingCount[prereq[0]] += 1
18
19        q: deque[int] = deque()
20
21
22        for node, count in enumerate(incomingCount):
23            if count == 0:
24                q.append(node)
25
26        res: list[int] = []
27
28        while q:
29            curr: int = q.popleft()
30            res.append(curr)
31
32            for neigh in adjList[curr]:
33                incomingCount[neigh] -= 1
34                if incomingCount[neigh] == 0:
35                    q.append(neigh)
36
37        # print(incomingCount)
38        # print(res)
39
40        for count in incomingCount:
41            if count > 0:
42                return []
43        
44        return res