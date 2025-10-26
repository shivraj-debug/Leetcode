class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto& it:nums){
            mp[it]++;
        }

        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for(auto& it:mp){
            pq.push({it.second,it.first});
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();

            if(ans.size()==k) return ans;
        }

        return {};
    }
};