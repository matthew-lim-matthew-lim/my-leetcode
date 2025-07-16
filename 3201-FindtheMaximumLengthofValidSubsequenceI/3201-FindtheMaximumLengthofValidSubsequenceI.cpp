// Last updated: 7/16/2025, 6:05:48 PM
/* 
Adjacent values must be either:
- All the same parity.
- OR Alternating parity.

Even/Odd prev even -> AEVEN
Even/Odd prev odd -> AODD
Even only -> EVEN
Odd only -> ODD
 */
class Solution {

public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int oddFirst = 0;
        int evenFirst = 0;
        int numOdd = 0;
        int numEven = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                numEven++;
                if (evenFirst % 2 == 0) {
                    evenFirst++;
                } 
                if (oddFirst % 2 == 1) {
                    oddFirst++;
                }
            } else {
                numOdd++;
                if (oddFirst % 2 == 0) {
                    oddFirst++;
                } 
                if (evenFirst % 2 == 1) {
                    evenFirst++;
                }
            }
        }
        
        return max({oddFirst, evenFirst, numOdd, numEven});
    }
};