class Solution {
public:
    void backtrack(
        vector<int>& candidates, 
        vector<vector<int>>& res, 
        vector<int>& curr, 
        int& curr_sum, 
        int curr_index,
        int& target
    ) {
        if (curr_sum == target) {
            res.push_back(curr);
            return;
        } else if (curr_sum > target) {
            return;
        }

        for (int i = curr_index; i < candidates.size(); i++) {
            if (i > curr_index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            curr_sum += candidates[i];
            backtrack(candidates, res, curr, curr_sum, i + 1, target);
            curr_sum -= candidates[i];
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Similar way of dealing with dupicates as 3Sum. 
        // Sort.
        // If current index is the same as the previous, then move it forwards?

        // If we already had value val in index i, then we shouldnt bother checking another one 
        // with value val in index i. 

        sort(candidates.begin(), candidates.end());        

        vector<vector<int>> res;
        vector<int> curr = {};
        int curr_sum = 0;

        backtrack(candidates, res, curr, curr_sum, 0, target);

        return res;
    }
};