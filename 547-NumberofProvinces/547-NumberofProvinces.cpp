// Last updated: 4/26/2026, 8:37:59 PM
1class UnionFind {
2private:
3    vector<int> parent;
4    vector<int> rank;
5public:
6    UnionFind(int n) {
7        parent.resize(n, 0);
8        iota(parent.begin(), parent.end(), 0);
9        rank.resize(n, 0);
10    }
11
12    int find(int a) {
13        if (a == parent[a]) {
14            return a;
15        }
16
17        return parent[a] = find(parent[a]);
18    }
19
20    void join(int a, int b) {
21        int rootA = find(a);
22        int rootB = find(b);
23
24        if (rootA == rootB) {
25            return;
26        }
27
28        if (rank[rootA] > rank[rootB]) {
29            parent[rootB] = rootA;
30        } else if (rank[rootA] < rank[rootB]) {
31            parent[rootA] = rootB;
32        } else {
33            parent[rootB] = rootA;
34            rank[rootA]++;
35        }
36    }
37
38    int uniqueParents() {
39        unordered_set<int> uniqueParents;
40        for (int i = 0; i < parent.size(); i++) {
41            uniqueParents.insert(find(i));
42        }
43
44        return uniqueParents.size();
45    }
46};
47
48class Solution {
49public:
50    int findCircleNum(vector<vector<int>>& isConnected) {
51        int n = isConnected.size();
52
53        UnionFind uf(n);
54
55        for (int i = 0; i < n; i++) {
56            for (int j = 0; j < n; j++) {
57                if (isConnected[i][j]) {
58                    uf.join(i, j);
59                }
60            }
61        }
62
63        return uf.uniqueParents();
64    }
65};