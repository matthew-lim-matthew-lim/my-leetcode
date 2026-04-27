// Last updated: 4/27/2026, 9:21:11 PM
1class Solution {
2public:
3    int peakIndexInMountainArray(vector<int>& arr) {
4        int n = arr.size();
5        int lo = 0;
6        int hi = n-1;
7
8        while (lo < hi) {
9            // cout << lo << " " << hi << endl;
10            int mid = (hi + lo) / 2;
11            if (mid+1 < n && arr[mid] < arr[mid+1]) {
12                lo = mid+1;
13            } else {
14                hi = mid;
15            }
16        }
17
18        
19        return hi;
20    }
21};