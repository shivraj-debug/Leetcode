class Solution {
public:
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // DFS from Pacific edges
        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);        // left column
            dfs(i, m - 1, heights, atlantic);   // right column
        }
        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);        // top row
            dfs(n - 1, j, heights, atlantic);   // bottom row
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& ocean) {
        ocean[i][j] = true;
        static int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto& d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

            // only flow to higher or equal height (reverse thinking)
            if (!ocean[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(ni, nj, heights, ocean);
            }
        }
    }
};
