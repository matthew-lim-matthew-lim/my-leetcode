class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // For each one, consider what happens if you bought each of the 'costs' tickets; 1, 7, or 30. 
        // opt(day(i)) = min(opt(day(i - 1)) + costs[0], opt(day(i - 7)) + costs[1], opt((i - 30)) + costs[2]);
        // day() is a helper function that gets the day index in the days array when you use a ticket.
        // day() can just floor to the index of the largest valid value. 

        vector<int> dp(days.size() + 1, INT_MAX);
        dp[0] = 0;

        // for (int i = 0; i < days.size(); i++) {
        //     dp[i] = min(dp[day(i, 1)] + costs[0], dp[day(i, 7)] + costs[1], dp[day(i, 30)] + costs[2]);
        // }

        days.insert(days.begin(), 0);

        cout << "days.size(): " << days.size() << endl;

        for (int i = 1; i < days.size(); i++) {
            // Go backwards in 'days' to find the index covered outside the spans of last 1, 7, and 30 days.
            int next_after_1_day = i;
            int next_after_7_day = i;
            int next_after_30_day = i;
            int curr_day_index = i;
            for (int j = 1; j <= 30; j++) {
                cout << "i: " << i << " j: " << j << endl;
                cout << "i - j: " << i - j << endl;
                if (days[curr_day_index] > days[i] - j && curr_day_index > 0) {
                    curr_day_index--;
                }
                cout << "curr_day_index: " << curr_day_index << endl;
                if (j <= 1) {
                    next_after_1_day = curr_day_index;
                } 
                if (j <= 7) {
                    next_after_7_day = curr_day_index;
                }
                if (j <= 30) {
                    next_after_30_day = curr_day_index;
                }
            }
            cout << i << endl;
            cout << "next_after_1_day: " << next_after_1_day << endl;
            cout << "next_after_7_day: " << next_after_7_day << endl;
            cout << "next_after_30_day: " << next_after_30_day << endl;
            dp[i] = min({dp[next_after_1_day] + costs[0], dp[next_after_7_day] + costs[1], dp[next_after_30_day] + costs[2]});
        }

        for (int i = 0; i < dp.size(); i++) {
            cout << dp[i] << endl;
        }

        return dp[days.size() - 1];
    }
};