class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<int> temp;
        solve(0,temp,st,target,0,candidates);
        return vector<vector<int>>(st.begin(),st.end());

    }

    void solve(int i,vector<int>& temp,set<vector<int>>& st,int target,int sum,vector<int>& candidates){
        if(i>=candidates.size() || sum>target){
            return;
        }

        if(sum==target){
            st.insert(temp);
            return;
        }

        for(int j=i;j<candidates.size();j++){
            temp.push_back(candidates[j]);
            solve(j,temp,st,target,sum+candidates[j],candidates);
            temp.pop_back();
        }
        return;
    }
};