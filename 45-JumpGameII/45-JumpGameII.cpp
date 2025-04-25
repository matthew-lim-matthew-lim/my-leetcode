// Last updated: 4/25/2025, 5:19:02 PM
class Solution {
public:
// We track reachable.
// We keep track of the furthest reachable within the current reachable. 
// When we reach the end of reachable, we use the furthest one.
    int jump(vector<int>& nums) {
        int currReachable = nums[0];
        int reachable = currReachable;
        int currCost = 1; 
        int n = nums.size();
        if (n == 1) {
            return 0;
        }

        for (int i = 1; i < n - 1; i++) {
            currReachable = max(currReachable, i + nums[i]);

            if (i == reachable) {
                reachable = currReachable;
                currCost++;
            }
        }

        return currCost;
    }
};