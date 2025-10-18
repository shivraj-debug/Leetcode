class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int ans=0;
        int prev=-1e9;

        for(auto num:nums){
            int x=max(num-k,prev+1);
            if(x<=num+k){
                ans++;
                prev=x;
            }
        }

        return ans;

    }
};