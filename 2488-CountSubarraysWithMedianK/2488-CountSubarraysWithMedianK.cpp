// Last updated: 3/1/2026, 4:25:30 PM
1/*
2Note that the integers are distinct.
3
4That means there is only one 'k' in the entire array. 
5
6You could just count the numbers bigger than k and the numbers smaller than k. 
7
8For each index to the right of 'k', keep track of how many bigger and smaller. 
9
10Iterate from k leftwards, and keep track of how many bigger and smaller. 
11Try to see if there is a matching pair that had appeared on the right side. 
12
13To the left of the middle element means that we accept either: 
14- 0 bigger than k and 0 smaller than k (total odd length).
15- 1 bigger than k and 0 smaller than k (total even length).
16
17For each rhs index, track (bigger - smaller) to a set rhsSet.
18
190 = (rhs_bigger - rhs_smaller) + (lhs_bigger - lhs_smaller);
20(rhs_bigger - rhs_smaller) = -(lhs_bigger - lhs_smaller)
21
221 = (rhs_bigger - rhs_smaller) + (lhs_bigger - lhs_smaller);
23(rhs_bigger - rhs_smaller) = 1 -(lhs_bigger - lhs_smaller)
24
25For each lhs index, try:
26- rhsSet.contains(-(lhs_bigger - lhs_smaller))
27- rhsSet.contains(1-(lhs_bigger - lhs_smaller))
28 */
29class Solution {
30public:
31    int countSubarrays(vector<int>& nums, int k) {
32        unordered_map<int, int> rhsSet;
33        int n = nums.size();
34
35        int index = distance(
36            nums.begin(),
37            find(nums.begin(), nums.end(), k)
38        );
39        // cout << index << endl;
40        
41        int bigger = 0;
42        int smaller = 0;
43        for (int i = index; i < n; i++) {
44            if (nums[i] > k) {
45                bigger++;
46            } else if (nums[i] < k) {
47                smaller++;
48            }
49            rhsSet[bigger - smaller]++;
50        }
51
52        int res = 0;
53
54        bigger = 0;
55        smaller = 0;
56        for (int i = index; i >= 0; i--) {
57            if (nums[i] > k) {
58                bigger++;
59            } else if (nums[i] < k) {
60                smaller++;
61            }
62            res += rhsSet[-(bigger - smaller)];
63            res += rhsSet[1-(bigger - smaller)];
64        }
65
66        return res;
67    }
68};