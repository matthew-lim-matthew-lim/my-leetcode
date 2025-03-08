class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // Sliding window size k.
        int minWhite = INT_MAX;
        int currWhite = 0;
        int n = blocks.size();
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                currWhite++;
            }
        }
        minWhite = min(minWhite, currWhite);
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') {
                currWhite++;
            }
            if (blocks[i - k] == 'W') {
                currWhite--;
            }   
            minWhite = min(minWhite, currWhite);
        } 

        return minWhite;
    }
};