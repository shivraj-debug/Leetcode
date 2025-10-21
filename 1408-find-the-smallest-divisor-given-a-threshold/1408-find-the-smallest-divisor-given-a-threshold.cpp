class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int f=1;
        int l=*max_element(nums.begin(),nums.end());

        int ans=l;

        while(l>=f){
            int m=f+(l-f)/2;

            if(candivide(m,nums,threshold)){
                ans=m;
                l=m-1;
            }else{
                f=m+1;
            }
        }

        return ans;
    }

    bool candivide(int m,vector<int>& nums,int thres){
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+m-1)/m;
        }

        return sum<=thres;
    }
};