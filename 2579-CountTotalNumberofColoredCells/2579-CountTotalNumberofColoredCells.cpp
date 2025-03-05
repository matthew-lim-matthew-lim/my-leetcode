class Solution {
public:
    long long coloredCells(int _n) {
        unsigned long long n = _n;
        return 1 + 2 * (n-1) * (n);
    }
};