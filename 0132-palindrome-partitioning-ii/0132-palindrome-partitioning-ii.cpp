class Solution {
public:
    
    vector<int> dp;

    int minCut(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return solve(0,s)-1;   
    }

    bool palin(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }

        return 1;
    }

    int solve(int i,string& s){
        if(i>=s.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int cut=INT_MAX;
        for(int k=i;k<s.size();k++){
            if(palin(i,k,s)){
               int take=1+solve(k+1,s);
                cut=min(cut,take);
            }
        }

        return dp[i]=cut;
    }
};