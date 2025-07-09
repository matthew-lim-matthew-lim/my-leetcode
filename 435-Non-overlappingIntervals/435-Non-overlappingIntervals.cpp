// Last updated: 7/10/2025, 1:03:23 AM
/* 
Minimum number of intervals to remove. 

Sort by the 2nd value increasing. 
Add the ones that end earliest first. 
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto SORT = [](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        };

        sort(intervals.begin(), intervals.end(), SORT);

        int count = 0;
        int lastTaken = INT_MIN;
        for (const vector<int> &vec : intervals) {
            if (vec[0] >= lastTaken) {
                count++;
                lastTaken = vec[1];
            }
        }

        return intervals.size() - count;
    }
};