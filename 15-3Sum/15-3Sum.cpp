// Last updated: 7/13/2025, 1:14:44 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        unordered_set<string> uSet;

        vector<vector<int>> res;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0 && 
                    i != j && 
                    i != k && 
                    j != k
                ) {
                    string key = to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]);
                    if (!uSet.contains(key)) {
                        res.push_back({ nums[i], nums[j], nums[k] });
                        uSet.insert(key);
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