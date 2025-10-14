class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || K == 0) return 0;

        // dp[k][i][buy]
        // k = number of transactions remaining (1..K)
        // i = day (0..n)
        // buy = 0 (we have stock to sell), 1 (we can buy)
        vector<vector<vector<int>>> dp(K + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));

        // Base case: dp[*][n][*] = 0 already (when day > n, profit = 0)

        // Fill table from back to front (i = n-1 downto 0)
        for (int k = 1; k <= K; k++) {  // At least 1 transaction needed
            for (int i = n - 1; i >= 0; i--) {
                // If we can buy
                dp[k][i][1] = max(
                    dp[k][i + 1][1],              // skip buying
                    dp[k][i + 1][0] - prices[i]   // buy today
                );

                // If we are holding stock (need to sell)
                dp[k][i][0] = max(
                    dp[k][i + 1][0],               // skip selling
                    dp[k - 1][i + 1][1] + prices[i] // sell today → use one transaction
                );
            }
        }

        return dp[K][0][1]; // Start at day 0 with k=K and allowed to buy
    }
};
