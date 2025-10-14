class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        return solve(prices,0,true);
    }
    int solve(vector<int>& prices,int i,bool buy){
        if(i>=prices.size()){
            return 0;
        }

        if(dp[i][buy]!=-1) return dp[i][buy];

        int take,notTake;
        if(buy){
            take=solve(prices,i+1,!buy)-prices[i];
            notTake=solve(prices,i+1,buy);
        }else{
            take=solve(prices,i+2,!buy)+prices[i];
            notTake=solve(prices,i+1,buy);
        }

        return dp[i][buy]=max(take,notTake);
    }
};