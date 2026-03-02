// Last updated: 3/2/2026, 10:35:13 PM
1/* 
2Go from.
3From 1 up to sqrt(n).
4*/
5class Solution {
6public:
7    int sumPrimeNumbers(int n) {
8        int res = 0;
9        while (n % 2 == 0) {
10            // cout << "YOYO" << endl;
11            n /= 2;
12            res += 2;
13        }
14
15        for (int i = 3; i <= sqrt(n); i += 2) {
16            while (n % i == 0) {
17                n /= i;
18                res += i;
19            }
20        }
21
22        if (n > 2) {
23            res += n;
24        }
25
26        // cout << res << endl;
27        return res;
28    }
29
30    int smallestValue(int n) {
31        int res = sumPrimeNumbers(n);
32        int oldRes;
33        do {
34            oldRes = res;
35            res = sumPrimeNumbers(res);
36        } while (res != oldRes);
37
38        return res;
39    }
40};
41
42