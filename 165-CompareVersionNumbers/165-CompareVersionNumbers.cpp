// Last updated: 9/23/2025, 7:56:02 PM
/* 
Every missing revision is treated as 0.
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int lptr = 0;
        int rptr = 0;
        int n = version1.size();
        int m = version2.size();
        while (lptr < n && rptr < m) {
            string s1;
            for (; lptr < n && version1[lptr] != '.'; lptr++) {
                s1 += version1[lptr];
            }
            lptr++;

            string s2;
            for (; rptr < m && version2[rptr] != '.'; rptr++) {
                s2 += version2[rptr];
            }
            rptr++;

            int s1Int = stoi(s1);
            int s2Int = stoi(s2);

            if (s1Int < s2Int) {
                return -1;
            } else if (s1Int > s2Int) {
                return 1;
            }
        }

        // Now, deal with the longer string. If it is non-zero then return the corresponding one.
        for (; lptr < n; lptr++) {
            if (version1[lptr] != '.' && version1[lptr] != '0') {
                return 1;
            }
        }

        for (; rptr < m; rptr++) {
            if (version2[rptr] != '.' && version2[rptr] != '0') {
                return -1;
            }
        }

        return 0;
    }
};