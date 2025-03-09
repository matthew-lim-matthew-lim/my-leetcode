class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // Looks like sliding window. 
        // If you come accross something that breaks the sliding window, then move the l_ptr 
        // right until it doesn't break it any more. 
        // Since it's a circle, we alos need to cover the cases where (colors.size() - l_ptr <= k) 
        // and (r_ptr < k), meaning that it wraps over the end of the colors array.
        int res = 0;
        int r_ptr = 1;
        int l_ptr = 0;
        int n = colors.size();
        while (r_ptr < n) {
            if (colors[r_ptr] == colors[r_ptr - 1]) {
                l_ptr = r_ptr;
            }
            if (r_ptr - l_ptr + 1 == k) {
                cout << l_ptr << " " << r_ptr << endl;
                l_ptr++;
                res++;
            }
            r_ptr++;
        }

        // Wrap around
        // Check if the wrap around results in the alternating we want
        r_ptr = 0;
        while (r_ptr < k - 1) {
            if ((r_ptr == 0 && colors[0] == colors[n - 1]) || 
                (r_ptr != 0 && colors[r_ptr] == colors[r_ptr - 1])
            ) {
                l_ptr = r_ptr;
            }
            if ((r_ptr + 1) + (n - l_ptr) == k) {
                cout << l_ptr << " " << r_ptr << endl;
                l_ptr++;
                res++;
            }
            r_ptr++;
        }

        return res;
    }
};