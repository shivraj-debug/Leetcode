class Solution {
public:
    vector<vector<int>> dp;
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int>(3,-1));
        return solve(0,0,nums);
    }

    int solve(int i,int rem,vector<int>& nums){
        if(i>=nums.size()){
            if(rem==0) return 0;
            else return INT_MIN;
        }

        if(dp[i][rem]!=-1) return dp[i][rem];

        int take=nums[i]+solve(i+1,(nums[i]+rem)%3,nums);
        int skip=solve(i+1,rem,nums);

        return dp[i][rem]=max(take,skip);
    }
};