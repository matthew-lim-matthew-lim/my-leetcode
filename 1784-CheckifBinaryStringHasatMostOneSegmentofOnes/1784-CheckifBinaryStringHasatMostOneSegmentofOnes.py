# Last updated: 3/6/2026, 3:47:54 PM
1class Solution:
2    def checkOnesSegment(self, s: str) -> bool:
3        foundOne = False
4        endingZeros = False
5        for c in s:
6            if c == '1':
7                foundOne = True
8                if endingZeros:
9                    return False
10            elif c == '0' and foundOne == True:
11                endingZeros = True
12
13        return True