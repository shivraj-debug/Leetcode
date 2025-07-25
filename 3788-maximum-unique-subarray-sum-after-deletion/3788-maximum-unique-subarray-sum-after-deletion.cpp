class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool isnegative=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                isnegative=false;
                break;
            }
        }

        if(isnegative) return *max_element(nums.begin(),nums.end());

        int sum=0;
        int maxsum=0;

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            while(i<nums.size() && nums[i]<0) {
                i++;          
            }

            if(i==nums.size()) break;

            if(i<nums.size() && mp.find(nums[i])!=mp.end()){
                continue;
            }

            sum+=nums[i];
            mp[nums[i]]++;
            maxsum=max(sum,maxsum);

        }
        return maxsum;
    }
};