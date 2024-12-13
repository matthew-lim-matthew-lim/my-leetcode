class Solution {
public:
    long long findScore(vector<int>& nums) {
        // Priority Queue, with {val, index}.
        // Pop the first one, add it to the sum, and add the two adjacent indicies to a set of marked indicides.
        // Whenever we pop again, if the indicies are in the set of marked indicides, pop again.

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        long long sum = 0;

        unordered_set<int> marked;

        while (!pq.empty()) {
            int val = pq.top()[0];
            int index = pq.top()[1];
            pq.pop();

            if (marked.contains(index)) {
                continue;
            }

            sum += val;

            if (index - 1 >= 0) marked.insert(index - 1);
            if (index + 1 < nums.size()) marked.insert(index + 1);
        }

        return sum;
    }
};