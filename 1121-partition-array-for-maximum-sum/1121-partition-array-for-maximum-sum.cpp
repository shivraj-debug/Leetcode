class Solution {
public:
    int n;
    vector<int> dp;
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        dp.resize(n+1,0);

        for(int i=n-1;i>=0;i--){
            int len=0;
            int maxi=0;
            int maxsum=0;
            for(int j=i;j<min(i+k,n);j++){
                len++;
                maxi=max(maxi,arr[j]);
                maxsum=max(maxsum,len*maxi+dp[j+1]);
            }

            dp[i]=maxsum;
        }
        return dp[0];
    }   
};