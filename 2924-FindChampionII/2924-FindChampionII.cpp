class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // A team is the champion simply if they exist in the edge
        // list as a source but not a destination.
        
        // Pass twice.
        // 1st time: Add all sources to the source set.
        // 2nd time: Remove all the destinations from the source set. 
        // If the source set is size 1, return that value. Otherwise return -1. 

        unordered_set<int> source_set;

        // Add all sources to the source set
        for (int i = 0; i < n; i++) {
            source_set.insert(i);
        }

        // Remove all the destinations from the source set
        for (vector<int>& edge : edges) {
            source_set.erase(edge[1]);
        }

        if (source_set.size() == 1) {
            return *source_set.begin();
        } else {
            return -1;
        }
    }
};