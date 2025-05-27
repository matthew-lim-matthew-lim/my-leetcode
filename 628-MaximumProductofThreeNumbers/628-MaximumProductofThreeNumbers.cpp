// Last updated: 5/27/2025, 10:31:21 PM
class Solution {
public:
/* 
Sort it.
 */

    int maximumProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, std::greater<int>> pq1;
        priority_queue<int> pq2;

        for (int num : nums) {
            if (pq1.size() >= 3 && num > pq1.top()) {
                pq1.pop();
            }
            if (pq2.size() >= 2 && num < pq2.top()) {
                pq2.pop();
            }
            if (pq1.size() < 3) pq1.push(num);
            if (pq2.size() < 2) pq2.push(num);
        }

        int res1 = pq2.top();
        pq2.pop();
        res1 *= pq2.top();
        pq2.pop();
        int res2 = pq1.top();
        pq1.pop();
        res2 *= pq1.top();
        pq1.pop();
        res2 *= pq1.top();
        res1 *= pq1.top();
        pq1.pop();

        return max(res1, res2);
    }
};