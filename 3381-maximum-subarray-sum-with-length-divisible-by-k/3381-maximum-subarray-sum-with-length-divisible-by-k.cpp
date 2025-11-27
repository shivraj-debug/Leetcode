class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size(),0);

        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        int n=nums.size();
        long long maxsum=LLONG_MIN;

        for(int start=0;start<k;start++){
            int i=start;
            long long currsum=0;
            while(i<n && i+k-1<n){
                int j=i+k-1;

                long long sum=prefix[j]-((i-1>=0)?prefix[i-1]:0);
                currsum=max(sum,currsum+sum);
                maxsum=max(maxsum,currsum);

                i+=k;
            }
        }

        return maxsum;
    }
};