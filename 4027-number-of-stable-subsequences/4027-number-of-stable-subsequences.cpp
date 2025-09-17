class Solution {
public:

    int countStableSubsequences(vector<int>& nums) {
        long long odd1=0;
        long long odd2=0;
        long long even1=0;
        long long even2=0;

        long long mod=1e9+7;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even2+=even1;
                even1+=odd1+odd2+1;

                even2=even2%mod;
                even1=even1%mod;
                
            }else{
                odd2+=odd1;
                odd1+=even1+even2+1;

                odd2=odd2%mod;
                odd1=odd1%mod;
            }
        }

        long long total=(odd1+odd2+even1+even2)%mod;

        return (int)total;
    }
};