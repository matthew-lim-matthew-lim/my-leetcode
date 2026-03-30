// Last updated: 3/30/2026, 6:55:31 PM
1/* 
2multiset
3or
4monotonic increasing
5
6You can do this with 2 multisets for sure.
7
8lower.size() = x
9upper.size() = k - lower.size() = k - x
10 */
11class Solution {
12public:
13    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
14        multiset<int> lower;
15        multiset<int> upper;
16
17        int n = nums.size();
18
19        for (int i = 0; i < k; i++) {
20            lower.insert(nums[i]);
21        }
22
23        for (int i = x; i < k; i++) {
24            upper.insert(*prev(lower.end()));
25            lower.erase(prev(lower.end()));
26        }
27
28        vector<int> res;
29        res.push_back(min(*prev(lower.end()), 0));
30
31        for (int i = k; i < n; i++) {
32            if (lower.empty() || *prev(lower.end()) >= nums[i]) {
33                lower.insert(nums[i]);
34            } else {
35                upper.insert(nums[i]);
36            }
37
38            if (lower.contains(nums[i-k])) {
39                lower.erase(lower.find(nums[i-k]));
40            } else {
41                upper.erase(upper.find(nums[i-k]));
42            }
43
44            while (lower.size() > x) {
45                upper.insert(*prev(lower.end()));
46                lower.erase(prev(lower.end()));
47            }
48            while (upper.size() > k - x) {
49                lower.insert(*upper.begin());
50                upper.erase(upper.begin());
51            }
52
53            // cout << lower.size() << " " << upper.size() << endl;
54            // cout << *prev(lower.end()) << endl;
55
56            res.push_back(min(*prev(lower.end()), 0));
57        }
58
59        return res;
60    }
61};