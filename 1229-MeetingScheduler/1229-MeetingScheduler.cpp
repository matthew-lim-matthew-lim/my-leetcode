// Last updated: 4/9/2025, 12:47:18 AM
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        // Looks like 2 pointer. 
        int s1_p = 0;
        int s2_p = 0;

        int n1 = slots1.size();
        int n2 = slots2.size();
        while (s1_p < n1 && s2_p < n2) {
            int start = max(slots1[s1_p][0], slots2[s2_p][0]);
            int end = min(slots1[s1_p][1], slots2[s2_p][1]);

            if (end - start >= duration) {
                return { start, start + duration };
            }
            if (slots1[s1_p][1] < slots2[s2_p][1]) {
                s1_p++;
            } else {
                s2_p++;
            }
        }

        return {};
    }
};