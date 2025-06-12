class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size()-1;
        int maxi=abs(nums[0]-nums[n]);

        for(int i=0;i<n;i++){
            maxi=max(abs(nums[i]-nums[i+1]),maxi);
        }

        return maxi;

    }
};