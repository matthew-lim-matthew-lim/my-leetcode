# Last updated: 3/14/2026, 2:57:09 PM
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
13        dp: list[int] = [ 0 for i in range(n) ]
14
15        dp[0] = nums[0]
16        dp[1] = max(nums[0], nums[1])
17
18        for i in range(2, n):
19            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
20
21        return dp[n-1]