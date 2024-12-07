class Solution {
public:
    bool possible(vector<int>& nums, int maxOperations, int biggest_bag) {
        int curr_size = 0;
        for (int i : nums) {
            curr_size += ceil(static_cast<double>(i) / biggest_bag);
        }

        return curr_size <= nums.size() + maxOperations;
    }

    int binary_search(vector<int>& nums, int maxOperations) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());
        int bestSoFar = -1;
        // Range [lo, hi];
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (possible(nums, maxOperations, mid)) {
                bestSoFar = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return bestSoFar;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        return binary_search(nums, maxOperations);
    }
};