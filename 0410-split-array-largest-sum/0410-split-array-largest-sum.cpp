class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
           int n=nums.size();

           int f=*max_element(nums.begin(),nums.end());
           int l=accumulate(nums.begin(),nums.end(),0);

           int ans=l;

           while(l>=f){
                int m=f+(l-f)/2;

                if(cansplit(m,k,nums)){
                    ans=m;
                    l=m-1;
                }else{
                    f=m+1;
                }
           }

           return ans;
    }

    bool cansplit(int m,int k,vector<int>& nums){
        int subarray=1;
        int sum=0;

        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>m){
                subarray++;
                sum=nums[i];
            }else{
              
                sum+=nums[i];
            }
        }

        return subarray<=k;
    }
};