class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        dp.resize(n,vector<int>(n,INT_MAX));
       return  solve(0,0,triangle);
    }

    int solve(int row,int col,vector<vector<int>>& triangle){
       if(row==n-1) return triangle[row][col];

       if(dp[row][col]!=INT_MAX){
        return dp[row][col];
       }

        int down=solve(row+1,col,triangle);
        int dia=solve(row+1,col+1,triangle);

        return dp[row][col] = triangle[row][col]+min(down,dia);

    }
};
