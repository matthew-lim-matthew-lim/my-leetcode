// Last updated: 4/4/2026, 6:07:35 PM
1/* 
2Seems really easy.
3 */
4#include <iterator>
5
6class Solution {
7public:
8    string decodeCiphertext(string encodedText, int rows) {
9        int n = rows;
10        int m = encodedText.size() / n;
11
12        int currCol = 0;
13        int i = 0;
14        int j = 0;
15
16        string res;
17
18        while (i != 0 || j != m) {
19            res += encodedText[i * m + j];
20            i++;
21            j++;
22
23            if (i >= n || j >= m) {
24                i = 0;
25                currCol++;
26                j = currCol;
27            }
28        }
29
30        int endIndex = res.find_last_not_of(' ');
31
32        return res.substr(0, endIndex + 1);
33    }
34};