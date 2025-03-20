class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // Just find max number of overlaps
        int currActive = 0;
        int maxActive = 0;
        
        // Turn all the intervals into events. 
        vector<vector<int>> events;
        for (vector<int> &interval : intervals) {
            // Start event
            events.push_back({ interval[0], 1 });
            // End event
            events.push_back({ interval[1], 0 });
        }

        // Sort the events
        sort(events.begin(), events.end());

        // Go through the events
        for (vector<int> &event : events) {
            if (event[1] == 1) {
                currActive++;
                maxActive = max(maxActive, currActive);
            }
            if (event[1] == 0) {
                currActive--;
            }
        }

        return maxActive;
    }
};