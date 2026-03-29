// Last updated: 3/29/2026, 3:05:03 PM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        
        if (n == 0 || k == 0) {
            return result;
        }
        
        if (k == 1) {
            return nums;
        }
        
        int num_windows = n - k + 1;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        
        for (int i = 1; i < n; ++i) {
            if (i % k == 0) {
                left[i] = nums[i];
            } else {
                left[i] = max(nums[i], left[i - 1]);
            }
            
            int endIdx = n - i - 1;
            
            if ((endIdx + 1) % k == 0) {
                right[endIdx] = nums[endIdx];
            } else {
                right[endIdx] = max(right[endIdx + 1], nums[endIdx]);
            }
        }
        
        result.resize(num_windows); // num of windows
        
        for (int i = 0; i < num_windows; ++i) {
            result[i] = max(left[i + k - 1], right[i]);
        }
        
        return result;
    }
};