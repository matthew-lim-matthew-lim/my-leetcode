// Last updated: 7/13/2025, 1:19:13 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        set<vector<int>> vSet;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0 && 
                    i != j && 
                    i != k && 
                    j != k
                ) {
                    vector<int> newVec = { nums[i], nums[j], nums[k] };
                    if (!vSet.contains(newVec)) {
                        res.push_back(newVec);
                        vSet.insert(newVec);
                    }
                    j++;
                } else {
                    if (nums[i] + nums[j] + nums[k] < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }

        return res;
    }
};