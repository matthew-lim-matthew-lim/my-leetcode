class Solution {
public:
    bool valid(vector<int>& ranks, int cars, long long target) {
        for (int i = 0; i < ranks.size(); i++) {
            if (cars > 0) {
                cars -= static_cast<long long>(sqrt(target / ranks[i]));   
            }
        }
        return cars <= 0;
    }

    // Find the smallest X such that f(X) is true;
    long long binarysearch(vector<int>& ranks, int cars) {
        long long lo = 0;
        long long hi = pow(cars, 2) * (*min_element(ranks.begin(), ranks.end()));
        long long bestSoFar = -1;
        // Range [lo, hi];
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (valid(ranks, cars, mid)) {
                bestSoFar = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }

        }
        return bestSoFar;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        // Binary search
        return binarysearch(ranks, cars);
    }
};