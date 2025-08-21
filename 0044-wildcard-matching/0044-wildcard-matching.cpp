class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return rec(s,p,0,0);
    }

    bool rec(string& s,string& p,int i,int j){
        if(i==n && j==m) return true;
        if(j==m) return false;

        if(dp[i][j]!=-1) return dp[i][j];

        if( i<n && (s[i]==p[j] || p[j]=='?')){
            return dp[i][j] = rec(s,p,i+1,j+1);
        }else if(p[j]=='*'){
            return dp[i][j]=(i<n && rec(s,p,i+1,j)) || rec(s,p,i,j+1);
        }

        return false;
         
    }
};