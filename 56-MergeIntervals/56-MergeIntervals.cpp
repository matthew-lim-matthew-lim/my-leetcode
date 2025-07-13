// Last updated: 7/13/2025, 7:19:55 PM
/* 
Track as events, and when going from 0->1 event or from 1->0 event, start/end an interval. 
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> events;

        for (vector<int> &interval : intervals) {
            events.push_back({ interval[0], 0 });
            events.push_back({ interval[1], 1 });
        }

        sort(events.begin(), events.end());

        vector<vector<int>> res;
        int active = 0;

        int prevStamp = 0;

        for (vector<int> & event : events) {
            if (event[1] == 0) {
                active++;
                if (active == 1) {
                    prevStamp = event[0];
                }
            } else {
                active--;
                if (active == 0) {
                    res.push_back({ prevStamp, event[0] });
                }
            }
        }

        return res;
    }
};