class Solution {
public:
    //memoization

    // int minTotal(vector<vector<int>> arr,int row,int col,vector<vector<int>> dp){
    //     int n=arr.size();
    //     if(row==n-1){
    //         return arr[row][col];
    //     }
    //     if(dp[row][col]!=-1){
    //         return dp[row][col];
    //     }

    //     int bottom=arr[row][col]+minTotal(arr,row+1,col,dp);
    //     int diagonal=arr[row][col]+minTotal(arr,row+1,col+1,dp);

    //     dp[row][col]=min(bottom,diagonal);
    //     return dp[row][col];
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        // int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return minTotal(triangle,0,0,dp);

        //tabulation
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0;i<n;i++) dp[n-1][i]=triangle[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int bottom=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(bottom,diagonal);
            }
        }
        return dp[0][0];
    }
};