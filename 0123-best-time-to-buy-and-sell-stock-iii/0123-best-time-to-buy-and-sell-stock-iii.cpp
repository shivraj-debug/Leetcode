class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[i][buy][k]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = n-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int k = 0; k < 2; k++) { // max 2 transactions
                    if(buy == 0) {
                        dp[i][buy][k] = max(
                            dp[i+1][0][k],             // skip
                            -prices[i] + dp[i+1][1][k] // buy
                        );
                    } else {
                        dp[i][buy][k] = max(
                            dp[i+1][1][k],             // skip
                            prices[i] + dp[i+1][0][k+1] // sell
                        );
                    }
                }
            }
        }

        return dp[0][0][0]; // start: day 0, can buy, 0 transactions done
    }
};
