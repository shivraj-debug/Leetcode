class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt=0;
        bool isfirst=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 ){
                if(cnt<k && !isfirst){
                    return false;
                }
                cnt=0;
                isfirst=false;
            }else{
                cnt++;
            }
        }

        return true;
    }
};