class Solution {
public:

    int dp1f(vector<vector<int>>& fruits, vector<vector<int>>& dp, int i, int j) {
        int n = fruits.size();
        if(i < 0 || j < 0 || i >= n || j >= n) return -1e5;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n-1 && j == n-1) return 0;
        if(i == n-1 && j != n-1) return -1e5;
        int findmax = max(dp1f(fruits, dp, i+1, j-1), max(dp1f(fruits, dp, i+1, j), dp1f(fruits, dp, i+1, j+1)));

        return dp[i][j] = (findmax + fruits[i][j]);
    }

    int dp2f(vector<vector<int>>& fruits, vector<vector<int>>& dp, int i, int j) {
        int n = fruits.size();
        if(i < 0 || j < 0 || i >= n || j >= n) return -1e5;

        if(dp[i][j] != -1) return dp[i][j];
        if(j == n-1 && i == n-1) return 0;
        if(j == n-1 && i != n-1) return -1e5;
        int findmax = max(dp2f(fruits, dp, i-1, j+1), max(dp2f(fruits, dp, i, j+1), dp2f(fruits, dp, i+1, j+1)));

        return dp[i][j] = (findmax + fruits[i][j]);
    }

    
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int ans = 0;
        int n = fruits.size();
        for(int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }

        vector<vector<int>> dp1(n, vector<int>(n, -1)), dp2(n, vector<int>(n, -1));

        ans += dp1f(fruits, dp1, 0, n-1);
        ans += dp2f(fruits, dp2, n-1, 0);

        return ans;
    }
};