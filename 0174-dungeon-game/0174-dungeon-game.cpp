class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();
        dp.assign(n, vector<int>(m, -1));

        return rec(dungeon, 0, 0);
    }

    int rec(vector<vector<int>>& d, int i, int j) {
        // Out of bounds → return infinity (invalid path)
        if (i >= n || j >= m) return INT_MAX;

        // Princess cell (bottom-right)
        if (i == n - 1 && j == m - 1) {
            return max(1, 1 - d[i][j]);
        }

        // Already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Recurse to right and down
        int right = rec(d, i, j + 1);
        int down  = rec(d, i + 1, j);

        int need = min(right, down) - d[i][j];
        return dp[i][j] = max(1, need);
    }
};
