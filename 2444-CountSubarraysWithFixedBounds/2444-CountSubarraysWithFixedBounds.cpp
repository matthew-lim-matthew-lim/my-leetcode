// Last updated: 4/26/2025, 1:13:11 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int n = nums.size();
        long long ans = 0;

        int lastMin  = -1;     
        int lastMax  = -1;      
        int lastBad  = -1;     

        for (int r = 0; r < n; ++r) {
            if (nums[r] < minK || nums[r] > maxK) {
                lastBad = r;
            }

            if (nums[r] == minK) {
                lastMin = r;  
            }    
            if (nums[r] == maxK) {
                lastMax = r;
            }       

            int earliestOK = min(lastMin, lastMax);
            if (earliestOK > lastBad) {
                ans += earliestOK - lastBad;     
                // cout << "r: " << r << ", added: " << earliestOK - lastBad << endl;
            }
        }
        return ans;
    }
};
