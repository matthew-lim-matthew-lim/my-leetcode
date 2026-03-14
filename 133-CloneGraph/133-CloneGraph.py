# Last updated: 3/15/2026, 2:01:26 AM
1"""
2# Definition for a Node.
3class Node:
4    def __init__(self, val = 0, neighbors = None):
5        self.val = val
6        self.neighbors = neighbors if neighbors is not None else []
7"""
8""" 
9Every node for the second graph should be a node in the first graph.
10Visit the first node, and for each neighbour node in first graph:
11- Copy it in 2nd graph if it didnt exist in 2nd graph. 
12- Queue a tuple of the 1st graph node and 2nd graph node together. 
13"""
14from typing import Optional
15class Solution:
16    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
17        if not node:
18            return None
19
20        head: Node = Node(node.val)
21
22        node_map: dict[int, Node] = {}
23
24        q: deque[tuple[Node, Node]] = deque()
25        q.append((node, head))
26        node_map[head.val] = head
27
28        visited: set[int] = set({head.val})
29
30        while q:
31            g1_node, g2_node = q.popleft()
32            
33            for neigh in g1_node.neighbors:
34                if neigh.val not in node_map:
35                    node_map[neigh.val] = Node(neigh.val)
36
37                g2_node.neighbors.append(node_map[neigh.val])
38                if neigh.val in visited:
39                    continue
40                visited.add(neigh.val)
41                q.append((neigh, node_map[neigh.val]))
42
43        return head
44