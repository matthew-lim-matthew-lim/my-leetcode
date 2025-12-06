// Last updated: 12/6/2025, 4:19:32 PM
1/* 
2- Notice you need equal number of odds and evens in the subarray.
3- Sliding window might be hard because of the XOR. XOR is not monotonic. 
4- Use an unordered_map and keep track of the index where you first saw each prefix state.
5*/
6class Solution {
7public:
8    int maxBalancedSubarray(vector<int>& nums) {
9        unordered_map<int, unordered_map<int, int>> prefixMap;
10        prefixMap[0][0] = -1;
11        uint32_t currPrefix = 0;
12        int n = nums.size();
13
14        int res = 0;
15        int parityCount = 0;
16
17        for (int i = 0; i < n; i++) {
18            if (nums[i] % 2 == 0) {
19                parityCount++;
20            } else {
21                parityCount--;
22            }
23            currPrefix ^= (uint32_t)nums[i];
24            if (prefixMap.contains(currPrefix) &&
25                prefixMap[currPrefix].contains(parityCount)
26            ) {
27                res = max(res, i - prefixMap[currPrefix][parityCount]);
28            }
29            if (!prefixMap.contains(currPrefix) ||
30               !prefixMap[currPrefix].contains(parityCount)
31            ) {
32                prefixMap[currPrefix][parityCount] = i;
33            }
34        }
35
36        return res;
37    }
38};