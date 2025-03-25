// Last updated: 3/25/2025, 12:58:11 PM
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Go through each possible Y cut and each possible X cut. 
        // Probably 2 pointers.
        // Can do it with an event system. 
        // We can only make a cut when 0 are active. 
        // And we can't make a cut before the first event and after the last event. 
        vector<vector<int>> xEvents;
        vector<vector<int>> yEvents;

        for (vector<int> &rectangle : rectangles) {
            xEvents.push_back({ rectangle[0], 1 });
            xEvents.push_back({ rectangle[2], 0 });
            yEvents.push_back({ rectangle[1], 1 });
            yEvents.push_back({ rectangle[3], 0 });
        }
        

        // Determine if xEvent is possible
        sort(xEvents.begin(), xEvents.end());
        int currXEvents = 0;
        int validX = 0;
        for (vector<int> &xEvent : xEvents) {
            if (xEvent[1] == 1) {
                currXEvents++;
            } else {
                currXEvents--;
            }
            if (currXEvents == 0) {
                validX++;
            }
        }
        validX--;
        cout << validX << endl;
        
        sort(yEvents.begin(), yEvents.end());
        int currYEvents = 0;
        int validY = 0;
        for (vector<int> &yEvent : yEvents) {
            if (yEvent[1] == 1) {
                currYEvents++;
            } else {
                currYEvents--;
            }
            if (currYEvents == 0) {
                validY++;
            }
        }
        validY--;
        cout << validY << endl;

        return (validX >= 2 || validY >= 2);
    }
};