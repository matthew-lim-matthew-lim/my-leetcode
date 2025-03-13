class Solution {
public:
    bool isZeroArray(vector<int> nums, vector<vector<int>>& queries) {
        // Need to use a difference array to meet time complexity requirements
        vector<int> difference_array(nums.size() + 1, 0);

        for (vector<int>& query : queries) {
            difference_array[query[0]] -= query[2];
            difference_array[query[1] + 1] += query[2];
        }

        // Compute prefix sum of difference array
        for (int i = 1; i < difference_array.size(); i++) {
            difference_array[i] += difference_array[i - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + difference_array[i] > 0) {
                return false;
            }
        } 

        return true;
    }

    // Find the smallest X such that f(X) is true;
    int binarysearch(vector<int>& nums, vector<vector<int>>& queries) {
    	int lo = 0;
    	int hi = queries.size();
    	int bestSoFar = -1;
    	// Range [lo, hi];
    	while (lo <= hi) {
    		int mid = (lo + hi) / 2;
            vector<vector<int>> subarray(queries.begin(), queries.begin() + mid);
    		if (isZeroArray(nums, subarray)) {
    			bestSoFar = mid;
    			hi = mid - 1;
    		} else {
    			lo = mid + 1;
    		}
    	}
    	return bestSoFar;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // Use binary search with the difference array method

        return binarysearch(nums, queries);
    }
};