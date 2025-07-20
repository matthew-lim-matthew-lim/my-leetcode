// Last updated: 7/20/2025, 9:24:39 PM
/* 
Use triangle inequality theorem.

a + b > c

 */
class Solution {
public:
    bool isValid(int a, int b, int c) {
        return a + b > c;
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    res += isValid(nums[i], nums[j], nums[k]);
                }
            }
        }

        return res;
    }
};