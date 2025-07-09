// Last updated: 7/10/2025, 12:14:55 AM
/* 
- Find the index of the largest value. 
It would be the only one where nums[i] > nums[i + 1].

Binary search from [0 .. i]
and on [i + 1..n-1]
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        auto binarySearch = [&]() {
            int lo = 0;
            int hi = n - 1;

            int bestSoFar = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                // cout << mid << " lo: " << lo << " hi: " << hi << endl;
                if (nums[mid] == target) return mid;
                if (nums[lo] == target) return lo;
                if (nums[hi] == target) return hi;

                if (nums[lo] <= nums[mid]) {
                    if (nums[lo] <= target && target <= nums[mid]) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                } else {
                    if (nums[mid] <= target && target <= nums[hi]) {
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
            }

            return -1;
        };

        return binarySearch();
    }
};