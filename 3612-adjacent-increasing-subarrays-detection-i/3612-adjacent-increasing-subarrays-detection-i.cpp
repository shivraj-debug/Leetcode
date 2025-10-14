class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        for(int i=k-1;i<nums.size();i++){
            int cnt1=1;
            int idx1=i;
            while(idx1>0){
                if(cnt1==k){
                    break;
                }
                if(idx1-1>=0 && nums[idx1]>nums[idx1-1]) cnt1++;
                else{
                    break;
                }

                idx1--;
            }

            int cnt2=1;
            int idx2=i+1;
            while(idx2<nums.size()){

                if(cnt2==k){
                    break;
                }
                if(idx2+1<nums.size() && nums[idx2]<nums[idx2+1]) cnt2++;
                else{
                    break;
                }


                idx2++;
            }


            if(cnt1==k && cnt2==k) return true;
        }

        return false;
    }
};