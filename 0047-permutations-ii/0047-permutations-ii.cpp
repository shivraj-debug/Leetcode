class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        solve(nums,0);

        return ans;
    }

    void solve(vector<int>& nums,int idx){
        if(idx==n){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for(int i=idx;i<n;i++){
            if(st.find(nums[i])!=st.end()) continue;

            st.insert(nums[i]);
            swap(nums[i],nums[idx]);

            solve(nums,idx+1);

            swap(nums[i],nums[idx]);
            
        }
    }
};