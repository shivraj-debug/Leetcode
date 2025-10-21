class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=accumulate(weights.begin(),weights.end(),0);
        int f=*max_element(weights.begin(),weights.end());

        int ans=l;

        while(l>=f){
            int m=f+(l-f)/2;

            if(canshipped(m,weights,days)){
                ans=m;
                l=m-1;
            }else{
                f=m+1;
            }
        }

        return ans;
    }

     bool canshipped(int m,vector<int>& nums,int days){
        int sum=0;
        int day=1;

        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=m){
                sum+=nums[i];
            }else{
                day++;
                sum=nums[i];
            }
        }

        return day<=days;
    }
};