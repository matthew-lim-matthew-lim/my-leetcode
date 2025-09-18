// Last updated: 9/18/2025, 1:38:46 PM
/* 
Insert as many as you possibly can by inserting whatever interval ends soonest.
 */
class Solution {
public:
struct Order {
    bool operator()(vector<int> a, vector<int> b) const {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
};

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), Order());

        // Place intervals
        int count = 0;
        int lastEnd = INT_MIN;
        for (vector<int> interval : intervals) {
            if (interval[0] >= lastEnd) {
                lastEnd = interval[1];
                count++;
            }
        }

        return intervals.size() - count;
    }
};