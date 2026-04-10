// Last updated: 4/10/2026, 1:48:47 PM
1/* 
2Easy with 3 for loops. O(n^3).
3
4Possible with binary search O(n log n).
5- (log n) different possible lengths.
6- (n) time for each check, using a sliding window.
7
8let the distance between i and j be x. 
9
10abs(i - j) + abs(j - k) + abs(k - i)
111st vs 2nd = x
122nd vs 3rd = x 
131st vs 3rd = 2x
14
15Solution = 4x.
16
17Possible for a pair for each value. 
18When you find a value, update the pair. 
19Use the values in the pair and your value to calculate the current 
20absolute value. 
21 */
22class Solution {
23public: 
24    int minimumDistance(vector<int>& nums) {
25        int n = nums.size();
26
27        unordered_map<int, deque<int>> pMap;
28
29        int res = INT_MAX;
30
31        for (int i = 0; i < n; i++) {
32            if (pMap[nums[i]].size() >= 2) {
33                int k = pMap[nums[i]].front();
34                int j = pMap[nums[i]].back();
35                res = min(res, abs(i - j) + abs(j - k) + abs(k - i));
36
37                pMap[nums[i]].pop_front();
38            }
39
40            pMap[nums[i]].push_back(i);
41        }
42
43        return res == INT_MAX ? -1 : res;
44    }
45};