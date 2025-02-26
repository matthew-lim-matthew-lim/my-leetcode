class SparseVector {
    
    int[] nums;
    SparseVector(int[] nums) {
        this.nums = nums;
    }
	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {        
        int n = nums.length;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i] * vec.nums[i];
        }        
        return sum;
    }
}