// Last updated: 5/6/2025, 12:48:43 PM
class Solution {
public:
/* 
Got rejected from my dream company after giving it my all.
Not sure if I'll make it.
Bruh pleaseeee I want to do this so bad! I like low latency HPC.
Bro pleassssseee!!!!!
*/

    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            res[i] = nums[nums[i]];
        }

        return res;
    }
};