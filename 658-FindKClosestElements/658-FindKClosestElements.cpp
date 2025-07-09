// Last updated: 7/9/2025, 9:57:48 PM
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> arrProcessed = arr;
        
        for (int i = 0; i < n; i++) {
            arrProcessed[i] = abs(arrProcessed[i] - x);
        }

        int rPtr = n - 1;
        int lPtr = 0;

        while (rPtr - lPtr + 1 > k) {
            if (arrProcessed[rPtr] > arrProcessed[lPtr]) {
                rPtr--;
            } else if (arrProcessed[rPtr] < arrProcessed[lPtr]) {
                lPtr++;
            } else {
                rPtr--;
            }
        }

        return vector<int>(arr.begin() + lPtr, arr.begin() + rPtr + 1);
    }
};