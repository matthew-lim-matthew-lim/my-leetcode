// Last updated: 4/14/2025, 12:03:45 PM
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        // O(n^3) maybe optimise later im very busy today
        int n = arr.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (
                        abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c
                    ) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};