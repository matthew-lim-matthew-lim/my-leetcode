// Last updated: 7/10/2025, 1:38:52 AM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            res[i] = gas[i] - cost[i];
        }

        int index = -1;

        for (int i = 0; i < n - 1; i++) {
            if (res[i] >= 0) {
                if (index == -1) {
                    index = i;
                }
                res[i + 1] += res[i];
                res[i] = 0;
            } else {
                index = -1;
            }
        }
        if (res[n - 1] >= 0) {
            if (index == -1) {
                index = n - 1;
            }
            res[0] += res[n - 1];
            res[n - 1] = 0;
        } else {
            index = -1;
        }
        for (int i = 0; i < n - 1; i++) {
            if (res[i] >= 0) {
                if (index == -1) {
                    index = i;
                }
                res[i + 1] += res[i];
                res[i] = 0;
            } else {
                index = -1;
            }
        }
        

        if (*min_element(res.begin(), res.end()) < 0) {
            return -1;
        }

        return index;
    }
};