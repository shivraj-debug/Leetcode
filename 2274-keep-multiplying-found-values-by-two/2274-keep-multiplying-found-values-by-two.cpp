class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        while(mp.find(original)!=mp.end()){
            original=2*original;
        }

        return original;
    }
};