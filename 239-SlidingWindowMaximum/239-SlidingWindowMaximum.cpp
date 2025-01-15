class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Easy using a cpp ordered map. An ordered map in cpp is ordered by key in increasing order.
        vector<int> res;
        int l_ptr = 0;
        map<int, int> nums_count;
        for (int r_ptr = 0; r_ptr < nums.size(); r_ptr++) {
            nums_count[nums[r_ptr]]++;
            if (r_ptr - l_ptr + 1 == k) {
                res.push_back(nums_count.rbegin()->first);
                nums_count[nums[l_ptr]]--;
                if (nums_count[nums[l_ptr]] == 0) nums_count.erase(nums[l_ptr]);
                l_ptr++;
            }
        }
        return res;
    }
};