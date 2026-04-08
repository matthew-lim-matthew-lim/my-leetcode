// Last updated: 4/8/2026, 5:42:18 PM
1/* 
2Brute force?
3 */
4class Solution {
5public:
6    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
7        for (const vector<int>& query : queries) {
8            for (int i = query[0]; i <= query[1]; i += query[2]) {
9                nums[i] = ((long long)nums[i] * (long long)query[3]) % (1'000'000'007);
10            }
11        }
12
13        int res = 0;
14        for (int num : nums) {
15            res ^= num;
16        }
17
18        return res;
19    }
20};