// Last updated: 7/13/2025, 10:52:52 PM
/* 
All combinations of 4 indicies a, b, c, d.


*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        unordered_map<int, unordered_set<int>> uMap; 

        for (int i = 0; i < n - 3; i++) {

            for (int j = i + 1; j < n - 2; j++) {
                int lptr = j + 1;
                int rptr = n - 1;

                if (uMap.contains(nums[i]) && uMap[nums[i]].contains(nums[j])) {
                    continue;
                }

                uMap[nums[i]].insert(nums[j]);

                // cout << i << " " << j << endl;

                while (lptr < rptr) {
                    if ((long long)nums[i] + (long long)nums[j] + (long long)nums[lptr] + (long long)nums[rptr] 
                            == (long long)target
                        ) {
                        res.push_back({ nums[i], nums[j], nums[lptr], nums[rptr] });
                        while (lptr < rptr && nums[lptr] == nums[lptr + 1]) lptr++;
                        while (lptr < rptr && nums[rptr] == nums[rptr - 1]) rptr--;
                        lptr++;
                        rptr--;
                    } else {
                        if ((long long)nums[i] + (long long)nums[j] + (long long)nums[lptr] + (long long)nums[rptr] 
                            < (long long)target
                        ) {
                            lptr++;
                        } else {
                            rptr--;
                        }
                    }   
                }
            }
        }

        return res;
    }
};