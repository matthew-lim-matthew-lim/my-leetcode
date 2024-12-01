class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Fastest is by using a dict

        unordered_map<int, int> int_count;

        for (int val : arr) {
            int_count[val]++;
        }

        for (int val : arr) {
            if (val == 0) {
                if (int_count[val] > 1) {
                    return true;
                }
            } else if (int_count.contains(val * 2)) {
                return true;
            }
        }

        return false;
    }
};