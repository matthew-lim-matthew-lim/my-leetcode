// Last updated: 9/16/2025, 11:25:59 PM
/* 
dp[i] is the maximum score at index 'i'. 

Max priority queue of all the values, but you keep popping the top until it is in valid range.
 */
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        pq.push({ nums[0], 0 });

        // Each value MUST be added to a value that came before it.
        for (int i = 1; i < n; i++) {
            while (pq.top().second < i - k) {
                pq.pop();
            }
            pq.push({ nums[i] + pq.top().first, i });
        }

        while (!pq.empty()) {
            if (pq.top().second == n - 1) {
                return pq.top().first;
            }
            pq.pop();
        }

        return 0;
    }
};