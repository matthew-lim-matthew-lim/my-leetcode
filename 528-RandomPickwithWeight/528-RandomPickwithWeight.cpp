class Solution {
public:
    vector<int> indexRange;
    int sum = 0;
    Solution(vector<int>& w) {
        // Use rand() to generate the random number in the range [0, sum].
        // Have the start of each interval in an array. 
        // Use std::lower_bound() to find the iterator with the lower value we need.
        // Get the index back using (it - vec.begin()). 
        int n = w.size();
        indexRange = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            indexRange[i] = sum;
            sum += w[i];
        }
    }
    
    int pickIndex() {
        int rangeValue = rand() % sum;
        // std::lower_bound finds the first value that is >= the current value. 
        // We want to find the largest value that is smaller than the current value. 
        // Therefore, whatever element std::lower_bound finds, is 1 index larger
        // than the index of the element we actually want. 
        auto it = lower_bound(indexRange.begin(), indexRange.end(), rangeValue);
        if (it == indexRange.end() || *it > rangeValue) {
            it--;
        }
        return distance(indexRange.begin(), it);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */