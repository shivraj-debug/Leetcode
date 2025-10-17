class Solution {
public:
    int cnt=0;
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.assign(coins.size(),vector<int>(amount,-1));
        return solve(amount,0,0,coins);
    }

    int solve(int amount,int i,int sum,vector<int>& coins){
        if(i>=coins.size() || sum>amount) return 0;

        if(sum==amount) {
            return 1;
        }

        if(dp[i][sum]!=-1) return dp[i][sum];

        int res=0;
        
        for(int j=i;j<coins.size();j++){
            res=res+solve(amount,j,sum+coins[j],coins);
        }

        return dp[i][sum]=res;
    }

};