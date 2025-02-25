class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        deque<int> dq;
        for (int num : nums) {
            dq.push_back(num);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = dq.front();
                dq.pop_front();      
            } else {
                nums[i] = dq.back();
                dq.pop_back();
            }
        }
    }
};