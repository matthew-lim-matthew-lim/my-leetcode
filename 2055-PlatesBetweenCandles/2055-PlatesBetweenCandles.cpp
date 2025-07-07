// Last updated: 7/8/2025, 1:58:05 AM
/* 
Prefix sum.
Each index, number of plates to the left. 
l_ptr shift right to a candle.
r_ptr shift left to a candle.
 */

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        int totalPlates = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                totalPlates++;
            }
        }


        vector<int> prefixSumLeft(n, 0);
        vector<int> prefixSumRight(n, 0);
        int plateCount = 0;
        int lastCandlePlateCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                plateCount++;
            } else {
                lastCandlePlateCount = plateCount;
            }
            prefixSumLeft[i] = lastCandlePlateCount;
        }

        plateCount = 0;
        lastCandlePlateCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*') {
                plateCount++;
            } else {
                lastCandlePlateCount = plateCount;
            }
            prefixSumRight[i] = lastCandlePlateCount;
        }

        vector<int> res(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int l_ptr = queries[i][0];
            int r_ptr = queries[i][1];

            res[i] = max(0, prefixSumLeft[r_ptr] + prefixSumRight[l_ptr] - totalPlates);
        }

        return res;
    }
};