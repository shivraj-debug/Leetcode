class Solution {
public:
    
    vector<int> dp;

    int jump(vector<int>& nums) {
     
        dp.resize(nums.size()+1,-1);
        return solve(nums,0);

        
    }

    int solve(vector<int>& nums,int i){

        if(i>=nums.size()-1) return 0;

        if(nums[i]==0) return 1e9;

         if(dp[i]!=-1) return dp[i];
        
        int ans=1e9;
        for(int l=1;l<=nums[i];l++){
            
            ans=min(ans,1+solve(nums,i+l));
            
        }

        return dp[i]=ans;
    }
};