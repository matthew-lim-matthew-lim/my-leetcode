// Last updated: 4/30/2025, 5:06:14 PM
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            int numDigits = 0;
            while (num > 0) {
                num /= 10;
                numDigits++;
            }
            res += (numDigits % 2 == 0);
        }

        return res;
    }
};