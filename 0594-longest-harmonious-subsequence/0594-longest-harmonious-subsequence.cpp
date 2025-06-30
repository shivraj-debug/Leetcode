class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

       long long maxcnt=0;

       for(int i=0;i<nums.size();i++){
        long long cnt=1;
        long long mini=nums[i];
        long long maxi;
        for(int j=i+1;j<nums.size();j++){
            if((nums[j]-nums[i])<=1){
                maxi=nums[j];
                cnt++;
            }
        }
         if((maxi-mini)==1) maxcnt=max(maxcnt,cnt);
       }

       return maxcnt;
    }
};