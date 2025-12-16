class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 0;
        int n = prices.size();
        vector<int>dp(n,1);
        res = dp[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i] + 1 == prices[i-1])
            dp[i] += dp[i-1];
            res += dp[i];
        }
        return res;
    }
};