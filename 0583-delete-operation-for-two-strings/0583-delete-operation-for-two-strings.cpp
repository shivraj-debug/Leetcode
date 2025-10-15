class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
         n=word1.size();
         m=word2.size();
         dp.assign(n+1,vector<int>(m+1,0));
        
        for (int i = n - 1; i >= 0; i--) dp[i][m] = n - i;
        for (int j = m - 1; j >= 0; j--) dp[n][j] = m - j;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]) dp[i][j]=dp[i+1][j+1];
                else{
                    dp[i][j]=1+min(dp[i][j+1],dp[i+1][j]);
                }
            }
        }

        return dp[0][0];
    }
};