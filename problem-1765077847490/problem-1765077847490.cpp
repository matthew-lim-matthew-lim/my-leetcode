// Last updated: 12/7/2025, 2:24:07 PM
1/*
2Seive of ethrosthanes
3*/
4class Solution {
5public:
6    int largestPrime(int n) {
7        vector<int> prime(n + 1, true);
8        for (int p = 2; p * p <= n; p++) {
9            if (prime[p] == true) {
10                for (int i = p * p; i <= n; i += p) {
11                    prime[i] = false;
12                }
13            }
14        }
15
16        // Algo
17        // Find valid numbers. 
18        vector<long long> validNumbers;
19        long long currNum = 0;
20        int res = 0;
21        for (int i = 2; i <= n; i++) {
22            if (prime[i] == true) {
23                currNum += i;
24            }
25            // cout << currNum << endl;
26            if (currNum > n) {
27                break;
28            }
29            if (prime[currNum] == true) {
30                res = currNum;
31            }
32        }
33
34        return res;
35    }
36};