// Last updated: 7/10/2025, 12:56:59 PM
/* 
Priority queue min-heap with max size k. 
vector of { count, value }
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        sort(nums.begin(), nums.end());

        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                pq.push({ count, nums[i - 1] });
                if (pq.size() > k) {
                    pq.pop();
                }
                count = 1;
            }
        }
        pq.push({ count, nums[nums.size() - 1]});
        if (pq.size() > k) {
            pq.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top()[1]);
            pq.pop();
        }

        return res;
    }
};