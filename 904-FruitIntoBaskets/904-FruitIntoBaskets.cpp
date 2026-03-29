// Last updated: 3/30/2026, 9:37:40 AM
1/* 
2Longest subarray with 2 distinct numbers. 
3As soon as the subarray reaches a 3rd distinct number, move the lptr.
4 */
5class Solution {
6public:
7    int totalFruit(vector<int>& fruits) {
8        unordered_map<int, int> fruit_count;
9        int n = fruits.size();
10
11        int res = 0;
12
13        int l = 0;
14        for (int r = 0; r < n; r++) {
15            fruit_count[fruits[r]]++;
16            while (fruit_count.size() > 2) {
17                fruit_count[fruits[l]]--;
18                if (fruit_count[fruits[l]] == 0) {
19                    fruit_count.erase(fruits[l]);
20                }
21                l++;
22            }
23            
24            res = max(res, r - l + 1);
25        }
26
27        return res;
28    }
29};