class Solution {
public:
    vector<vector<int>> dp;
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());

        dp.resize(cuts.size()+2,vector<int>(cuts.size()+2,-1));

        return solve(1,cuts.size()-2,cuts);
    }

    int solve(int left,int right,vector<int>& cuts){
        if(left>right) return 0;

        if(dp[left][right]!=-1) return dp[left][right];

        int mini=INT_MAX;

        for(int i=left;i<=right;i++){
            int cut=cuts[right+1]-cuts[left-1] + solve(left,i-1,cuts)+solve(i+1,right,cuts);

            mini=min(mini,cut);
        }
        return dp[left][right]=mini;
    }
};