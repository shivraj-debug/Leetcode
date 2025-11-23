class Solution {
public:
    vector<vector<int>> dp;
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1,vector<int>(3,INT_MIN));
        
        dp[n][0]=0;
        dp[n][1]=INT_MIN;
        dp[n][2]=INT_MIN;


        for(int i=n-1;i>=0;i--){
            for(int rem=0;rem<=2;rem++){
                int newrem=(nums[i]+rem)%3;
                int take=nums[i]+dp[i+1][newrem];
                int skip=dp[i+1][rem];
                dp[i][rem]=max(take,skip);
            }
        }

        return dp[0][0];
    }
};