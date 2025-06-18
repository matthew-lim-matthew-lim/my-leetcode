// Last updated: 6/19/2025, 12:27:25 AM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        for (int i = 0; i < n; i++) {
            curr.emplace_back(nums[i]);
            if (curr.size() == 3) {
                if (curr.back() - curr.front() > k) {
                    return {};
                } else {
                    res.emplace_back(curr);
                }
                curr.clear();
            }
        }

        return res;
    }
};