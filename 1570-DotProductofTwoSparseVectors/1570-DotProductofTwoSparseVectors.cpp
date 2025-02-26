class SparseVector {
public:
    vector<int> v;
    
    SparseVector(vector<int> &nums) {
        v = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (int i = 0; i < vec.v.size(); i++) {
            res += v[i] * vec.v[i];
        }

        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);