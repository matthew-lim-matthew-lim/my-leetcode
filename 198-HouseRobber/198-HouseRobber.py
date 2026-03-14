# Last updated: 3/14/2026, 2:59:13 PM
1"""
2dp[i] = max[dp[i-1], dp[i-2] + nums[i])
3"""
4class Solution:
5    def rob(self, nums: List[int]) -> int:
6        n: int = len(nums)
7
8        if n == 1:
9            return nums[0]
10        elif n == 2:
11            return max(nums[0], nums[1]) 
12
13        prev: int = nums[0]
14        curr: int = max(nums[0], nums[1])
15
16        for i in range(2, n):
17            new_curr = max(curr, prev + nums[i])
18            prev = curr
19            curr = new_curr
20
21        return new_curr