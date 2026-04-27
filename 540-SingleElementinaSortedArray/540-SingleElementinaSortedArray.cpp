// Last updated: 4/27/2026, 11:11:07 PM
1/* 
2Halve it, and then check the middle + 1. 
3If they are the same, the single element is on the left.
4If they are not the same, the single element is on the right. 
5
6The array with the number must be odd. 
7
8Is the extra element in the left or right?
9
10Left:
11- mid is even and mid+1 doesnt match it
12- mid is odd and mid+1 matches it
13
14Right:
15- mid is even and mid+1 matches it
16- mid is odd and mid+1 doesnt match it
17
18 */
19class Solution {
20public:
21    int singleNonDuplicate(vector<int>& nums) {
22        int n = nums.size();
23
24        int lo = 0;
25        int hi = n-1;
26        while (lo < hi) {
27            int mid = (lo + hi) / 2;
28            if (
29                (mid % 2 == 0 && nums[mid] != nums[mid+1]) ||
30                (mid % 2 == 1 && nums[mid] == nums[mid+1])
31            ) {
32                hi = mid;
33            } else {
34                lo = mid + 1;
35            }
36        }
37
38        return nums[hi];
39    }
40};