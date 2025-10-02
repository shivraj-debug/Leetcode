class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});

        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> vis(n,vector<int>(m,false));

        // vis[0][0]=true;

        while(!q.empty()){
            int size=q.size();
            int time=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;

            q.pop();
            if(vis[x][y]) continue;
            vis[x][y]=true;
            

           if (x == n-1 && y == m-1) return time;

            for(int i=0;i<4;i++){
                int new_x=x+dir[i][0];
                int new_y=y+dir[i][1];

                if(new_x<n && new_x>=0 && new_y<m && new_y>=0 && !vis[new_x][new_y]){
                    q.push({max(time, grid[new_x][new_y]), {new_x, new_y}});
                }
            }
        }

        return -1;
    }
};