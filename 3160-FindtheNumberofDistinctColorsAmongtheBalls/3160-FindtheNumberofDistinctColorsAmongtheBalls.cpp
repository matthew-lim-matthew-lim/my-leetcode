class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Record colour of each ball. 
        // Record count of each colour. If it reaches 0, then the curr count decreases.
        unordered_map<int, int> ballColor;
        unordered_map<int, int> colorCount;
        vector<int> res;
        int curr = 0;
        for (vector<int>& query : queries) {
            int ball = query[0];
            int color = query[1];

            if (!ballColor.contains(ball)) {
                colorCount[color]++;
                ballColor[ball] = color;
                if (colorCount[color] == 1) {
                    // This color got added
                    curr++;
                }
            } else {
                // No change in colorCount
                colorCount[ballColor[ball]]--;
                if (colorCount[ballColor[ball]] == 0) {
                    // This color got removed
                    curr--;
                }
                ballColor[ball] = color;
                colorCount[ballColor[ball]]++;
                if (colorCount[ballColor[ball]] == 1) {
                    // This color got added
                    curr++;
                }
            }
            res.push_back(curr);
        }

        return res;
    }
};