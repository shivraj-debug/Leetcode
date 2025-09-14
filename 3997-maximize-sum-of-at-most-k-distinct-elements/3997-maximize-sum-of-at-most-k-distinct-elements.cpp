class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=nums.size()-1;i>=0;i--){
            if(mp.find(nums[i])==mp.end()){
                ans.push_back(nums[i]);
                mp[nums[i]]++;
            }

            if(ans.size()==k) break;
        }

        return ans;
    }
};