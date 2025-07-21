// Last updated: 7/21/2025, 9:56:46 PM
class Solution {
public:
    int jump(vector<int>& nums)
    {
        // what is the best index i can reach with x number of moves
        // 0 number 0ind
        // 1 number nums[0] ind // can reach anything in between 
        // 2 number maximum value of (index + nums[index]) index <=nums[0]
        // for (moves in 1 to n) 
        // ind = best i can reach , just take the max index+nums[index]  index <= ind 
        // when ind exceeds or equals n-1 bail out
        
        int n = nums.size();
        if(n==0) return  0 ;
        int moves = 0 ;
        vector<int> maxReachable(n,0);
        maxReachable[0] = nums[0];
        for(int i = 1 ; i < n ; i ++)
        {
            maxReachable[i] = max(maxReachable[i-1],nums[i]+i);
        }
        int ind = 0 ;
        for(;moves<=n ; ++ moves)
        {
            // i need this move
            if(ind >=n-1) return moves ;
            ind = max(ind, maxReachable[ind]);
        }
        return  -1;

            
    }
};