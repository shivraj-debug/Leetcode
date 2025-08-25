class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.assign(k + 1, vector<vector<int>>(n, vector<int>(2, -1)));
        return rec(k, 0, prices, 1); // 1 means we can buy
    }

    int rec(int k, int i, vector<int>& prices, int buy) {
        if (i >= n || k == 0) return 0;

        if (dp[k][i][buy] != -1) return dp[k][i][buy];

        int ans;
        if (buy) {
            int skip = rec(k, i + 1, prices, 1);
            int take = rec(k, i + 1, prices, 0) - prices[i];
            ans = max(skip, take);
        } else {
            int skip = rec(k, i + 1, prices, 0);
            int take = rec(k - 1, i + 1, prices, 1) + prices[i];
            ans = max(skip, take);
        }

        return dp[k][i][buy] = ans;
    }
};
