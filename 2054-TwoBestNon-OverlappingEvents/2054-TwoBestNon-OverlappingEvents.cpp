class Solution {
public:
    static bool SORT_END_FIRST(const vector<int>& a, const vector<int>&b) {
        if (a[1] != b[1]) {
            return a[1] < b[1];
        }

        if (a[0] != b[0]) {
            return a[0] < b[0];
        }

        return a[2] < b[2];
    }

    bool valid(vector<vector<int>>& events, vector<int>& selected_event, int i) {
        // If the selected event is inside the current event, return false. 
        if (events[i][0] >= selected_event[0] || events[i][1] >= selected_event[0]) {
            return false;
        } 
        return true;
    }

    // Find the largest X such that f(X) is true;
    int binarysearch(vector<vector<int>>& events, vector<int>& selected_event) {
        int lo = 0;
        int hi = events.size() - 1;
        int bestSoFar = -1;
        // Range [lo, hi];
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (valid(events, selected_event, mid)) {
                bestSoFar = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return bestSoFar;
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        // YOU CAN ONLY CHOOSE AT MOST 2!!!
        sort(events.begin(), events.end(), SORT_END_FIRST);

        vector<int> dp(events.size(), 0);
        // Prefix dp to find the maximum value up to an interval
        for (int i = 0; i < events.size(); i++) {
            if (i == 0) {
                dp[i] = events[i][2];
            } else {
                dp[i] = max(dp[i - 1], events[i][2]);
            }
        }

        int curr_max = 0;
        // For each interval, find the pair that works with binary search
        for (int i = 0; i < events.size(); i++) {
            int bestSoFar = binarysearch(events, events[i]);
            if (bestSoFar == -1) {
                curr_max = max(curr_max, events[i][2]);
            } else {
                curr_max = max(curr_max, dp[bestSoFar] + events[i][2]);
            }
        }

        return curr_max;
    }
};