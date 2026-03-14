# Last updated: 3/14/2026, 7:40:16 PM
1""" 
2At each index, look at the previous 2 values and see if you can make a character using them.
3
4Use the last 2 indexes and see if they are `<= "26"`.
5Check that the first index is not `0`. 
6
7prev_digit = s[i] <= "9" and s[i] >= "1"
8prev_2_digit = s[i-1] != "0" and s[i-1:i] <= "26"
9
10dp[i] = max(
11    dp[i-1] + prev_digit,
12    dp[i-2] + prev_2_digit
13)
14
15226:
162,2,6
172,26
1822,6
19
2022:
212,2
2222
23"""
24class Solution:
25    def numDecodings(self, s: str) -> int:
26        n: int = len(s)
27        
28        dp: list[int] = [0 for i in range(n)]
29
30        dp[0] = int(s[0] <= "9" and s[0] >= "1") 
31
32        if n == 1:
33            return dp[0]
34
35        dp[1] = (
36            (dp[0] and s[1] <= "9" and s[1] >= "1") + 
37            int(s[0] != "0" and s[0:2] <= "26")
38        )
39
40        if n == 2:
41            return dp[1]
42
43        for i in range(2, n):
44            curr_digit = s[i] <= "9" and s[i] >= "1"
45            prev_digit = s[i-1] != "0" and s[i-1:i+1] <= "26"
46            print(curr_digit, prev_digit)
47
48            if not curr_digit and not prev_digit:
49                return 0
50
51            if curr_digit:
52                dp[i] += dp[i-1]
53            if prev_digit:
54                dp[i] += dp[i-2]
55
56        # print(dp)
57
58        return dp[n-1]
59