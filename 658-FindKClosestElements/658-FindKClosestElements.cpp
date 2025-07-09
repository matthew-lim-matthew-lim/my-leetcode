// Last updated: 7/9/2025, 9:58:56 PM
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int rPtr = n - 1;
        int lPtr = 0;

        while (rPtr - lPtr + 1 > k) {
            if (abs(arr[rPtr] - x) > abs(arr[lPtr] - x)) {
                rPtr--;
            } else if (abs(arr[rPtr] - x) < abs(arr[lPtr] - x)) {
                lPtr++;
            } else {
                rPtr--;
            }
        }

        return vector<int>(arr.begin() + lPtr, arr.begin() + rPtr + 1);
    }
};