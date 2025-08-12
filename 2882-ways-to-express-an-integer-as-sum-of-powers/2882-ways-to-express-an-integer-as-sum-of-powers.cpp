class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int numberOfWays(int n, int x) {
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return dfs(n, x, 1);
    }

    int dfs(int n, int x, int num) {
        if (n == 0) return 1; // found a valid combination
        if (n < 0 || pow(num, x) > n) return 0; // no possible way

        if (dp[n][num] != -1) return dp[n][num];

        long long take = dfs(n - (int)pow(num, x), x, num + 1); // include num
        long long skip = dfs(n, x, num + 1);                    // skip num

        return dp[n][num] = (take + skip) % MOD;
    }
};
