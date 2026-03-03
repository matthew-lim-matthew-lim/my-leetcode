// Last updated: 3/3/2026, 10:44:04 PM
1public class Solution {
2    public char[] modify(char[] s) {
3        int n = s.Length;
4        char[] res = new char[s.Length];
5
6        for (int i = 0; i < s.Length; i++) {
7            if (s[i] == '0') {
8                res[n - 1 - i] = '1';
9            } else {
10                res[n - 1 - i] = '0';
11            }
12        }
13
14        return res;
15    }
16
17    public char FindKthBit(int n, int k) {
18        char[] first = { '0' };
19
20        for (int i = 0; i < n; i++) {
21            char[] second = modify(first);
22            // Console.WriteLine(first);
23            // Console.WriteLine(second);
24
25            char[] next = new char[first.Length + 1 + second.Length];
26            Array.Copy(first, 0, next, 0, first.Length);
27            Array.Copy(second, 0, next, first.Length + 1, second.Length);
28            next[first.Length] = '1';
29            first = next;
30            // Console.WriteLine(first);
31        }
32
33        return first[k-1];
34    }
35}