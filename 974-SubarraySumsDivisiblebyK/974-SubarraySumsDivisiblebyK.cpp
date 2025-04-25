// Last updated: 4/25/2025, 2:32:29 PM
class Solution {
public:
// Prefix Sums surely
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> complimentMap; 
        int n = nums.size();
        int curr;
        int prev = 0;
        complimentMap[0] = 1;
        int res = 0;
        for (int i = 1; i < n + 1; i++) {
            curr = prev + nums[i - 1];
            
            res += complimentMap[((curr % k) + k) % k];

            complimentMap[((curr % k) + k) % k]++;

            prev = curr;
        }

        return res;
    }
};