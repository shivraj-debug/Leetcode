class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int upperrow=-1;
        int lowerrow=-1;
        int leftcol=-1;
        int rightcol=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    upperrow=i;
                    break;
                }
            }

            if(upperrow!=-1) break;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(grid[i][j]==1){
                    lowerrow=i;
                    break;
                }
            }

            if(lowerrow!=-1) break;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    leftcol=i;
                    break;
                }
            }

            if(leftcol!=-1) break;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(grid[j][i]==1){
                    rightcol=i;
                    break;
                }
            }

            if(rightcol!=-1) break;
        }

        return (rightcol-leftcol+1)*(lowerrow-upperrow+1);

    }
};