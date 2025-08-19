class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n=nums.size();

        vector<int> diff(n,0);

        for(auto& it:requests){
            diff[it[0]]++;
            if(it[1]+1<n) diff[it[1]+1]--;
        }

        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        sort(diff.begin(),diff.end());
        sort(nums.begin(),nums.end());

        long long ans=0;
        int mod=1e9+7;

        for(int i=0;i<n;i++){
            ans=(ans+1LL*diff[i]*nums[i])%mod;
        }

        return (int)ans;
       
    }
};