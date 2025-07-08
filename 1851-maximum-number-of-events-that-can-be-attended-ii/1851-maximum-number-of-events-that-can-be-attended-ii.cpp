class Solution {
public:

    vector<vector<int>> dp;
    int n;

    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));

        sort(events.begin(),events.end());

        return solve(0,k,events);
    }

    int solve(int i,int k,const vector<vector<int>>& events){
        if(i>=n || k==0) return 0;

        int start=events[i][0];
        int end=events[i][1];
        int value=events[i][2];

        if(dp[i][k]!=-1){
            return dp[i][k];
        }

        int skip=solve(i+1,k,events);

        int j=i+1;

        for(;j<n;j++){
            if(events[j][0]>events[i][1]){
                break;
            }
        }

        int take=value+solve(j,k-1,events);

        return dp[i][k]=max(take,skip);
    }
};