class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int target=-1;

        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                target=i-1;
                break;
            }
        }

        if(target!=-1){
            int just_greater=-1;
            for(int i=n-1;i>=target+1;i--){
                if(nums[i]>nums[target]){
                    just_greater=i;
                    break;
                }
            }

            swap(nums[just_greater],nums[target]);
        }

        return reverse(nums.begin()+target+1,nums.end());


    }
};