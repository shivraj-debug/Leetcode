class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int countSquares(vector<vector<int>>& matrix) {
        int res=0;
        n=matrix.size();
        m=matrix[0].size();

        dp.resize(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res+=rec(i,j,matrix);
            }
        }

        return res;
    }

    int rec(int i,int j,const vector<vector<int>>& mat){
        if(i==n-1 || j==m-1) return mat[i][j];
       
        if(mat[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right=0,dia=0,bottom=0;

        right=rec(i,j+1,mat);
        dia=rec(i+1,j+1,mat);
        bottom=rec(i+1,j,mat);

        return dp[i][j]=mat[i][j]+min({right,dia,bottom});
    }
};