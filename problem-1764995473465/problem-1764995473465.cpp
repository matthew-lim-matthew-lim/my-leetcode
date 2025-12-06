// Last updated: 12/6/2025, 3:31:13 PM
1class Solution {
2public:
3    long long sumAndMultiply(int n) {
4        long long cpy = n;
5        long long sum = 0;
6        long long curr_digits = 0;
7        long long x = 0;
8        while (cpy > 0) {
9            if (cpy % 10 != 0) {
10                x += (cpy % 10) * pow(10, curr_digits);
11                curr_digits++;
12                sum += (cpy % 10);
13            }
14            cpy /= 10;
15        }
16
17        return x * sum;
18    }
19};