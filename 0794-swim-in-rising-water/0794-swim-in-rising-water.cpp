class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        int ans=0;

        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){
            int t=q.top().first;
            int r=q.top().second.first;
            int c=q.top().second.second;

            q.pop();

            ans=max(t,ans);
            vis[r][c]=true;

            if(r==n-1 && c==m-1) return ans;

            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];

                if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc]){
                    q.push({grid[nr][nc],{nr,nc}});
                }
            }
        }

        return ans;
    }
};