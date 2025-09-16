// Last updated: 9/16/2025, 11:58:02 PM
/* 
Backtracking
 */

class Solution {
public:
    vector<int> nums_;
    void backtrack(vector<vector<int>> &result, vector<int> curr, unordered_set<int> used) {
        if (used.size() == nums_.size()) {
            result.push_back(curr);
            return;
        }
        for (int val : nums_) {
            if (used.contains(val)) {
                continue;
            }
            curr.push_back(val);
            used.insert(val);
            backtrack(result, curr, used);
            used.erase(val);
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        nums_ = nums;
        unordered_set<int> used;
        vector<vector<int>> result;

        backtrack(result, {}, used);

        return result;
    }
};