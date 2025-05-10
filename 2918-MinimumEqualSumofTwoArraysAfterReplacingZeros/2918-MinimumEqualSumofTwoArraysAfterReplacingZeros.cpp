// Last updated: 5/10/2025, 9:39:05 PM
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        // Iterate over nums1 and nums2. Keep track of count of zeros. 
        // If both have `> 0` zeros, then return the larger 
        // `nums1.sum() + |nums1ZeroCount|`. 
        // If one has `== 0` zeros, then check if that one is 
        // `<= nums1.sum() + |nums1ZeroCount|`. 
        int nums1ZeroCount = 0;
        long long nums1Sum = 0;
        int nums2ZeroCount = 0;
        long long nums2Sum = 0;

        for (int &val : nums1) {
            if (val == 0) {
                nums1ZeroCount++;
            } else {
                nums1Sum += val;
            }
        }

        for (int &val : nums2) {
            if (val == 0) {
                nums2ZeroCount++;
            } else {
                nums2Sum += val;
            }
        }

        if (nums1ZeroCount > 0 && nums2ZeroCount > 0) {
            return max(nums1Sum + nums1ZeroCount, nums2Sum + nums2ZeroCount);
        }

        if (nums1ZeroCount == 0 && nums2ZeroCount == 0) {
            return nums1Sum == nums2Sum ? nums1Sum : -1;
        }

        if (nums1ZeroCount == 0 && nums2Sum + nums2ZeroCount <= nums1Sum) {
            return nums1Sum;
        }
        if (nums2ZeroCount == 0 && nums1Sum + nums1ZeroCount <= nums2Sum) {
            return nums2Sum;
        }

        return -1;
    }
};