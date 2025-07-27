// Last updated: 7/27/2025, 6:22:33 PM
/* 
Keep track of previous incline and decline.

If changes, then it is a hill or valley. 
 */
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int res = 0;

        int prevIncl = 0;

        for (int i = 1; i < n; i++) {
            int currIncl = 0;

            if (nums[i - 1] == nums[i]) {
                currIncl = 0;
            } else if (nums[i - 1] < nums[i]) {
                currIncl = 1;
            } else {
                currIncl = -1;
            }

            if (prevIncl == 0) {
                prevIncl = currIncl;
            }

            if (currIncl != 0 && prevIncl != currIncl) {
                prevIncl = currIncl;
                res++;
            }
        }

        return res;
    }
};