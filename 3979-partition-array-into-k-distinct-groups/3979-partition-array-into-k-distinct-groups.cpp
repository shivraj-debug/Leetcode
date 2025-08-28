class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();

        int partition=n/k;

        if(n%k!=0) return false;

        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int maxi=0;

        for(auto& it:mp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }

        if(maxi>partition) return false;

        return true;
    }
};