class Solution {
public:
vector<vector<int>> dp;
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return solve(prices,0,true,fee);
    }

    int solve(vector<int>& prices,int i,bool buy,int fee){
        if(i>=prices.size()){
            return 0;
        }

        if(dp[i][buy]!=-1) return dp[i][buy];

        int take,notTake;
        if(buy){
            take=solve(prices,i+1,!buy,fee)-prices[i];
            notTake=solve(prices,i+1,buy,fee);
        }else{
            take=solve(prices,i+1,!buy,fee)+prices[i]-fee;
            notTake=solve(prices,i+1,buy,fee);
        }

        return dp[i][buy]=max(take,notTake);
    }
};