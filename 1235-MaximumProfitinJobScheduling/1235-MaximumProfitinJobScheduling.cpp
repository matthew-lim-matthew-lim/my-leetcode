// Last updated: 7/13/2025, 5:02:30 PM
/* 
Dynamic Programming?

For each point in time 'i', what is the most amount of profit we can have?

Sort by increasing ending time. Always pick the earliest available job. 
 */

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Jobs: { end, start, profit }
        vector<vector<int>> jobs;
        int n = startTime.size();

        for (int i = 0; i < n; i++) {
            jobs.push_back({ endTime[i], startTime[i], profit[i] });
        }

        sort(jobs.begin(), jobs.end());

        map<int, int> dp;

        int maxRes = 0;

        for (int currJob = 0; currJob < n; currJob++) {
            // Find the entry of the thing that ended soonest. Compare the profit at this end.
            auto it = dp.upper_bound(jobs[currJob][0]);
            int endProfit = 0;
            if (it != dp.begin()) {
                it--;
                endProfit = it->second;
            }

            dp[jobs[currJob][0]] = max(dp[jobs[currJob][0]], endProfit);

            // Find the entry of the thing that ends right before this starts. 
            it = dp.upper_bound(jobs[currJob][1]);
            int startProfit = 0;
            if (it != dp.begin()) {
                it--;
                startProfit = it->second;
            }

            dp[jobs[currJob][0]] = max(dp[jobs[currJob][0]], startProfit + jobs[currJob][2]);

            maxRes = max(maxRes, dp[jobs[currJob][0]]);
        }

        return maxRes;
    }
};