class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int countSquares(vector<vector<int>>& matrix) {
        int res=0;
        n=matrix.size();
        m=matrix[0].size();

        dp.resize(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
            res+=matrix[i][0];
        }

        for(int i=1;i<m;i++){
            dp[0][i]=matrix[0][i];
            res+=matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                } else {
                    dp[i][j] = 0;
                }
                res += dp[i][j];
            }
        }

        return res;
    }
};