class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt=0;
        
        sort(nums.begin(),nums.end());

        for(int i=nums.size()-1;i>=2;i--){
            int j=i-1;
            int k=0;

            while(k<j){
                if(nums[j]+nums[k]>nums[i]){
                    cnt+=(j-k);
                    j--;
                }else{
                    k++;
                }
            }
        }
        return cnt;
    }
};