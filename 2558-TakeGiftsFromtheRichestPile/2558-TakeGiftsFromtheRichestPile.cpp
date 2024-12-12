class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for (int val : gifts) {
            pq.push(val);
        }

        for (int i = 0; i < k; i++) {
            int top = pq.top();
            pq.pop();
            pq.push(floor(sqrt(top)));
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};