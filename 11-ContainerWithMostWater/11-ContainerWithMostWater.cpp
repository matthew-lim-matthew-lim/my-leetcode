// Last updated: 7/10/2025, 2:07:00 AM
/* 
2 pointers asf
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int lPtr = 0;
        int rPtr = n - 1;

        int maxWater = 0;

        while (lPtr < rPtr) {
            int currCapacity = (rPtr - lPtr) * min(height[lPtr], height[rPtr]);
            maxWater = max(maxWater, currCapacity);
            if (height[lPtr] < height[rPtr]) {
                lPtr++;
            } else {
                rPtr--;
            }
        } 

        return maxWater;
    }
};