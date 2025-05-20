// Last updated: 5/20/2025, 11:13:40 AM
class Solution {
public:
/* 
Prefix sum
 */

    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (vector<int> &query : queries) {
            prefix[query[0]]--;
            prefix[query[1]+1]++;
        }

        int currOffset = 0;
        for (int i = 0; i < n; i++) {
            currOffset += prefix[i];
            if (currOffset + nums[i] > 0) {
                return false;
            }
        }

        return true;
    }
};