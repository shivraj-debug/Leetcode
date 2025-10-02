class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});

        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> vis(n,vector<int>(m,false));

        int curr=0;

        while(!q.empty()){
            auto [mini_time, cell] = q.top();
            q.pop();
            int x = cell.first, y = cell.second;

            if (vis[x][y]) continue; 
            vis[x][y] = true;

            // update time as the max elevation so far
            curr = max(curr, mini_time);

            // if reached bottom-right return
            if (x == n-1 && y == m-1) return curr;

            // explore neighbors
            for (auto &d : dir) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    q.push({grid[nx][ny], {nx, ny}});
                }
            }
        }
        return curr;
    }
};