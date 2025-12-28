class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        int currmax=nums[0];
        int currmin=nums[0];

        for(int i=1;i<nums.size();i++){
            int temp=max({nums[i],nums[i]*currmax,nums[i]*currmin});

            currmin=min({nums[i],nums[i]*currmax,nums[i]*currmin});

            currmax=temp;
            maxi=max(maxi,currmax);
        }

        return maxi;
    }
};