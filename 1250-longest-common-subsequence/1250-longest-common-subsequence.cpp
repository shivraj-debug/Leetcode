class Solution {
public:

    vector<vector<int>> dp;

    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size()+1,vector<int>(text2.size()+1,-1));
        return rec(text1,text2,text1.size(),text2.size());
    }

    int rec(const string& s1,const string& s2,int n,int m){
        if(n==0 || m==0) return 0;

        if(dp[n][m]!=-1) return dp[n][m];

        if(s1[n-1]==s2[m-1]){
            return dp[n][m] = 1+rec(s1,s2,n-1,m-1);
        }else{
            return dp[n][m] = max(rec(s1,s2,n-1,m),rec(s1,s2,n,m-1));
        }


    }
};