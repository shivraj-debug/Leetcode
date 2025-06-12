class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();

        for(int i=0;i<=n;i++){
            maxi=max(abs(nums[i%n]-nums[(i+1)%n]),maxi);
        }

        return maxi;

    }
};