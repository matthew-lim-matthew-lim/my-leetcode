// Last updated: 3/31/2025, 12:25:55 PM
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // The left and right ends must be included.
        // Then, we need to select (k - 1) adjacent weights. 
        // We can make a max-heap and a min-heap to keep track of the adjacent weights. 
        priority_queue<long long> pqMax;
        priority_queue<long long, vector<long long>, greater<>> pqMin;

        int n = weights.size();
        for (int i = 1; i < n; i++) {
            pqMax.push(weights[i] + weights[i - 1]);
            pqMin.push(weights[i] + weights[i - 1]);
        }

        // Get the top k for both.
        long long maxScore = 0;
        long long minScore = 0;
        for (int i = 0; i < k - 1; i++) {
            maxScore += pqMax.top();
            pqMax.pop();
            minScore += pqMin.top();
            pqMin.pop();
        }

        return maxScore - minScore;
    }
};