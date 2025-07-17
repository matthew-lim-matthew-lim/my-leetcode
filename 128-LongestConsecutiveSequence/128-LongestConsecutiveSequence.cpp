// Last updated: 7/18/2025, 12:28:11 AM
/* 

 */

class Solution {
private:
    unordered_map<int, int> rank;
    unordered_map<int, int> parent;

public:
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void unionT(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rank[rootI] < rank[rootJ]) {
            parent[rootI] = rootJ;
        } else if (rank[rootJ] < rank[rootI]) {
            parent[rootJ] = rootI;
        } else {
            parent[rootJ] = rootI;
            rank[rootI]++;
        }
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int val : nums) {
            numSet.insert(val);
        }
        for (int val : numSet) {
            parent[val] = val;
            // cout << parent[val] << endl;
        }

        for (int num : numSet) {
            // cout << "now, " << num << endl;

            if (parent.contains(num - 1)) {
                unionT(num, num - 1);
            }
            if (parent.contains(num + 1)) {
                unionT(num, num + 1);
            }
        }

        unordered_map<int, vector<int>> parentCount;
        int res = 0;
        for (const pair<int, int> &p : parent) {
            // cout << p.first << " " << p.second << endl;
            int root = find(p.second);
            parentCount[root].push_back(p.first);
            res = max(res, (int)parentCount[root].size());
        }

        return res;
    }
};