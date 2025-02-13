class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Min-heap.
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int res = 0;
        while (pq.top() < k) {
            res++;
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            pq.push(min(a, b) * 2 + max(a, b));
        }

        return res;
    }
};