class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {

        int curr=0;
        int prev=0;
        long long ans=0;

        for(int i=0;i<nums.size();i++){
            curr=target[i]-nums[i];

            if((curr>0 && prev<0) || (curr<0 && prev>0)){
                ans+=abs(curr);
            }else if(abs(curr)>abs(prev)){
                ans+=abs(curr)-abs(prev);
            }
            prev=curr;
        }

        return ans;
    }
};