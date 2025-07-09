// Last updated: 7/9/2025, 8:34:38 PM
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int n = endTime.size();
        
        int maxFreeSpace = 0;
        int occupiedSpace = 0;

        int currStart = 0;
        int currEnd = 0;

        for (; currEnd <= k; currEnd++) {
            maxFreeSpace = max(maxFreeSpace, startTime[currEnd] - occupiedSpace);
            occupiedSpace += endTime[currEnd] - startTime[currEnd];
        }

        for (; currEnd < n; currStart++, currEnd++) {
            occupiedSpace -= endTime[currStart] - startTime[currStart];
            
            maxFreeSpace = max(maxFreeSpace, startTime[currEnd] - endTime[currStart] - occupiedSpace);

            occupiedSpace += endTime[currEnd] - startTime[currEnd];
        }

        return maxFreeSpace;
    }
};