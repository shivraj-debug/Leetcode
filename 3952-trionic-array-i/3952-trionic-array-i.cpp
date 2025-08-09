class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=-1,q=-1;

        int i=0,j=nums.size()-1;

        while(i<j){
            // 0 to p inc
            while( i<j && nums[i]<nums[i+1]){
                i++;
                p=i;
            }

            while( i<j && nums[i]>nums[i+1]){
                i++;
                q=i;
            }

            if(i==j) return false;

            while(i<j && nums[i]<nums[i+1]){
                i++;
            }

             if(p==-1 || q==-1 || i!=j) return false;

        }

        if(p<q){
            return true;
        }

        return i==j;
    }
};