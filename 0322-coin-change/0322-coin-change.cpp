class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();

        if(amount==0) return 0;

        dp.assign(n+1,vector<int>(amount+1,-1));
        int res=solve(n-1,coins,amount);

        return (dp[n-1][amount]==1e9)?-1:dp[n-1][amount];
    }

    int solve(int i,vector<int>& coins,int amount){
        if(i<0) return 0;

        if(amount==0) return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int res=1e9;
        for(int j=i;j>=0;j--){
            if(amount-coins[j]>=0) res=min(res,1+solve(j,coins,amount-coins[j]));
        }
        
        return dp[i][amount]=res;
    }
};