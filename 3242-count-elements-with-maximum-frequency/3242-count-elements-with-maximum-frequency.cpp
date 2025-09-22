class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int cnt_max=0;

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            cnt_max=max(cnt_max,mp[nums[i]]);
        }

        int ans=0;

        for(auto& it:mp){
            if(cnt_max==it.second){
                ans+=cnt_max;
            }
        }

        return ans;
    }
};