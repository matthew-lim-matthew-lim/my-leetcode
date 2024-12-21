class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Toplogical sorting.
        // We want to process the courses with indegree 0 first.
        unordered_map<int, vector<int>> adj_list;
        vector<int> indegree(numCourses, 0);
        for (vector<int>& prereq : prerequisites) {
            adj_list[prereq[0]].push_back(prereq[1]);
            indegree[prereq[1]]++;
        }
        
        queue<int> q;
        // Add items with indegree 0 to the queue.
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process queue
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int course : adj_list[curr]) {
                indegree[course]--;
                if (indegree[course] == 0) {
                    q.push(course);
                }
            }
        }

        for (int indeg : indegree) {
            if (indeg != 0) {
                return false;
            }
        }

        return true;
    }
};