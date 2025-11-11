class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> cnt;

        int size=strs.size();
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(size+1,-1)));

        for(auto& it:strs){
            int zero=0;
            int one=0;
            for(int i=0;i<it.size();i++){
                if(it[i]=='1') one++;
                else zero++;
            }
            cnt.push_back({zero,one});
        }

        return solve(cnt,strs,m,n,0);
    }

    int solve(vector<pair<int,int>>& cnt,vector<string>& strs,int m,int n,int idx){
        if((m==0 && n==0) || idx>=strs.size()) return 0;

        if(dp[m][n][idx]!=-1) return dp[m][n][idx];

        int take=INT_MIN;
        if(cnt[idx].first<=m && cnt[idx].second<=n){
            take=1+solve(cnt,strs,m-cnt[idx].first,n-cnt[idx].second,idx+1);
        }

        int skip=solve(cnt,strs,m,n,idx+1);

        return dp[m][n][idx]= max(skip,take);
    }
};