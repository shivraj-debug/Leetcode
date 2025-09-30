class Solution {
public:
    int n;
    vector<int> dp;
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        dp.resize(n,-1);
        return solve(arr,k,0);
    }

    int solve(vector<int>& arr,int k,int idx){
        if(idx>=n) return 0;

        if(dp[idx]!=-1) return dp[idx];

        int len=0;
        int maxi=INT_MIN;
        int maxiSum=INT_MIN;

        for(int i=idx;i<min(idx+k,n);i++){
            len++;
            maxi=max(maxi,arr[i]);
            int sum=maxi*len + solve(arr,k,i+1);
            maxiSum=max(maxiSum,sum);
        }

        return dp[idx]=maxiSum;
    }
};