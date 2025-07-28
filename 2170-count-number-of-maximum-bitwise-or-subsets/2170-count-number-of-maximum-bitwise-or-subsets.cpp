class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or=0;

        for(int i=0;i<nums.size();i++){
            max_or|=nums[i];
        }

        return rec(nums,max_or,0,0);
    }

    int rec(const vector<int>& nums,int max_or,int idx,int current_or){
        if(idx==nums.size()){
            return max_or==current_or?1:0;
        }

        if(current_or==max_or){
            return 1 << (nums.size()-idx);
        }

        return rec(nums,max_or,idx+1,current_or | nums[idx])+rec(nums,max_or,idx+1,current_or);
    }
};