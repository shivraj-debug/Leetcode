class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int idx=2; //keep two element always
        
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[idx-2]){
                nums[idx]=nums[i];
                idx++;
            }
        }

        return idx;
    }
};