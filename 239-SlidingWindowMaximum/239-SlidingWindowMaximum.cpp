class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Using a monotonic queue
        vector<int> res;
        // val : index
        deque<pair<int, int>> mono_q;

        int l_ptr = 0;

        for (int r_ptr = 0; r_ptr < nums.size(); r_ptr++) {
            while (!mono_q.empty() && mono_q.back().first < nums[r_ptr]) {
                mono_q.pop_back();
            }
            mono_q.push_back({ nums[r_ptr], r_ptr });

            if (r_ptr - l_ptr + 1 == k) {
                while (!mono_q.empty() && mono_q.front().second <= r_ptr - k) {
                    mono_q.pop_front();
                }
                res.push_back(mono_q.front().first);
                l_ptr++;
            }
        }
        return res;
    }
};