class Solution {
public:
    int dp[100001][2][3]; // n x buy(0/1) x k(0..2)

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return rec(0, prices, 0, 0);
    }

    int rec(int i, vector<int>& prices, int buy, int k) {
        if(i >= prices.size() || k == 2) return 0;

        if(dp[i][buy][k] != -1) return dp[i][buy][k];

        int a = rec(i+1, prices, buy, k); // skip
        int b;

        if(buy == 0) { // can buy
            b = rec(i+1, prices, 1, k) - prices[i];
        } else { // can sell
            b = rec(i+1, prices, 0, k+1) + prices[i];
        }

        return dp[i][buy][k] = max(a, b);
    }
};
