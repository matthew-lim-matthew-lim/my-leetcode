class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int prev_max_index = 0;
        int carry_vol = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= height[prev_max_index]) {
                res += carry_vol;
                carry_vol = 0;
                prev_max_index = i;
            } else {
                carry_vol += height[prev_max_index] - height[i];
            }
        }
        cout << prev_max_index;

        int rev_prev_max_index = height.size() - 1;
        carry_vol = 0;
        for (int i = height.size() - 1; i >= prev_max_index; i--) {
            if (height[i] >= height[rev_prev_max_index]) {
                res += carry_vol;
                carry_vol = 0;
                rev_prev_max_index = i;
            } else {
                carry_vol += height[rev_prev_max_index] - height[i];
            }
        }

        return res;
    }
};