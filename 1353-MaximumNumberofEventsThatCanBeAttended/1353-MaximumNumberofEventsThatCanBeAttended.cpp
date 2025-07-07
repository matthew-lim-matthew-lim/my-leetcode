// Last updated: 7/8/2025, 12:59:11 AM
/* 
For each one, if multiple events are occurring simultaneously, attend the unvisited one ending soonest. 

Priority queue for event end dates.
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int largest = 0;
        for (const vector<int> &event : events) {
            largest = max(largest, max(event[0], event[1]));
        }
        int n = events.size();

        int eventsAttended = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        int currEvent = 0;
        for (int i = 1; i <= largest; i++) {
            while (currEvent < n && events[currEvent][0] <= i) {
                pq.push(events[currEvent][1]);
                currEvent++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty() && pq.top() >= i) {
                eventsAttended++;
                pq.pop();
            }
        }

        return eventsAttended;
    }
};