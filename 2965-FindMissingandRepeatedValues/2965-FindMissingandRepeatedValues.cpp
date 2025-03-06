class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a, n = grid.size();
        vector<int> num_freq(n*n + 1, 0);
        for(vector<int> row : grid) {
            for(int num : row) {
                if(num_freq[num] == 1)
                    a = num;
                num_freq[num]++;
            }
        }
        for(int num = 1; num <= n*n; num++)
            if(num_freq[num] == 0)
                return {a, num};
        return {-1, -1};
    }
};