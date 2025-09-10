class Solution {
public:

    vector<int> dp;

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,-1);
        return solve(nums,0); 
    }

    bool solve(vector<int>& nums,int i){
        if(i>=nums.size()-1) return true;

        if(nums[i]==0) return false;

        if(dp[i]!=-1) return dp[i];

        for(int l=1;l<=nums[i];l++){
            if(solve(nums,i+l)) return dp[i]=1;
        }

        return dp[i]=0;
    }
};