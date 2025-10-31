class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        unordered_map<int,int> mp;

        for(int& num:nums){
            mp[num]++;
        }

        vector<int> temp;

        solve(temp,mp);

        return ans;
    }

    void solve(vector<int>& temp,unordered_map<int,int>& mp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }

        for(auto& [num,freq]:mp){
            if(freq==0) continue;

            temp.push_back(num);
            mp[num]--;
            solve(temp,mp);

            temp.pop_back();
            mp[num]++;
            
        }
    }
};