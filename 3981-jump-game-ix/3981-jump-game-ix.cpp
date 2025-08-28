class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();

        vector<int> premax(n,0);
        
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            premax[i]=maxi;
        }
        
        vector<int> premini(n,0);
        int mini=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            premini[i]=mini;
        }

        vector<int> ans(n,0);
        ans[n-1]=premax[n-1];

        for(int i=n-2;i>=0;i--){
            if(premax[i]>premini[i+1]){
                ans[i]=ans[i+1];
            }else{
                ans[i]=premax[i];
            }
        }

        return ans;
    }
};