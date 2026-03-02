// Last updated: 3/2/2026, 10:50:09 PM
1public class Solution {
2    public int sumOfPrimes(int n) {
3        int res = 0;
4
5        while (n % 2 == 0) {
6            n /= 2;
7            res += 2;
8        }
9
10        for (int i = 3; i <= Math.Sqrt(n); i += 2) {
11            while (n % i == 0) {
12                n /= i;
13                res += i;
14            }
15        }
16
17        if (n > 2) {
18            res += n;
19        }
20
21        // Console.WriteLine(res);
22
23        return res;
24    }
25
26    public int SmallestValue(int n) {
27        int res = sumOfPrimes(n);
28        int oldRes;
29        do {
30            oldRes = res;
31            res = sumOfPrimes(res);
32        } while (oldRes != res);
33
34        return res;
35    }
36}