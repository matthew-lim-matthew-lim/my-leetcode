// Last updated: 4/5/2026, 3:19:28 PM
1/*  
2Very interesting problem. 
3Thought: Can this be solved with template metaprogramming? LOL.
4
5Will brute force work?:
6
7n <= 10^9.
8
9(10^3)^3 <= 10^9.
10
11So the biggest number that we'd need to test is (10^3) = 1,000.
12*/
13class Solution {
14public:
15    vector<int> findGoodIntegers(int n) {
16        vector<int> nums(1'000, 0);
17
18        unordered_map<int, int> entries;
19
20        for (int i = 0; i < nums.size(); i++) {
21            nums[i] = pow((i+1), 3);
22
23            for (int j = 0; j < i; j++) {
24                if (nums[i] + nums[j] <= n) {
25                    entries[nums[i] + nums[j]]++;
26                }
27            }
28        }
29
30        vector<int> res;
31
32        for (auto p : entries) {
33            if (p.second >= 2) {
34                res.push_back(p.first);
35            }
36        }
37
38        sort(res.begin(), res.end());
39
40        return res;
41    }
42};