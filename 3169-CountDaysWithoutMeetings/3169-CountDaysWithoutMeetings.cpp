// Last updated: 3/24/2025, 11:37:38 AM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> events;
        for (int i = 0; i < meetings.size(); i++) {
            events.push_back({ meetings[i][0], 0 });
            events.push_back({ meetings[i][1], 1 });
        }
        sort(events.begin(), events.end());


        // for (vector<int> &event : events) {
        //     cout << event[0] << " " << event[1] << endl;
        // }

        int currMeetings = 0;
        int res = 0;
        for (int i = 0; i < events.size(); i++) {
            // cout << currMeetings << endl;
            if (currMeetings == 0) {
                int prevDay = (i == 0) ? 0 : events[i - 1][0];
                res += events[i][0] - prevDay - 1;
                // cout << events[i][0] << " prevDay: " << prevDay << endl;
            }
            if (events[i][1] == 0) {
                currMeetings++;
            } else if (events[i][1] == 1) {
                currMeetings--;
            }
        }
        if (currMeetings == 0 && events.back()[0] != days) {
            int prevDay = events.back()[0];
            res += days - prevDay;
            // cout << days << " prevDay: " << prevDay << endl;
        }

        return res;
    }
};