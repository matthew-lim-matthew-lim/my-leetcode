// Last updated: 4/21/2025, 12:21:12 PM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        // Seems really easy.
        long long seqMin = INT_MAX;
        long long seqMax = INT_MIN;
        long long curr = 0;
        seqMin = min(seqMin, curr);
        seqMax = max(seqMax, curr);

        for (int val : differences) {
            curr += val;
            seqMin = min(seqMin, curr);
            seqMax = max(seqMax, curr);
        }

        return (upper - lower + 1) - (seqMax - seqMin) > 0 ? (upper - lower + 1) - (seqMax - seqMin) : 0;
    }
};