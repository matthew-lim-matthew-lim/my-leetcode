// Last updated: 12/7/2025, 3:01:44 PM
1/* 
2Need to do in O(n).
3
4Start from right to left obviously.
5
65 + 7 = 12 -> F
7
86 + 3 + 2 = 11 -> P
9
10- Sliding window!??!
11
123 + 4 = 7 -> P (1)
133 + 6 + 2 -> 11 -> p (2) Used
143 + 6 + 7 + 5 -> 21 -> F
156 + 2 -> 8 -> p (1) Used
166 + 7 + 5 -> 18 -> F
177 + 5 -> 12 -> F
18*/
19class Solution {
20public:
21    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
22        int n = damage.size();
23        vector<int> prefixSum(n + 1, 0);
24        for (int i = 0; i < n; i++) {
25            prefixSum[i + 1] = prefixSum[i] + damage[i];
26        }
27
28        long long res = 0;
29        for (int i = 0; i < n; i++) {
30            auto it = lower_bound(prefixSum.begin(), prefixSum.begin() + i + 1, (prefixSum[i + 1] - hp + requirement[i]));
31            int validIndex = distance(prefixSum.begin(), it);
32            if (validIndex <= i) {
33                res += (i - validIndex + 1);
34            }
35        }
36
37        return res;
38    }
39};