class Solution {
public:
    unordered_map<string,int> mp;
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto& it:wordDict){
            mp[it]++;
        }

        dp.resize(s.size(),-1);

        return solve(s,0,wordDict);
    }

    bool solve(string& s,int i,vector<string>& wordDict){
        if(i==s.size()) return true;

        if(dp[i]!=-1) return dp[i];

        string st="";
        for(int j=i;j<s.size();j++){
            st+=s[j];
            if(mp.find(st)!=mp.end()){
                if(solve(s,j+1,wordDict)) return dp[i] = true;
            }
        }

        return dp[i]=false;
    }

};