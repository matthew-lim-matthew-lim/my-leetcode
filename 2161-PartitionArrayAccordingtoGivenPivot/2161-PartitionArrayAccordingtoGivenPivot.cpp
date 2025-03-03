class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n, 0);
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                res[curr] = nums[i];
                curr++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == pivot) {
                res[curr] = nums[i];
                curr++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) {
                res[curr] = nums[i];
                curr++;
            }
        }

        return res;
    }
};