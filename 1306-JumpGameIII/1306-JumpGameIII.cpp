// Last updated: 7/21/2025, 9:29:20 PM
/* 
BFS
 */
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        q.push(start);
        vector<bool> visited(n, false);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (arr[x] == 0) {
                return true;
            }

            if (x + arr[x] < n && !visited[x + arr[x]]) {
                q.push(x + arr[x]);
                visited[x + arr[x]] = true;
            } 
            if (x - arr[x] >= 0 && !visited[x - arr[x]]) {
                q.push(x - arr[x]);
                visited[x - arr[x]] = true;
            }
        }

        return false;
    }
};