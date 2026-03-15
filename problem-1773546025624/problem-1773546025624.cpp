// Last updated: 3/15/2026, 2:40:25 PM
1/*
21002 - 999 = 3.
3
41'000'000'000'000'000
5
61 comma includes 0 comma. 
7So all 1 comma subtract all 0 comma.
8100,000
9
102 comma includes 1 comma and 0 comma.
11real 2 comma = 2c - 1c
12100,000,000
13- 999,999
14
15If the number is 1,000,000,000
16Then, use the value:
17999,999,999 - 999,999
18999,000,000
19
203 comma includes 2 comma, 1 comma, and 0 comma.
21real 3 comma = 3c - 2c
22Multiply this number by 3 since we use 3 commas. 
23
24Divide through in groups of 1000.
25*/
26class Solution {
27public:
28    long long countCommas(long long n) {
29        long long res = 0;
30        long long n_copy = n;
31        long long comma_count = 0;
32        while (n_copy > 999) {
33            n_copy /= 1'000;
34            comma_count++;
35            // cout << "comma_count: " << comma_count << endl;
36            long long value = min(n, (long long)(pow(10, comma_count * 3 + 3) - 1));
37            long long negative = min(n, (long long)(pow(10, (comma_count) * 3) - 1));
38            // cout << "value: " << value << endl;
39            // cout << "negative: " << negative << endl;
40            res += (value - negative) * comma_count;
41        }
42
43        return res;
44    }
45};