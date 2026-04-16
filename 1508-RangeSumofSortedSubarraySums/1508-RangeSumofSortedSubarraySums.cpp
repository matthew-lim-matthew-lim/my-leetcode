// Last updated: 4/17/2026, 12:02:21 AM
1/* 
2
3 */
4class Solution {
5public:
6    int rangeSum(vector<int>& nums, int n, int left, int right) {
7        vector<int> subSum;
8        for (int i = 0; i < n; i++) {
9            for (int j = i; j < n; j++) {
10                int currSum = 0;
11                for (int k = i; k <= j; k++) {
12                    // cout << i << " " << j << " " << k << endl;
13                    currSum += nums[k];
14                }
15                subSum.push_back(currSum);
16            }
17        }
18
19        sort(subSum.begin(), subSum.end());
20
21        // for (int i = 0; i < subSum.size(); i++) {
22        //     cout << subSum[i] << endl;
23        // }
24
25        long long res = 0;
26
27        for (int i = left-1; i <= right-1; i++) {
28            res += subSum[i];
29            res %= 1'000'000'007;
30        }
31
32        return res;
33    }
34};