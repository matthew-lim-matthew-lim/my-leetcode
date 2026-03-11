# Last updated: 3/11/2026, 5:23:46 PM
1class Solution:
2    def bitwiseComplement(self, n: int) -> int:
3        binary = bin(n)
4        binList = list(binary)
5
6        for i in range(2, len(binList)):
7            if binList[i] == '1':
8                binList[i] = '0'
9            else:
10                binList[i] = '1'
11
12        return int(''.join(binList[2:]), 2)