// Last updated: 11/30/2025, 9:26:26 PM
1/*
2- Sum of array gives you remainder, which tells you what subarray sum you need to remove. 
3
4- While iterating through, keep track of:
5    - Map from remainder to latest index with that remainder.
6    - Keep track of the shortest length.
7 */
8
9class Solution {
10public:
11    int minSubarray(vector<int>& nums, int p) {
12        long long rem = 0;
13        for (int x : nums) {
14            rem += x;
15        }
16        rem %= p;
17        if (rem == 0) return 0;
18        int n = nums.size();
19        int currSum = 0;
20        unordered_map<int, int> rMap;
21        rMap[0] = -1;
22
23        int bestLen = INT_MAX;
24
25        for (int i = 0; i < n; i++) {
26            nums[i] %= p;
27            currSum += nums[i];
28            currSum %= p;
29            rMap[currSum] = i;
30
31            int target = (currSum - rem + p) % p;
32            if (rMap.contains(target)) {
33                // cout << i << " " << rMap[target] << endl;
34                bestLen = min(bestLen, i - rMap[target]);
35            }
36        }
37
38        return (bestLen == INT_MAX  || bestLen == n) ? -1 : bestLen;
39    }
40};