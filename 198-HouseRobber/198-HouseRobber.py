# Last updated: 3/14/2026, 2:59:37 PM
1"""
2dp[i] = max[dp[i-1], dp[i-2] + nums[i])
3"""
4class Solution:
5    def rob(self, nums: List[int]) -> int:
6        if len(nums) == 1:
7            return nums[0]
8        elif len(nums) == 2:
9            return max(nums[0], nums[1]) 
10
11        prev: int = nums[0]
12        curr: int = max(nums[0], nums[1])
13
14        for i in range(2, len(nums)):
15            new_curr = max(curr, prev + nums[i])
16            prev = curr
17            curr = new_curr
18
19        return new_curr