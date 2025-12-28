class Solution {
public:

    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    int n,m;

    int bfs(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        m=grid.size();
        n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        int res=-1;

        while(!q.empty()){
            int size=q.size();
            // bool cnt=true;
            res++;

            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int i=row+dir[k][0];
                    int j=col+dir[k][1];

                    if(i>=0 && i<m && j<n && j>=0 && grid[i][j]==1){
                            grid[i][j]=2;
                            // if(cnt==true){
                            //     res++;
                            //     cnt=false;
                            // }
                        q.push({i,j});
                    }
                }
            }
        }

        return res;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int res=bfs(grid);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        if(res==-1) return 0;

        return res;
    }
};