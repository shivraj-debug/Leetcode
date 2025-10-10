class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> dp(energy.size(),0);

        int ans=INT_MIN;

        for(int i=energy.size()-1;i>=0;i--){
            dp[i]=energy[i]+(i+k<energy.size()?dp[i+k]:0);
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};