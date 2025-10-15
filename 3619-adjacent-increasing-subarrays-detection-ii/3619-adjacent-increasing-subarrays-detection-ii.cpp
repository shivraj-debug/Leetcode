class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();

        vector<int> end(n,1);// it store no of inc subarray till at inde x i;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) end[i]=end[i-1]+1;
        }

        vector<int> start(n,1); // it store no of inc subarray till at inde x i from end;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) start[i]=start[i+1]+1;
        }

        int ans=0;

        for(int k=0;k<n-1;k++){
            ans=max(ans,min(end[k],start[k+1]));
        }

        return ans;
    }
};