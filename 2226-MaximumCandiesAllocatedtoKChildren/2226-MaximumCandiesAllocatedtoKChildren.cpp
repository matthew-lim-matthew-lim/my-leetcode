class Solution {
public:
    bool possible(vector<int>& candies, long long k, long long target) {
        if (target == 0) return true;
        
        for (int val : candies) {
            k -= val / target; 
        }

        return k <= 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        // Binary search to find the number of candies to allocate to each child.
        // Make a verifying function that checks greedily if that number of candies is possible. 

        long long lo = 0;
        long long hi = INT_MAX;
        long long bestSoFar = (lo + hi) / 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (possible(candies, k, mid)) {
                bestSoFar = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return bestSoFar;
    }
};