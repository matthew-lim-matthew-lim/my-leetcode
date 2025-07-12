// Last updated: 7/13/2025, 1:23:54 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort the array nums first 
        //now we want to find i,j,k such that nums[i]+nums[j]+nums[k]==0
        //loop from 0->n if at any point nums[i]>0 there is no point searching further(since sorted)
        //fix nums[i] then set j=i+1 and solve two sum with target=nums[i]
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                break;
            }
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int target=-1*nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k]==nums[k-1])k--;
                    j++;
                    k--;
                    //move both to avoid duplicates
                }else if(nums[j]+nums[k]<target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};